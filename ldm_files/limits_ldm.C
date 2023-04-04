{
  TFile *_file0 = TFile::Open("res2/graph_expected_ldm.v1.root");
  TGraph* all_fgd12_rec0; _file0.GetObject("all_fgd12_rec0",all_fgd12_rec0);

  double ratio_Mxv =1./3.;
  double alpha_d = 0.5;
  double epsilon = 0.001;
  double Y0 = pow(epsilon,2)*alpha_d*pow(ratio_Mxv,4);
  std::cout<<"Y0= "<<Y0<<std::endl;

  //double n_limit = 3;//(15X)  12.;
  //double n_limit = 2.4;//9;
  
  
  double n_limit = 0.;
  //n_limit = 9; // S/sqrt(S+B)=2 stat=2*10^21POT B=12 => S=9
  //n_limit = 2.4; //statX10 S/sqrt(S+B)=2 B=120 => S=24
  //n_limit = 1.65; //statX20 S/sqrt(S+B)=2 B=240 => S=33   =>33./20=1.65

  n_limit = 5.7; // lim 90%: stat=2*10^21POT B=12 => S=5.7
  //n_limit = 1.5; //statX10 lim90% B=120 => S=15
  //n_limit = 1.05; //statX20 lim90% B=240 => S=21   =>21./20=1.05
  
  Double_t x[200], y[200], y1[200];
  int npoints=0;
  float Mv=0.005;
  while(Mv<0.547){
  //while(Mv<0.127){
     float nrec0 = all_fgd12_rec0->Eval(Mv);  
     //calc with no Eff factor
     //float nrec0 = eta_fgd1_exp0->Eval(Mv)+eta_fgd2_exp0->Eval(Mv);
     //if(Mv<0.127)nrec0 += pi0_fgd1_exp0->Eval(Mv)+pi0_fgd2_exp0->Eval(Mv);
     //float Y_limit1 = Y0*n_limit/nrec0;
     float Y_limit = Y0*sqrt(n_limit/nrec0);
    std::cout<<Mv<<"  "<<Mv/3.<<"  "<<nrec0<<"  "<<Y_limit/*<<"  "<<Y_limit1*/<<std::endl;
     x[npoints] = Mv/3.;
     y[npoints] = Y_limit;
     y1[npoints] = Y_limit;//Y_limit1;
     npoints++;
     Mv += 0.005;
  }
  TGraph* gr = new TGraph(npoints,x,y);
  gr->SetName("YMx_limits");
  gr->SetTitle("YMx_limits");
  gr->SetLineColor(2);
  gr->SetLineWidth(3);
  
  TGraph* gr1 = new TGraph(npoints,x,y1);
  gr1->SetName("YMx_limits");
  gr1->SetTitle("YMx_limits");
  gr1->SetLineColor(4);
  gr1->SetLineWidth(3);

  
  auto c = new TCanvas();
  c->SetLogx();
  c->SetLogy();
  TH1F *hfr = c->DrawFrame(0.001,1e-13,0.6,1e-5);
  hfr->SetYTitle("Y=#epsilon^{2}#alpha_{D}(m_{#chi}/m_{V})^{4}");
  hfr->SetXTitle("M_{#chi}, GeV");
  hfr->SetTitle("ND280 sensitivity to LDM");
  
  gr->Draw("same");
  //gr1->Draw("same");
  c->SaveAs("ldm_sensitivity.png");
  
  
// MiniBoone calculation 
if(false){
    double pot_rate=1.8;
    double Y0m=sqrt(1.e-13)*sqrt(0.5)*pow(1./3.,4);
    double Y10m=Y0m*sqrt(10/(pot_rate*5.e4));
    std::cout<<std::endl<<"MiniBoone  mx=0.01  Y="<<Y10m<<std::endl;
  }
  
  
  
  
  
  


}
