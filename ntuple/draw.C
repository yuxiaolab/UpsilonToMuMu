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
#include <bitset>

#include <iostream>
using namespace std;

void draw()
{
	gStyle->SetOptStat(0);
	//gStyle->SetPalette(1);
	const Int_t NRGBs = 5;
    const Int_t NCont = 255;

    Double_t stops[NRGBs] = { 0.00, 0.34, 0.61, 0.84, 1.00 };
    Double_t red[NRGBs]   = { 0.00, 0.00, 0.87, 1.00, 0.51 };
    Double_t green[NRGBs] = { 0.00, 0.81, 1.00, 0.20, 0.00 };
    Double_t blue[NRGBs]  = { 0.51, 1.00, 0.12, 0.00, 0.00 };
    TColor::CreateGradientColorTable(NRGBs, stops, red, green, blue, NCont);
    gStyle->SetNumberContours(NCont);
	//gStyle->SetNumberContours(1000);

	TChain* tree=new TChain("mm_tree");
    	tree->Add("afterTrigger/outputC.root");
        tree->Add("afterTrigger/outputD1.root");
        tree->Add("afterTrigger/outputD2.root");
        tree->Add("afterTrigger/outputE.root");
        tree->Add("afterTrigger/outputF.root");
        tree->Add("afterTrigger/outputG.root"); 
 
   	TLorentzVector *dimuon_p4, *muonP_p4, *muonM_p4;
	dimuon_p4 = 0;
	muonP_p4 = 0;
	muonM_p4 = 0;

	TBranch *b_dimuon_p4, *b_muonP_p4, *b_muonM_p4; 
	tree->SetBranchAddress("dimuon_p4",&dimuon_p4,&b_dimuon_p4);
    	tree->SetBranchAddress("muonP_p4",&muonP_p4,&b_muonP_p4);
	tree->SetBranchAddress("muonM_p4",&muonM_p4,&b_muonM_p4);	

   	Int_t nentries = tree->GetEntries();

   Int_t nbytes = 0, nb = 0;

   TH2F *pteta = new TH2F("pteta","muonM in dimuon10",50,-2,2,50,3,12);
   TH2F *ptr = new TH2F("ptr", "dimuon10", 50, -1.5, 1.5, 50, 0, 100);

   for (Int_t j=0; j<nentries; j++) {
      tree->GetEntry(j) ;
      if (0ul == (j % 1000000ul)) cout << "Read event " << j << "/" << nentries << endl;
      pteta->Fill(muonM_p4->Eta(), muonM_p4->Pt());
      ptr->Fill(dimuon_p4->Rapidity(), dimuon_p4->Pt());
      // if (Cut(ientry) < 0) continue;
      //       bitset<24> bit(trigger);
      //             if (!bit[1]) continue;
      //                   summary_tree->Fill();
      //                      }
      //
    }

    //pteta->SetTitle("Dimuon10_Upsilon_y1p4_v*");
    pteta->GetXaxis()->SetTitle("\\eta(\\mu)");
    pteta->GetYaxis()->SetTitle("p_T(\\mu)");

    //ptr->SetTitle("Dimuon10_Upsilon_y1p4_v*");
    ptr->GetXaxis()->SetTitle("A");
    ptr->GetXaxis()->SetTitle("y(\\mu^+\\mu^-)");
    ptr->GetYaxis()->SetTitle("p_T(\\mu^+\\mu^-)");
    //TCanvas *t;
    
    pteta->Draw("colz");
    //ptr->Draw("colz");

}
