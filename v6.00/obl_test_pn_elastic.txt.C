//TITLE pn elastic

{{

  
  Int_t nev = 10000;
  



  PReaction ela1("0.010","p","n","p n");
  ela1.Print();
  TH1F * theta1 = 
    new TH1F ("theta1","Polar angle at 10 MeV",100,-1,1);
  ela1.Do(theta1,"p1 = [p,1]; p1->Boost([p + n]); _x = p1->CosTheta()");
  ela1.Loop(nev);



  PReaction ela2("0.159","p","n","p n");
  ela2.Print();
  TH1F * theta2 = 
    new TH1F ("theta2","Polar angle at 159 MeV",100,-1,1);
  ela2.Do(theta2,"p1 = [p,1]; p1->Boost([p + n]); _x = p1->CosTheta()");
  ela2.Loop(nev);


    
  PReaction ela3("0.370","p","n","p n");
  ela3.Print();
  TH1F * theta3 = 
    new TH1F ("theta3","Polar angle at 370 MeV",100,-1,1);
  ela3.Do(theta3,"p1 = [p,1]; p1->Boost([p + n]); _x = p1->CosTheta()");
  ela3.Loop(nev);



  PReaction ela4("2","p","n","p n");
  ela4.Print();
  TH1F * theta4 = 
    new TH1F ("theta4","Polar angle at 2 GeV",100,-1,1);
  ela4.Do(theta4,"p1 = [p,1]; p1->Boost([p + n]); _x = p1->CosTheta()");
  ela4.Do(theta4,"_x = 1.");
  ela4.Loop(nev);


}}
