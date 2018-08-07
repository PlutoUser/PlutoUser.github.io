//TITLE Angles


void obl_test_helicity() {

    


    TH1F * histo1 = new TH1F ("histo1","D+ angle",100,-1,1);
    TH1F * histo2 = new TH1F ("histo2","helicity angle",50,0,1);

    //makeDistributionManager()->Disable("helicity_angles");
    
    PReaction my_reaction(3.13,"p","p","p D+ [p pi0 [dilepton [e+ e-] g]]");
    
    my_reaction.Do(histo2,"_pi0=[pi0]; _ep=[e+]; _em=[e-]; _pi0->Boost([p + p]); _em->Boost([p + p]); _ep->Boost([p + p]); _ep->Rot(_pi0); _em->Rot(_pi0); _pi0->Rot(_pi0) ; _ep->Boost(_pi0); _em->Boost(_pi0); dil=_ep+_em; _ep->Rot(dil); _em->Rot(dil); dil->Rot(dil); _ep->Boost(dil); _em->Boost(dil) ; s1= _ep->Theta();s2=_em->Theta(); _x = fabs(cos(s1)) ");
    
    my_reaction.Do(histo1,"mydelta = [D+]; mydelta->Boost([p + p]); _x = mydelta->CosTheta() ");
    
    my_reaction.Print();
    my_reaction.Loop(100000);
        
    
    

    




}
