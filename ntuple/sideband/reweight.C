// Achim asked to draw some comparing plots of data & mc in Run3
// That's what this programme does..
// this is to reweight MC by data/MC

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

void reweight() {

	gStyle->SetOptStat(0);

	TH1::SetDefaultSumw2();
	TH2::SetDefaultSumw2();

	TChain* data = new TChain("mm_tree");
	// TChain* mc = new TChain("mm_tree");
	data->Add("afterTrigger/outputC.root");
	data->Add("afterTrigger/outputD1.root");
	data->Add("afterTrigger/outputD2.root");
	data->Add("afterTrigger/outputE.root");
	data->Add("afterTrigger/outputF.root");
	data->Add("afterTrigger/outputG.root");
	TFile *f_mc = new TFile("mc_samecuts.root", "UPDATE");
        TTree *mc = (TTree *) f_mc->Get("mm_tree");
        //mc->Add("mc_samecuts.root");
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

        // for reweighting
        float weight = 1.0;
        double bin_edges[] = {3.6, 5.5, 7.5, 10.0, 14.0, 19.0, 25.0, 40.0};
        TH2D *h_data1 = new TH2D("h_data1", "Data1", 7, bin_edges, 7, bin_edges);
        TH2D *h_data2 = new TH2D("h_data2", "Data2", 7, bin_edges, 7, bin_edges);
        TH2D *h_data3 = new TH2D("h_data3", "Data3", 7, bin_edges, 7, bin_edges);
        TH2D *h_mc = new TH2D("h_mc", "MC", 7, bin_edges, 7, bin_edges);
        TBranch *b_weight = mc->Branch("weight", &weight, "weight/F");;

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
 
		//pu_d->Fill(numPrimaryVertices_d);

		if (dimuon_m_d < 9.1 && dimuon_m_d > 8.8) {
                        h_data1->Fill(muonP_p4_d->Pt(), muonM_p4_d->Pt());
		}
		if (dimuon_m_d > 9.25 && dimuon_m_d < 9.65) {
                        h_data2->Fill(muonP_p4_d->Pt(), muonM_p4_d->Pt());
		}
		if (dimuon_m_d > 9.7 && dimuon_m_d< 9.8) {
                        h_data3->Fill(muonP_p4_d->Pt(), muonM_p4_d->Pt());
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
                if (abs(muonP_p4_m->Eta()) > 0.9 && abs(muonP_p4_m->Eta()) <= 1.2 && muonP_p4_d->Pt() <= 3.6) continue;
                if (abs(muonM_p4_m->Eta()) > 0.9 && abs(muonM_p4_m->Eta()) <= 1.2 && muonM_p4_d->Pt() <= 3.6) continue;

                if(!(vProb_d>0.01)) continue;

                h_mc->Fill(muonP_p4_m->Pt(), muonM_p4_m->Pt());
	}

        h_data2->Add(h_data1, -1);
        h_data2->Add(h_data3, -1);
        double data_integral = h_data2->Integral();
        double mc_integral = h_mc->Integral();
        h_mc->Scale(data_integral / mc_integral);

        TH2D *h_weights = (TH2D *) h_data2->Clone("h_weights");
        for (int x = 1; x <= h_weights->GetNbinsX(); x++) {
            for (int y = 1; y <= h_weights->GetNbinsY(); y++) {
                double mc_content = h_mc->GetBinContent(x, y);

                if (mc_content > 0) {
                    // If MC bin is non-zero, calculate the weight
                    double data_content = h_data2->GetBinContent(x, y);
                    h_weights->SetBinContent(x, y, data_content / mc_content);
                } else {
                    // If MC bin is zero, set the weight to 1.0
                    h_weights->SetBinContent(x, y, 1.0);
                }
            }
        }
        
        for (int i=0;i<mc->GetEntries();i++) {
                mc->GetEntry(i);
                if (0ul == (i % 100000ul)) cout << "Fill event " << i << "/" << mc->GetEntries() << endl;  
                float ptP = muonP_p4_m->Pt();
                float ptM = muonM_p4_m->Pt();

                int bin_x = h_weights->GetXaxis()->FindBin(ptP);
                int bin_y = h_weights->GetYaxis()->FindBin(ptM);

                weight = h_weights->GetBinContent(bin_x, bin_y);

                if (weight <= 0) {
                        weight = 1.0; // Assign a default weight if needed
                }

                // Fill the new branch
                b_weight->Fill();
        }

        cout << "is it here?" << endl;
        mc->Write("", TObject::kOverwrite);
        //f_mc->Close();

	TCanvas*c1 = new TCanvas("c1","reweight");

	c1->cd();
        h_weights->GetXaxis()->SetTitle("Mu+ Pt [GeV/c]");
        h_weights->GetYaxis()->SetTitle("Mu- Pt [GeV/c]");
	h_weights->Draw("colz");
        c1->SetTitle("weights");
	c1->SaveAs("comparePlots/weights.png");

        f_mc->Close();
}
