//TITLE Decay Manager

{

    //This macro tests the pd fusion to He3

    makeStaticData()->SetBatchValue("_system_inactivate_decayed_particles", 1);

    PDecayChannel *c1;
    PDecayChannel *c2;
    PDecayManager *pdm = new PDecayManager;
    pdm->SetVerbose(1);
    pdm->SetDefault("pi0");
    pdm->SetDefault("dilepton");
    PParticle *p = new PParticle("p", 1.00);
    PParticle *d = new PParticle("d", 0., 0., 0., 1.875613, 45);
    PParticle *q = new PParticle(*p + *d);
    PParticle *eta = new PParticle("eta");
    c1 = new PDecayChannel;
    c2 = new PDecayChannel;
    c1->AddChannel(1.0, "He3", "eta");
    c2->AddChannel(1.0, "pi0", "pi0", "pi0");
    pdm->AddChannel("eta", c2);
    pdm->InitReaction(q, c1);
    pdm->Print();



    //Multiplicity for stable particles
    TH1F *histo1 = new TH1F ("histo1", "part mult", 21, -0.5, 20.5);
    pdm->Do("counter = 0;"); 
    pdm->Do("foreach(*); counter = counter +1");
    //pdm->Do("echo $counter;"); 
    pdm->Do(histo1, "_x = counter");

    int n = pdm->loop(100000, 0, "pd_eta_3pi0", 0, 0, 0,  1);


    
    


}
