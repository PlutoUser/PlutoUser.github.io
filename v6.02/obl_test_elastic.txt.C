//TITLE pp elastic

{

    //makeDistributionManager()->Disable("pp_elastic");
    
    Int_t nev = 10000;
    
    
    
    
    PReaction ela1("0.050", "p", "p", "p p");
    ela1.Print();
    TH1F *theta1 = 
	new TH1F ("theta1", "Polar angle at 50 MeV", 100, -1, 1);
    ela1.Do(theta1, "p1 = [p,1]; p1->Boost([p + p]); _x = p1->CosTheta()");
    ela1.Loop(nev);
    
    
    
    PReaction ela2("1.25", "p", "p", "p p");
    ela2.Print();
    TH1F *theta2 = 
	new TH1F ("theta2", "Polar angle at 1.25 GeV", 100, -1, 1);
    ela2.Do(theta2,"p1 = [p,1]; p1->Boost([p + p]); _x = p1->CosTheta()");
    ela2.Loop(nev);
    
    
    
    PReaction ela3("2.2", "p", "p", "p p");
    ela3.Print();
    TH1F *theta3 = 
	new TH1F ("theta3", "Polar angle at 2.2 GeV", 100, -1, 1);
    ela3.Do(theta3, "p1 = [p,1]; p1->Boost([p + p]); _x = p1->CosTheta()");
    ela3.Loop(nev);
    
    
    
    PReaction ela4("0.050", "p", "d", "p p (n)");
    ela4.Print();
    TH1F *theta4 = 
	new TH1F ("theta4", "Polar angle at 50 MeV (quasi-free d)", 100, -1, 1);
    TH1F *phi4 = 
	new TH1F ("phi4", "Azimuthal angle at 50 MeV (quasi-free d)", 100, -180., 180.);
    ela4.Do(theta4, "p1 = [p,1]; p1->Boost([p + p]); _x = p1->CosTheta()");
    ela4.Do(phi4, "_x = [p,1]->Phi()* 180. /TMath::Pi()");
    ela4.Do(theta4, "_x = 1.");
    ela4.Loop(nev);
    
    
    
    
    
}
