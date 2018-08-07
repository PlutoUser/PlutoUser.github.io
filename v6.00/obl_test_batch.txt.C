//TITLE Batch filter

{

    //This macro tests the batch language

    TFile *f = new TFile("ntuple.root", "RECREATE");  	//Create a file for the NTuple
    TNtuple *ntuple = new TNtuple("ntuple", 
				  "data from Pluto events", 
				  "eta_px:eta_py:eta_pz:opang"); 	
    //Create an NTuple with several variables.
    TH1F * histo1 = new TH1F ("histo1","dilepton mass with opening angle < 9deg",100,0.0,0.7); 
    TH1F * histo2 = new TH1F ("histo2","dilepton mass with opening angle < 9deg",100,0.0,0.7); 
    TH1F * histo3 = new TH1F ("histo3","pp missing mass",100,0.4,0.7); 
    histo2->Sumw2();
    //	Create a control histo.
    PReaction my_reaction("3.5","p","p", "p p eta [g dilepton [e+ e-]]","eta_dalitz"); 	
    my_reaction.Do("theta_ep = ([e+]->Theta() * 180.)/TMath::Pi()"); 
    my_reaction.Do("opang_cut = (9./180.)*TMath::Pi()");
    my_reaction.Do("theta_em = ([e-]->Theta() * 180.)/TMath::Pi()"); 

    //Just some syntaxes:
    my_reaction.Do("delme1 = ([e-] + [e-])->Pz()"); 
    my_reaction.Do("delme1 = delme1 + 1");
    

    my_reaction.Do("#filter = 1; if theta_ep<18 || theta_ep>85 || theta_em<18 || theta_em>85; #filter = 0");
    my_reaction.Do("eta_px = [eta]->Px() ; eta_py = [eta]->Py() ; eta_pz = [eta]->Pz();"); 
    my_reaction.Do("opang = [e+]->Angle([e-])"); 
    my_reaction.Output(ntuple); 	
    my_reaction.Do(histo1,"if opang > (9./180.)*TMath::Pi(); _x = ([e+] + [e-])->M()"); 
    my_reaction.Do(histo2,"if opang > opang_cut; _x = ([e+] + [e-])->M()"); 
    
    my_reaction.Do(histo3,"_x = ([p+p] - ([p,1] + [p,2]))->M()"); 

    my_reaction.Print();

    my_reaction.Loop(100000);

    
    
    

    
    

}
