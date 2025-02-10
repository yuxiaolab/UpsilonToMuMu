// Achim asked to draw some comparing plots of data & mc in Run3
// That's what this programme does..

#include <TChain.h>
#include <TTree.h>
#include <TH1D.h>
#include <TH2D.h>
#include <TF1.h>
#include <TFile.h>
#include <TCanvas.h>
#include <TLorentzVector.h>
#include <TROOT.h>
#include <TStyle.h>
#include <TLegend.h>
#include <TNtuple.h>

#include <iostream>
using namespace std;

void sideband() {

	gStyle->SetOptStat(0);

	TH1::SetDefaultSumw2();
	TH2::SetDefaultSumw2();

	TChain* data = new TChain("mm_tree");
	TChain* mc = new TChain("mm_tree");
	data->Add("afterTrigger/outputC.root");
	data->Add("afterTrigger/outputD1.root");
	data->Add("afterTrigger/outputD2.root");
	data->Add("afterTrigger/outputE.root");
	data->Add("afterTrigger/outputF.root");
	data->Add("afterTrigger/outputG.root");
	mc->Add("mc_samecuts.root");
	//data->Add("/home/storage0/users/yuxiao/work2/upsilon/ntuple/mcEE_tgr.root");
	//mc->Add("/home/storage0/users/yuxiao/work2/upsilon/ntuple/mcnoEE_tgr.root");

	Double_t dimuon_m_d, dimuon_pt_d, dimuon_y_d;
	UInt_t numPrimaryVertices_d;
	TLorentzVector *muonP_p4_d, *muonM_p4_d;
        Float_t vProb_d;
	muonP_p4_d = 0;
	muonM_p4_d = 0;
	UInt_t nonia_d;	
	
	data->SetBranchAddress("dimuon_m",&dimuon_m_d);
	data->SetBranchAddress("dimuon_pt",&dimuon_pt_d);
	data->SetBranchAddress("dimuon_y",&dimuon_y_d);
	data->SetBranchAddress("muonP_p4",&muonP_p4_d);
	data->SetBranchAddress("muonM_p4",&muonM_p4_d);
	data->SetBranchAddress("nonia",&nonia_d);
	data->SetBranchAddress("numPrimaryVertices",&numPrimaryVertices_d);
        data->SetBranchAddress("vProb",&vProb_d);

	Double_t dimuon_m_m, dimuon_pt_m, dimuon_y_m;
	UInt_t numPrimaryVertices_m;
	TLorentzVector *muonP_p4_m, *muonM_p4_m;
        Float_t vProb_m;
	muonP_p4_m = 0;
	muonM_p4_m = 0;
	UInt_t nonia_m;
	mc->SetBranchAddress("dimuon_m",&dimuon_m_m);
	mc->SetBranchAddress("dimuon_pt",&dimuon_pt_m);
	mc->SetBranchAddress("dimuon_y",&dimuon_y_m);
	mc->SetBranchAddress("muonP_p4",&muonP_p4_m);
	mc->SetBranchAddress("muonM_p4",&muonM_p4_m);
	mc->SetBranchAddress("nonia",&nonia_m);
	mc->SetBranchAddress("numPrimaryVertices",&numPrimaryVertices_m);
        mc->SetBranchAddress("vProb",&vProb_m);

        // reweighting
        Float_t weight;
        mc->SetBranchAddress("weight",&weight);

	TH1F *dim_d = new TH1F("dim_d","dimuon mass",100,9,9.8);
	TH1F *dipt_d = new TH1F("dipt_d","dimuon pt",100,0,50);
	TH1F *diy_d = new TH1F("diy_d","dimuon y",100,-1.5,1.5);
	TH1F *mpt_d = new TH1F("mpt_d","muon pt",100,0,30);
	TH1F *meta_d = new TH1F("meta_d", "muon eta",100,-2.5,2.5);
	TH1F *pu_d = new TH1F("pu_d", "pu_d",70,0,70);

	TH1F *dipt_d1 = new TH1F("dipt_d1","dimuon pt",100,0,50);
	TH1F *dipt_d2 = new TH1F("dipt_d2","dimuon pt",100,0,50);
	TH1F *dipt_d3 = new TH1F("dipt_d3","dimuon pt",100,0,50);
	TH1F *diy_d1 = new TH1F("diy_d1","dimuon y",100,-1.5,1.5);
	TH1F *diy_d2 = new TH1F("diy_d2","dimuon y",100,-1.5,1.5);
	TH1F *diy_d3 = new TH1F("diy_d3","dimuon y",100,-1.5,1.5);
	TH1F *mpt_d1 = new TH1F("mpt_d1","muon pt",100,0,30);
	TH1F *mpt_d2 = new TH1F("mpt_d2","muon pt",100,0,30);
	TH1F *mpt_d3 = new TH1F("mpt_d3","muon pt",100,0,30);
	TH1F *meta_d1 = new TH1F("meta_d1", "muon eta",100,-2.5,2.5);
	TH1F *meta_d2 = new TH1F("meta_d2", "muon eta",100,-2.5,2.5);
	TH1F *meta_d3 = new TH1F("meta_d3", "muon eta",100,-2.5,2.5);
	TH1F *pu_d1 = new TH1F("pu_d1", "pu_d1",70,0,70);
	TH1F *pu_d2 = new TH1F("pu_d2", "pu_d2",70,0,70);
	TH1F *pu_d3 = new TH1F("pu_d3", "pu_d3",70,0,70);

	TH1F *dim_m = new TH1F("dim_m","dimuon mass",100,9,9.8);
        TH1F *dipt_m = new TH1F("dipt_m","dimuon pt",100,0,50);
        TH1F *diy_m = new TH1F("diy_m","dimuon y",100,-1.5,1.5);
        TH1F *mpt_m = new TH1F("mpt_m","muon pt",100,0,30);
        TH1F *meta_m = new TH1F("meta_m", "muon eta",100,-2.5,2.5);
	TH1F *pu_m = new TH1F("pu_m", "pu_m",70,0,70);	

	for (int i=0;i<data->GetEntries();i++){
		data->GetEntry(i);
		if (0ul == (i % 1000000ul)) cout << "Read event " << i << "/" << data->GetEntries() << endl;
		if (nonia_d != 1) continue;		

                // selections
      		if(dimuon_pt_d<10) continue;
      		if(dimuon_pt_d >= 130) continue;
      		if (abs(dimuon_y_d) >= 1.2) continue;

      		if (abs(muonP_p4_d->Eta()) > 1.2 || abs(muonM_p4_d->Eta()) > 1.2) continue;
      		if (abs(muonP_p4_d->Eta()) <= 0.9 && muonP_p4_d->Pt() <= 4.6) continue;
      		if (abs(muonM_p4_d->Eta()) <= 0.9 && muonM_p4_d->Pt() <= 4.6) continue;
      		if (abs(muonP_p4_d->Eta()) > 0.9 && abs(muonP_p4_d->Eta()) <= 1.2 && muonP_p4_d->Pt() <= 3.6) continue;
      		if (abs(muonM_p4_d->Eta()) > 0.9 && abs(muonM_p4_d->Eta()) <= 1.2 && muonM_p4_d->Pt() <= 3.6) continue;

      		if(!(vProb_d>0.01)) continue;
 
		dim_d->Fill(dimuon_m_d);
		dipt_d->Fill(dimuon_pt_d);
		diy_d->Fill(dimuon_y_d);
		mpt_d->Fill(muonP_p4_d->Pt());
		mpt_d->Fill(muonM_p4_d->Pt());
		meta_d->Fill(muonP_p4_d->Eta());
		meta_d->Fill(muonM_p4_d->Eta());
		pu_d->Fill(numPrimaryVertices_d);

		if (dimuon_m_d < 9.1 && dimuon_m_d > 8.8) {
			dipt_d1->Fill(dimuon_pt_d);
			diy_d1->Fill(dimuon_y_d);
			mpt_d1->Fill(muonP_p4_d->Pt());
			mpt_d1->Fill(muonM_p4_d->Pt());
			meta_d1->Fill(muonP_p4_d->Eta());
			meta_d1->Fill(muonM_p4_d->Eta());
			pu_d1->Fill(numPrimaryVertices_d);
		}
		if (dimuon_m_d > 9.25 && dimuon_m_d < 9.65) {
			dipt_d2->Fill(dimuon_pt_d);
                        diy_d2->Fill(dimuon_y_d);
                        mpt_d2->Fill(muonP_p4_d->Pt());
                        mpt_d2->Fill(muonM_p4_d->Pt());
                        meta_d2->Fill(muonP_p4_d->Eta());
                        meta_d2->Fill(muonM_p4_d->Eta());
			pu_d2->Fill(numPrimaryVertices_d);
		}
		if (dimuon_m_d > 9.7 && dimuon_m_d< 9.8) {
			dipt_d3->Fill(dimuon_pt_d);
                        diy_d3->Fill(dimuon_y_d);
                        mpt_d3->Fill(muonP_p4_d->Pt());
                        mpt_d3->Fill(muonM_p4_d->Pt());
                        meta_d3->Fill(muonP_p4_d->Eta());
                        meta_d3->Fill(muonM_p4_d->Eta());
			pu_d3->Fill(numPrimaryVertices_d);
		}
	}	

	for (int i=0;i<mc->GetEntries();i++){
		mc->GetEntry(i);
		if (0ul == (i % 100000ul)) cout << "Read event " << i << "/" << mc->GetEntries() << endl;
		if (nonia_m != 1) continue;

                // selections
                if(dimuon_pt_m<10) continue;
                if(dimuon_pt_m >= 130) continue;
                if (abs(dimuon_y_m) >= 1.2) continue;

                if (abs(muonP_p4_m->Eta()) > 1.2 || abs(muonM_p4_m->Eta()) > 1.2) continue;
                if (abs(muonP_p4_m->Eta()) <= 0.9 && muonP_p4_m->Pt() <= 4.6) continue;
                if (abs(muonM_p4_m->Eta()) <= 0.9 && muonM_p4_m->Pt() <= 4.6) continue;
                if (abs(muonP_p4_m->Eta()) > 0.9 && abs(muonP_p4_m->Eta()) <= 1.2 && muonP_p4_m->Pt() <= 3.6) continue;
                if (abs(muonM_p4_m->Eta()) > 0.9 && abs(muonM_p4_m->Eta()) <= 1.2 && muonM_p4_m->Pt() <= 3.6) continue;

                if(!(vProb_m>0.01)) continue;

		/*
                dim_m->Fill(dimuon_m_m, weight);
                dipt_m->Fill(dimuon_pt_m, weight);
                diy_m->Fill(dimuon_y_m, weight);
                mpt_m->Fill(muonP_p4_m->Pt(), weight);
                mpt_m->Fill(muonM_p4_m->Pt(), weight);
                meta_m->Fill(muonP_p4_m->Eta(), weight);
                meta_m->Fill(muonM_p4_m->Eta(), weight);
		pu_m->Fill(numPrimaryVertices_m, weight);
                */
                dim_m->Fill(dimuon_m_m);
                dipt_m->Fill(dimuon_pt_m);
                diy_m->Fill(dimuon_y_m);
                mpt_m->Fill(muonP_p4_m->Pt());
                mpt_m->Fill(muonM_p4_m->Pt());
                meta_m->Fill(muonP_p4_m->Eta());
                meta_m->Fill(muonM_p4_m->Eta());
                pu_m->Fill(numPrimaryVertices_m);
	}

	float norm = 1000;
	float norm2 = 2000;
	float norm_m = dim_d->GetMaximum();
        float norm_dipt = dipt_m->GetMaximum();
        float norm_diy = diy_m->GetMaximum();
        float norm_mpt = mpt_m->GetMaximum();
        float norm_meta = meta_m->GetMaximum();
        float norm_pu = pu_m->GetMaximum();

	//dim_d->Scale(norm_m/dim_d->Integral());
	dipt_d->Scale(norm_dipt/dipt_d->GetMaximum());
	diy_d->Scale(norm_diy/diy_d->GetMaximum());
	mpt_d->Scale(norm_mpt/mpt_d->GetMaximum());
	meta_d->Scale(norm_meta/meta_d->GetMaximum());
	pu_d->Scale(norm_pu/pu_d->GetMaximum());
	
	dipt_d2->Add(dipt_d1, -1);
	dipt_d2->Add(dipt_d3, -1);
	dipt_d2->Scale(norm_dipt/dipt_d2->GetMaximum());

	diy_d2->Add(diy_d1, -1);
        diy_d2->Add(diy_d3, -1);
        diy_d2->Scale(norm_diy/diy_d2->GetMaximum());

	mpt_d2->Add(mpt_d1, -1);
        mpt_d2->Add(mpt_d3, -1);
        mpt_d2->Scale(norm_mpt/mpt_d2->GetMaximum());

	meta_d2->Add(meta_d1, -1);
        meta_d2->Add(meta_d3, -1);
        meta_d2->Scale(norm_meta/meta_d2->GetMaximum());

	pu_d2->Add(pu_d1, -1);
	pu_d2->Add(pu_d3, -1);
	pu_d2->Scale(norm_pu/pu_d2->GetMaximum());

	dim_m->Scale(norm_m/dim_m->GetMaximum());
        //dipt_m->Scale(norm/dipt_m->Integral());
        //diy_m->Scale(norm/diy_m->Integral());
        //mpt_m->Scale(norm2/mpt_m->Integral());
        //meta_m->Scale(norm2/meta_m->Integral());
	//pu_m->Scale(norm/pu_m->Integral());
	
	dim_m->SetLineColor(kRed);
	dipt_m->SetLineColor(kRed);
	diy_m->SetLineColor(kRed);
	mpt_m->SetLineColor(kRed);
	meta_m->SetLineColor(kRed);
	pu_m->SetLineColor(kRed);

	TCanvas*c1 = new TCanvas("c1","dimuon mass");
	TCanvas*c2 = new TCanvas("c2","dimuon pt");
	TCanvas*c21 = new TCanvas("c21","dimuon pt");
	TCanvas*c3 = new TCanvas("c3","dimuon rapidity");
	TCanvas*c31 = new TCanvas("c31","dimuon rapidity");
	TCanvas*c4 = new TCanvas("c4","muon pt");
	TCanvas*c41 = new TCanvas("c41","muon pt");
	TCanvas*c5 = new TCanvas("c5","muon eta");
	TCanvas*c51 = new TCanvas("c51","muon eta");
	TCanvas*c6 = new TCanvas("c6","pileup");
	TCanvas*c61 = new TCanvas("c61","pileup");

	c1->cd();
	dim_d->SetMinimum(0.);
	dim_m->SetMinimum(0.);
        dim_m->GetXaxis()->SetTitle("Dimuon Mass [GeV/c^{2}]");
        dim_m->GetYaxis()->SetTitle("Events");
	dim_m->Draw("HIST");
	dim_d->Draw("HISTsames");
        c1->SetTitle("Dimuon Mass Comparison");
	c1->SaveAs("comparePlots/dimuon_m_best.png");

	c2->cd();
        dipt_d->GetXaxis()->SetTitle("Dimuon Pt [GeV/c]");
        dipt_d->GetYaxis()->SetTitle("Events");
	dipt_d->Draw("HIST");
	dipt_m->Draw("HISTsames");
	c2->SetTitle("Dimuon Pt Comparison");
        c2->SaveAs("comparePlots/dimuon_pt_best.png");	

	c21->cd();
        dipt_d2->GetXaxis()->SetTitle("Dimuon Pt [GeV/c]");
        dipt_d2->GetYaxis()->SetTitle("Events");
	dipt_d2->Draw("HIST");
	dipt_m->Draw("HISTsames");
        c21->SetTitle("Dimuon Pt Comparison");
        c21->SaveAs("comparePlots/dimuon_pt_ss_best.png");    
	
	c3->cd();
        diy_d->GetXaxis()->SetTitle("Dimuon Rapidity");
        diy_d->GetYaxis()->SetTitle("Events");
	diy_d->Draw("HIST");
	diy_m->Draw("HISTsames");
	c3->SetTitle("Dimuon Rapidity Comparison");
        c3->SaveAs("comparePlots/dimuon_y_best.png");

	c31->cd();
        diy_m->GetXaxis()->SetTitle("Dimuon Rapidity");
        diy_m->GetYaxis()->SetTitle("Events");
        diy_m->Draw("HIST");
        diy_d2->Draw("HISTsames");
        c31->SetTitle("Dimuon Rapidity Comparison");
        c31->SaveAs("comparePlots/dimuon_y_ss_best.png");

	c4->cd();
        mpt_d->GetXaxis()->SetTitle("Single Muon Pt [GeV/c]");
        mpt_d->GetYaxis()->SetTitle("Events");
	mpt_d->Draw("HIST");
	mpt_m->Draw("HISTsames");
	c4->SetTitle("Single Muon Pt Comparison");
        c4->SaveAs("comparePlots/muon_pt_best.png");

	c41->cd();
        mpt_d2->GetXaxis()->SetTitle("Single Muon Pt [GeV/c]");
        mpt_d2->GetYaxis()->SetTitle("Events");
        mpt_d2->Draw("HIST");
        mpt_m->Draw("HISTsames");
        c41->SetTitle("Single Muon Pt Comparison");
        c41->SaveAs("comparePlots/muon_pt_ss_best.png");

	c5->cd();
        meta_d->GetXaxis()->SetTitle("Single Muon Eta");
        meta_d->GetYaxis()->SetTitle("Events");
	meta_d->Draw("HIST");
	meta_m->Draw("HISTsames");
	c5->SetTitle("Single Muon Eta Comparison");
        c5->SaveAs("comparePlots/muon_eta_best.png");

	c51->cd();
        meta_m->GetXaxis()->SetTitle("Single Muon Eta");
        meta_m->GetYaxis()->SetTitle("Events");
        meta_m->Draw("HIST");
        meta_d2->Draw("HISTsames");
        c51->SetTitle("Single Muon Eta Comparison");
        c51->SaveAs("comparePlots/muon_eta_ss_best.png");

	c6->cd();
        pu_d->GetXaxis()->SetTitle("number of primary vertices");
        pu_d->GetYaxis()->SetTitle("Events");
	pu_d->Draw("HIST");
	pu_m->Draw("HISTsames");
	c6->SetTitle("Pileup Comparison");
        c6->SaveAs("comparePlots/pu_best.png");

	c61->cd();
        pu_d2->GetXaxis()->SetTitle("number of primary vertices");
        pu_d2->GetYaxis()->SetTitle("Events");
	pu_d2->Draw("HIST");
	pu_m->Draw("HISTsames");
	c61->SetTitle("Pileup Comparison");
        c61->SaveAs("comparePlots/pu_ss_best.png");

	//c1->Draw();
	//c2->Draw();
	//c21->Draw();
	//c3->Draw();
	//c31->Draw();
	//c4->Draw();
	//c41->Draw();
	//c5->Draw();	
	//c51->Draw();
}
