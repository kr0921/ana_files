


/////////////////////////////////////////////////
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


void draw_momentum(const char myvar[], const char cut1[], const char title[], float ymax=1000.){

  char fdata[] = "res/nd280Highland2_v2r45_1_data.root";
  char fmc[] = "res/nd280Highland2_v2r45_1_MC.root";
  
  TString var(myvar);
  TString ttl(title);
  
  auto f = new TFile(fdata);
  auto h = new TProfile("h","h",40,0.,2000.);
  default->Draw((var+">>h").Data(),cut1);
  h->SetLineColor(4);
  h->SetLineWidth(3);

  auto f_mc = new TFile(fmc);
  auto hmc = new TProfile("hmc","hmc",40,0.,2000.);
  default->Draw((var+">>hmc").Data(),cut1);
  hmc->SetLineColor(3);
  hmc->SetLineWidth(3);

  
  mygStyleSetup();
  auto c = new TCanvas("c","c");
  TH1F *hr3 = c->DrawFrame(0.,-0.5,2000,1.1);
  hr3->SetTitle(title);
  hr3->SetXTitle("last_tpc_mom, MeV");
  if(ttl.Contains("pos")) hr3->SetYTitle("< #frac{last_tpc_mom-mom_p_range_tpc}{last_tpc_mom} >");
  else hr3->SetYTitle("< #frac{last_tpc_mom-mom_mu_range_tpc}{last_tpc_mom} >");
  hr3 -> GetXaxis() -> CenterTitle(); 
  hr3 -> GetYaxis() -> CenterTitle(); 
  
  
  hmc->Draw("same");
  h->Draw("same");
  
  TLegend* leg = new TLegend(0.58,0.28,0.85,0.44);     
  //leg->SetBorderSize(0);
  //leg->SetHeader("tHjb events");                            
  leg->AddEntry(h,"Data","le");
  leg->AddEntry(hmc,"MC","le");
  leg->Draw();
  
  c->SaveAs("000.pdf");
}

void draw_momentum000(const char myvar[], const char cut1[], const char title[], float ymax=1000.){

  char fdata[] = "res/nd280Highland2_v2r45_1_data.root";
  char fmc[] = "res/nd280Highland2_v2r45_1_MC.root";
  
  TString var(myvar);
  TString ttl(title);
    
  auto f = new TFile(fdata);
  auto h = new TProfile("h","h",40,0.,2000.);
  default->Draw((var+">>h").Data(),cut1);
  h->SetLineColor(4);
  h->SetLineWidth(3);

  auto f_mc = new TFile(fmc);
  auto hmc = new TProfile("hmc","hmc",40,0.,2000.);
  default->Draw((var+">>hmc").Data(),cut1);
  hmc->SetLineColor(3);
  hmc->SetLineWidth(3);

  
  float xminf(350.);
  float xmaxf(700.);
  if(ttl.Contains("posFGD2")){xminf=350.;xmaxf=700;}
  if(ttl.Contains("posDsEcal")){xminf=450.;xmaxf=800;}
  if(ttl.Contains("negFGD1")){xminf=50.;xmaxf=250;}
  if(ttl.Contains("negFGD2")){xminf=50.;xmaxf=250;}
  if(ttl.Contains("negDsECal")){xminf=100.;xmaxf=300;}
  if(ttl.Contains("FGD1->ECal")){xminf=250.;xmaxf=500;}
  if(ttl.Contains("FGD1->ECal-SMRD")){xminf=500.;xmaxf=1200;}
  if(ttl.Contains("FGD2->ECal")){xminf=200.;xmaxf=450;}
  if(ttl.Contains("FGD2->ECal-SMRD")){xminf=400.;xmaxf=900;}
  hmc->Fit("pol1","","",xminf,xmaxf);

  
  mygStyleSetup();
  TCanvas c("c","c");
  TH1F *hr3 = c.DrawFrame(0.,0.,2000,ymax);
  hr3->SetTitle(title);
  hr3->SetXTitle("last_tpc_mom, MeV");
  if(ttl.Contains("pos"))hr3->SetYTitle("< mom_p_range_tpc >, MeV");
  else hr3->SetYTitle("< mom_mu_range_tpc >, MeV");
  hr3 -> GetXaxis() -> CenterTitle(); 
  hr3 -> GetYaxis() -> CenterTitle(); 
  
 gStyle->SetOptFit(1);
  
  hmc->Draw("sames");
  h->Draw("same");
  
  TLegend* leg = new TLegend(0.62,0.17,0.89,0.35);     
  //leg->SetBorderSize(0);
  //leg->SetHeader("tHjb events");                            
  leg->AddEntry(h,"Data","le");
  leg->AddEntry(hmc,"MC","le");
  leg->Draw();
  
  c.SaveAs("000.pdf");
}



