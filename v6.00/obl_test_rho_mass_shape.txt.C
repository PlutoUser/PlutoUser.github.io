
{


    

    PReaction my_reaction("3.5","p","p","p p rho0");
    TH1F * histo1 = new TH1F ("histo1","dilepton mass",100,0.2,1.3);
    histo1->Sumw2();
    histo1->SetMinimum(0.000000001);
    my_reaction.Do(histo1,"_x =  ([rho0])->M()");

    my_reaction.Print();   //The "Print()" statement is optional
    my_reaction.Loop(10000);
    histo1->Draw("e1");
    
    PReaction my_reaction2("3.5","p","p","p p rho0 [e+ e-]");
    TH1F * histo2 = new TH1F ("histo2","dilepton mass",100,0.2,1.3);
    histo2->Sumw2();
    my_reaction2.Do(histo2,"_x =  ([rho0])->M()");

    my_reaction2.Print();   //The "Print()" statement is optional
    my_reaction2.Loop(10000);
    histo2->Draw("samee1");





}
