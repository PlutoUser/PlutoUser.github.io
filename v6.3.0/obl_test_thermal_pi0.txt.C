//TITLE Thermal pi0s
//This macro tests the thermal pi0 (in the so-called "multi-mode") 

{
    
    Float_t T1    = 0.080;   // temperature in GeV (for pion 2-component spectra)
    Float_t T2    = 0.080;   // temperature in GeV (assume this for thermalized source)
    Float_t frac  = 1.0;     // fraction of pion low-T component (from Jehad's fit to QMD)
    Float_t blast = 0.0;     // radial expansion velocity

    Float_t A2    = 1.0;     // polar distribution (from KaoS pion data)
    Float_t A4    = 0.0;
    Float_t v1    = 0.0;     // side flow
    Float_t v2    = 0.0;     // elliptic flow
    Float_t Eb    = 3.5;     // beam energy in AGeV

    PFireball *source1 = new PFireball("pi0", Eb, T1, T2, frac, blast, A2, A4, v1, v2);

    Float_t Mpi0   = 1.;      // pi0 multiplicity... just a test

    Float_t enhancepi = 3.;            //enhancement factor for pi
    
    Mpi0 *= enhancepi;

    source1->SetW(1.0/enhancepi);

    PChannel *c1 = source1->makeChannel(20, Mpi0);          // pi0 decay directly
    source1->Print();

    PReaction *r = new PReaction(&c1, "pA", 1);

    r->allParticles();        //Must be used, otherwise the PProjector does not consider all particles
    PPlutoBulkDecay *pl = new PPlutoBulkDecay();
    pl->SetRecursiveMode(1);  //Let also the products decay
    pl->SetTauMax(0.001);     //maxTau in ns
    r->AddBulk(pl);

    //Test histos
    TH1F *histo1 = new TH1F ("histo1", "pi0 mult", 21, -0.5, 20.5);

    r->Do("counter = 0;"); 
    r->Do("foreach(pi0); counter = counter +1");
    r->Do(histo1, "_x = counter");

    TH2F *histo2 = new TH2F ("histo2", "Rap. vs. Pt", 50, -1.5, 3.5, 50, 0, 1);
    r->Do(histo2, "foreach(pi0); _x = [pi0]->Rapidity(); _y=[pi0]->Pt(); ");

    TH1F *histo3 = new TH1F ("histo3", "ee invariant mass", 100, 0, 0.5);
    r->Do(histo3, "foreach(dilepton); _x = [dilepton]->M(); ");

    
    r->Print();
    r->loop(20000);

    TCanvas *obl_test_thermal_pi0_c1 = new 
	TCanvas ("obl_test_thermal_pi0_c1", "Multiplicity");

    TCanvas *obl_test_thermal_pi0_c2 = new 
	TCanvas ("obl_test_thermal_pi0_c2", "Rap. vs. Pt");

}
