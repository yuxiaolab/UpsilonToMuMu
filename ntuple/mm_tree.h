//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Mar  1 17:36:37 2023 by ROOT version 6.24/07
// from TTree mm_tree/Tree of dimuons
// found on file: 0D1.root
//////////////////////////////////////////////////////////

#ifndef mm_tree_h
#define mm_tree_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include "TLorentzVector.h"

class mm_tree {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   UInt_t          run;
   ULong64_t       event;
   UInt_t          lumiblock;
   UInt_t          nonia;
   UInt_t          trigger;
   Int_t           charge;
   TLorentzVector  *dimuon_p4;
   TLorentzVector  *muonP_p4;
   TLorentzVector  *muonM_p4;
   Float_t         vProb;
   Float_t         DCA;
   Float_t         ppdlPV;
   Float_t         ppdlErrPV;
   Float_t         cosAlpha;
   Float_t         ppdlBS;
   Float_t         ppdlErrBS;
   Float_t         cosAlphaBS;
   UInt_t          numPrimaryVertices;

   // List of branches
   TBranch        *b_run;   //!
   TBranch        *b_event;   //!
   TBranch        *b_lumiblock;   //!
   TBranch        *b_nonia;   //!
   TBranch        *b_trigger;   //!
   TBranch        *b_charge;   //!
   TBranch        *b_dimuon_p4;   //!
   TBranch        *b_muonP_p4;   //!
   TBranch        *b_muonM_p4;   //!
   TBranch        *b_vProb;   //!
   TBranch        *b_DCA;   //!
   TBranch        *b_ppdlPV;   //!
   TBranch        *b_ppdlErrPV;   //!
   TBranch        *b_cosAlpha;   //!
   TBranch        *b_ppdlBS;   //!
   TBranch        *b_ppdlErrBS;   //!
   TBranch        *b_cosAlphaBS;   //!
   TBranch        *b_numPrimaryVertices;   //!

   mm_tree(TTree *tree=0);
   virtual ~mm_tree();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   //virtual void     draw(); //wyx
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef mm_tree_cxx
mm_tree::mm_tree(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("original/2023/D2.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("original/2023/D2.root");
      }
      TDirectory * dir = (TDirectory*)f->Get("rootuple");
      dir->GetObject("mm_tree",tree);

   }
   Init(tree);
}

mm_tree::~mm_tree()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t mm_tree::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t mm_tree::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void mm_tree::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   dimuon_p4 = 0;
   muonP_p4 = 0;
   muonM_p4 = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("run", &run, &b_run);
   fChain->SetBranchAddress("event", &event, &b_event);
   fChain->SetBranchAddress("lumiblock", &lumiblock, &b_lumiblock);
   fChain->SetBranchAddress("nonia", &nonia, &b_nonia);
   fChain->SetBranchAddress("trigger", &trigger, &b_trigger);
   fChain->SetBranchAddress("charge", &charge, &b_charge);
   fChain->SetBranchAddress("dimuon_p4", &dimuon_p4, &b_dimuon_p4);
   fChain->SetBranchAddress("muonP_p4", &muonP_p4, &b_muonP_p4);
   fChain->SetBranchAddress("muonM_p4", &muonM_p4, &b_muonM_p4);
   fChain->SetBranchAddress("vProb", &vProb, &b_vProb);
   fChain->SetBranchAddress("DCA", &DCA, &b_DCA);
   fChain->SetBranchAddress("ppdlPV", &ppdlPV, &b_ppdlPV);
   fChain->SetBranchAddress("ppdlErrPV", &ppdlErrPV, &b_ppdlErrPV);
   fChain->SetBranchAddress("cosAlpha", &cosAlpha, &b_cosAlpha);
   fChain->SetBranchAddress("ppdlBS", &ppdlBS, &b_ppdlBS);
   fChain->SetBranchAddress("ppdlErrBS", &ppdlErrBS, &b_ppdlErrBS);
   fChain->SetBranchAddress("cosAlphaBS", &cosAlphaBS, &b_cosAlphaBS);
   fChain->SetBranchAddress("numPrimaryVertices", &numPrimaryVertices, &b_numPrimaryVertices);
   Notify();
}

Bool_t mm_tree::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void mm_tree::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t mm_tree::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef mm_tree_cxx