////////////////////////////
void myscript_tprofile(){
    
TString myvar00("(last_tpc_mom-mom_p_range_tpc)/last_tpc_mom:last_tpc_mom");    
TString myvar10("(last_tpc_mom-mom_mu_range_tpc)/last_tpc_mom:last_tpc_mom");    
TString myvar0("mom_p_range_tpc:last_tpc_mom");
TString myvar1("mom_mu_range_tpc:last_tpc_mom");
TString basic_cut(" last_tpc_nnodes>18 && last_tpc_mom>0 && startpos[2]> -2000");


gROOT->ProcessLine(".! rm report.pdf");



/*

   TString mycut = basic_cut+" && accum_level[0][0]>7";
   draw_momentum(myvar00.Data(), mycut.Data(), "posFGD1");
   gROOT->ProcessLine(".! pdfunite 000.pdf report.pdf");
   //
   TString mycut = basic_cut+" && accum_level[0][1]>7";
   draw_momentum(myvar00.Data(), mycut.Data(), "posFGD2");
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   //
   TString mycut = basic_cut+" && accum_level[0][2]>7";
   draw_momentum(myvar00.Data(), mycut.Data(), "posDsEcal");
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   //
   TString mycut = basic_cut+" && accum_level[0][3]>7";
   draw_momentum(myvar10.Data(), mycut.Data(), "negFGD1",400);
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   //
   TString mycut = basic_cut+" && accum_level[0][4]>6";
   draw_momentum(myvar10.Data(), mycut.Data(), "negFGD2",400);
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   //
   TString mycut = basic_cut+" && accum_level[0][5]>7";
   draw_momentum(myvar10.Data(), mycut.Data(), "negDsECal",400);
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   //
   TString mycut = basic_cut+" && accum_level[0][6]>7";
   draw_momentum(myvar10.Data(), mycut.Data(), "FGD1->ECal",700);
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   //
   TString mycut = basic_cut+" && accum_level[0][7]>7";
   draw_momentum(myvar10.Data(), mycut.Data(), "FGD1->ECal-SMRD",2000);
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   //
   TString mycut = basic_cut+" && accum_level[0][8]>7";
   draw_momentum(myvar10.Data(), mycut.Data(), "FGD2->ECal",500);
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   //
   TString mycut = basic_cut+" && accum_level[0][9]>7";
   draw_momentum(myvar10.Data(), mycut.Data(), "FGD2->ECal-SMRD");
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   
   return;
*/   
   TString mycut = basic_cut+" && accum_level[0][0]>7";
   draw_momentum000(myvar0.Data(), mycut.Data(), "posFGD1");
   gROOT->ProcessLine(".! pdfunite 000.pdf report.pdf");
   //
   TString mycut = basic_cut+" && accum_level[0][1]>7";
   draw_momentum000(myvar0.Data(), mycut.Data(), "posFGD2");
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   //
   TString mycut = basic_cut+" && accum_level[0][2]>7";
   draw_momentum000(myvar0.Data(), mycut.Data(), "posDsEcal");
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   //
   TString mycut = basic_cut+" && accum_level[0][3]>7";
   draw_momentum000(myvar1.Data(), mycut.Data(), "negFGD1",400);
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   //
   TString mycut = basic_cut+" && accum_level[0][4]>6";
   draw_momentum000(myvar1.Data(), mycut.Data(), "negFGD2",400);
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   //
   TString mycut = basic_cut+" && accum_level[0][5]>7";
   draw_momentum000(myvar1.Data(), mycut.Data(), "negDsECal",400);
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   //
   TString mycut = basic_cut+" && accum_level[0][6]>7";
   draw_momentum000(myvar1.Data(), mycut.Data(), "FGD1->ECal",700);
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   //
   TString mycut = basic_cut+" && accum_level[0][7]>7";
   draw_momentum000(myvar1.Data(), mycut.Data(), "FGD1->ECal-SMRD",2000);
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   //
   TString mycut = basic_cut+" && accum_level[0][8]>7";
   draw_momentum000(myvar1.Data(), mycut.Data(), "FGD2->ECal",500);
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   //
   TString mycut = basic_cut+" && accum_level[0][9]>7";
   draw_momentum000(myvar1.Data(), mycut.Data(), "FGD2->ECal-SMRD");
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");

    
}


