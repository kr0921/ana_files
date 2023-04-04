

void mygStyleSetup(){
//gStyle//////////////////////////////////
 gStyle->SetOptStat(00000);
 //gStyle->SetOptStat(00000);
 //gStyle->SetOptTitle(0);
 gStyle->SetHistLineWidth(2);
 gStyle->SetLineWidth(3);
 gStyle -> SetFrameLineWidth(3);
 //gStyle->SetLabelSize(0.035,"X");
 gStyle->SetTitleXOffset(1.2);
 gStyle->SetTitleYOffset(1.35);
 gStyle->SetLabelColor(1,"X");
 gStyle->SetLabelColor(1,"Y");
 //gStyle->SetMarkerStyle(20);
 gStyle -> SetMarkerSize(1);
 gStyle -> SetLabelSize(0.045,"X");
 gStyle -> SetLabelSize(0.045,"Y");
 gStyle -> SetTitleSize(0.045,"XY");
 gStyle -> SetPadLeftMargin(0.14);
 gStyle -> SetPadBottomMargin(0.13);
}



TGraph*  calc_curve(float my_n_limit){
  TFile *_file0 = TFile::Open("res2/graph_expected_ldm.v1.root");
  //TGraph* all_fgd12_rec0; _file0->GetObject("all_fgd12_rec0",all_fgd12_rec0);
  //TGraph* all_fgd12_rec0; _file0->GetObject("all_fgd12_exp0",all_fgd12_rec0);

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

  //n_limit = 5.7; // lim 90%: stat=2*10^21POT B=12 => S=5.7
  //n_limit = 1.5; //statX10 lim90% B=120 => S=15
  //n_limit = 1.05; //statX20 lim90% B=240 => S=21   =>21./20=1.05

  n_limit = my_n_limit; //1.; //
  
  
  
  Double_t x[200], y[200], y1[200];
  int npoints=0;
  float Mv=0.005;
  while(Mv<0.547){
  //while(Mv<0.127){
     //float nrec0 = all_fgd12_rec0->Eval(Mv)*2.*(2./1.8); //fgd1*2 
     //float nrec0 = all_fgd12_rec0->Eval(Mv)*2.*(2./1.8)*0.3; //fgd1*2 
     //float nrec0 = all_fgd12_rec0->Eval(Mv); //
     
     //calc with no Eff factor
     float nrec0 = eta_fgd1_exp0->Eval(Mv)+eta_fgd2_exp0->Eval(Mv);
     if(Mv<0.127)nrec0 += pi0_fgd1_exp0->Eval(Mv)+pi0_fgd2_exp0->Eval(Mv);
     
     float Y_limit1 = Y0*n_limit/nrec0;
     float Y_limit = Y0*sqrt(n_limit/nrec0);
    std::cout<<Mv<<"  "<<Mv/3.<<"  "<<nrec0<<"  "<<Y_limit/*<<"  "<<Y_limit1*/<<std::endl;
     x[npoints] = Mv/3.;
     y[npoints] = Y_limit;
     y1[npoints] = Y_limit1;
     npoints++;
     Mv += 0.005;
  }
  TGraph* gr = new TGraph(npoints,x,y);
  gr->SetName("YMx_limits");
  gr->SetTitle("YMx_limits");
  gr->SetLineColor(2);
  gr->SetLineWidth(3);
  
  //TGraph* gr1 = new TGraph(npoints,x,y1);
  //gr1->SetName("YMx_limits");
  //gr1->SetTitle("YMx_limits");
  //gr1->SetLineColor(4);
  //gr1->SetLineWidth(3);

  return gr;
}







////////
void benchmark_ldm(){
    
  auto gr1 = calc_curve(1.);
  gr1->SetLineColor(2);
  gr1->SetLineWidth(4);
  auto gr10 = calc_curve(10.);
  gr10->SetLineColor(2);
  gr10->SetLineWidth(4);
  gr10->SetLineStyle(7);
  auto gr1000 = calc_curve(1000.);
  gr1000->SetLineColor(2);
  gr1000->SetLineWidth(4);
  gr1000->SetLineStyle(2);
  
  
  ////////
  mygStyleSetup();  
  auto c = new TCanvas();
  c->SetLogx();
  c->SetLogy();
  TH1F *hfr = c->DrawFrame(0.0015,1e-14,0.2,1e-7);
  hfr->SetYTitle("Y=#epsilon^{2}#alpha_{D}(m_{#chi}/m_{V})^{4}");
  hfr->SetXTitle("M_{#chi}, GeV");
  //hfr->SetTitle("T2K sensetivity to LDM");
  //hfr->SetTitle("e #chi -> e #chi,   m_{V}=3m_{#chi},      #alpha_{D}=0.5");  //,     #epsilon=0.001");
  
  gr1->Draw("same");
  gr10->Draw("same");
  gr1000->Draw("same");
  

  TLegend* leg = new TLegend(0.52,0.22,0.87,0.47);
  leg->SetBorderSize(0);
  leg->SetHeader("ND280 POT=2x10^{21}");
  //leg->AddEntry(gr1,"Sensitivity","l");
  //leg->AddEntry(gr1,"Eff=30\%, B=0, Syst=0 ","");
  leg->AddEntry(gr1,"1 event","l");
  leg->AddEntry(gr10,"10 events","l");
  leg->AddEntry(gr1000,"10^{3} events","l");
  leg->Draw();

  c->SaveAs("escater_curves_fgd12.png");
  //c->SaveAs("escater_sensitivity0_fgd1_fgd2.png");
  
// MiniBoone calculation 
//if(false){
//    double pot_rate=1.8;
//    double Y0m=sqrt(1.e-13)*sqrt(0.5)*pow(1./3.,4);
//    double Y10m=Y0m*sqrt(10/(pot_rate*5.e4));
//    std::cout<<std::endl<<"MiniBoone  mx=0.01  Y="<<Y10m<<std::endl;
//  }
  
  

}







