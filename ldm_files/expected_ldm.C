
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


void prepare_nexp(){

    gROOT->ProcessLine(".! awk -F_ '{print $7\" \"$17}' res2/fgd1_eta_decay_prerun7geom.info_string > 000.tmp");
    auto eta_fgd1_exp0 = new TGraph("000.tmp");
    eta_fgd1_exp0->Sort();
    eta_fgd1_exp0->SetName("eta_fgd1_exp0");
    eta_fgd1_exp0->SetTitle("eta_fgd1_exp0");
    eta_fgd1_exp0->SetMarkerStyle(20);
    eta_fgd1_exp0->SetMarkerSize(1.3);
    eta_fgd1_exp0->SetMarkerColor(2);
    eta_fgd1_exp0->SetLineColor(2);
    eta_fgd1_exp0->SetLineWidth(4);
    //eta_fgd1_exp0->Draw("AC*");

    gROOT->ProcessLine(".! awk -F_ '{print $7\" \"$17}' res2/fgd1_pi0_decay_prerun7geom.info_string > 000.tmp");
    auto pi0_fgd1_exp0 = new TGraph("000.tmp");
    pi0_fgd1_exp0->Sort();
    pi0_fgd1_exp0->SetName("pi0_fgd1_exp0");
    pi0_fgd1_exp0->SetTitle("pi0_fgd1_exp0");
    pi0_fgd1_exp0->SetMarkerStyle(20);
    pi0_fgd1_exp0->SetMarkerSize(1.3);
    pi0_fgd1_exp0->SetMarkerColor(3);
    pi0_fgd1_exp0->SetLineColor(3);
    pi0_fgd1_exp0->SetLineWidth(4);
    //pi0_fgd1_exp0->Draw("AC*");

    gROOT->ProcessLine(".! awk -F_ '{print $7\" \"$17}' res2/fgd2_eta_decay_prerun7geom.info_string > 000.tmp");
    auto eta_fgd2_exp0 = new TGraph("000.tmp");
    eta_fgd2_exp0->Sort();
    eta_fgd2_exp0->SetName("eta_fgd2_exp0");
    eta_fgd2_exp0->SetTitle("eta_fgd2_exp0");
    eta_fgd2_exp0->SetMarkerStyle(20);
    eta_fgd2_exp0->SetMarkerSize(1.3);
    eta_fgd2_exp0->SetMarkerColor(4);
    eta_fgd2_exp0->SetLineColor(4);
    eta_fgd2_exp0->SetLineWidth(4);
    //eta_fgd2_exp0->Draw("AC*");

    gROOT->ProcessLine(".! awk -F_ '{print $7\" \"$17}' res2/fgd2_pi0_decay_prerun7geom.info_string > 000.tmp");
    auto pi0_fgd2_exp0 = new TGraph("000.tmp");
    pi0_fgd2_exp0->Sort();
    pi0_fgd2_exp0->SetName("pi0_fgd2_exp0");
    pi0_fgd2_exp0->SetTitle("pi0_fgd2_exp0");
    pi0_fgd2_exp0->SetMarkerStyle(20);
    pi0_fgd2_exp0->SetMarkerSize(1.3);
    pi0_fgd2_exp0->SetMarkerColor(6);
    pi0_fgd2_exp0->SetLineColor(6);
    pi0_fgd2_exp0->SetLineWidth(4);
    //pi0_fgd2_exp0->Draw("same");

/*    gROOT->ProcessLine(".! awk -F_ '{print $7\" \"$17}' res1/eta_p0d_win_info_string > 000.tmp");
    auto eta_p0d_win_exp0 = new TGraph("000.tmp");
    eta_p0d_win_exp0->Sort();
    eta_p0d_win_exp0->SetName("eta_p0d_win_exp0");
    eta_p0d_win_exp0->SetTitle("eta_p0d_win_exp0");
    eta_p0d_win_exp0->SetMarkerStyle(20);
    eta_p0d_win_exp0->SetMarkerSize(1.3);
    eta_p0d_win_exp0->SetMarkerColor(7);
    eta_p0d_win_exp0->SetLineColor(7);
    eta_p0d_win_exp0->SetLineWidth(4);
    //eta_p0d_win_exp0->Draw("AC*");

    gROOT->ProcessLine(".! awk -F_ '{print $7\" \"$17}' res1/eta_p0d_wout_info_string > 000.tmp");
    auto eta_p0d_wout_exp0 = new TGraph("000.tmp");
    eta_p0d_wout_exp0->Sort();
    eta_p0d_wout_exp0->SetName("eta_p0d_wout_exp0");
    eta_p0d_wout_exp0->SetTitle("eta_p0d_wout_exp0");
    eta_p0d_wout_exp0->SetMarkerStyle(20);
    eta_p0d_wout_exp0->SetMarkerSize(1.3);
    eta_p0d_wout_exp0->SetMarkerColor(8);
    eta_p0d_wout_exp0->SetLineColor(8);
    eta_p0d_wout_exp0->SetLineWidth(4);
    //eta_p0d_wout_exp0->Draw("AC*");

    gROOT->ProcessLine(".! awk -F_ '{print $7\" \"$17}' res1/pi0_p0d_win_info_string > 000.tmp");
    auto pi0_p0d_win_exp0 = new TGraph("000.tmp");
    pi0_p0d_win_exp0->Sort();
    pi0_p0d_win_exp0->SetName("pi0_p0d_win_exp0");
    pi0_p0d_win_exp0->SetTitle("pi0_p0d_win_exp0");
    pi0_p0d_win_exp0->SetMarkerStyle(20);
    pi0_p0d_win_exp0->SetMarkerSize(1.3);
    pi0_p0d_win_exp0->SetMarkerColor(9);
    pi0_p0d_win_exp0->SetLineColor(9);
    pi0_p0d_win_exp0->SetLineWidth(4);
    //pi0_p0d_win_exp0->Draw("AC*");

    gROOT->ProcessLine(".! awk -F_ '{print $7\" \"$17}' res1/pi0_p0d_wout_info_string > 000.tmp");
    auto pi0_p0d_wout_exp0 = new TGraph("000.tmp");
    pi0_p0d_wout_exp0->Sort();
    pi0_p0d_wout_exp0->SetName("pi0_p0d_wout_exp0");
    pi0_p0d_wout_exp0->SetTitle("pi0_p0d_wout_exp0");
    pi0_p0d_wout_exp0->SetMarkerStyle(20);
    pi0_p0d_wout_exp0->SetMarkerSize(1.3);
    pi0_p0d_wout_exp0->SetMarkerColor(12);
    pi0_p0d_wout_exp0->SetLineColor(12);
    pi0_p0d_wout_exp0->SetLineWidth(4);
    //pi0_p0d_wout_exp0->Draw("AC*");
*/
    
////////////////////////    
    
    
  auto c = new TCanvas();
  c->SetLogy();
  TH1F *hfr = c->DrawFrame(0.,0.00001,0.6,300e+6);
  hfr->SetYTitle("#events/1.8e+21 POT");
  hfr->SetXTitle("M_{V}, GeV");
  hfr->SetTitle("e #chi -> e #chi,   m_{V}=3m_{#chi},      #alpha_{D}=0.5,     #epsilon=0.001");
  //hfr->SetTitle("Total detector systematic uncertainty vs M_{V}");
   
  eta_fgd1_exp0->Draw("same LP");
  pi0_fgd1_exp0->Draw("same LP");
  eta_fgd2_exp0->Draw("same L");
  pi0_fgd2_exp0->Draw("same L");
  //eta_p0d_win_exp0->Draw("same LP");
  //eta_p0d_wout_exp0->Draw("same L");
  //pi0_p0d_win_exp0->Draw("same LP");
  //pi0_p0d_wout_exp0->Draw("same L");
   
    
  TLegend* leg = new TLegend(0.50,0.52,0.87,0.87);
  leg->AddEntry(eta_fgd1_exp0,"#eta parent, FGD1","lp");
  leg->AddEntry(eta_fgd2_exp0,"#eta parent, FGD2","l");
  leg->AddEntry(pi0_fgd1_exp0,"#pi^{0} parent, FGD1","lp");
  leg->AddEntry(pi0_fgd2_exp0,"#pi^{0} parent, FGD2","l");
  //leg->AddEntry(eta_p0d_win_exp0,"#eta parent, P0D_win","lp");
  //leg->AddEntry(eta_p0d_wout_exp0,"#eta parent, P0D_wout","l");
  //leg->AddEntry(pi0_p0d_win_exp0,"#pi^{0} parent, P0D_win","lp");
  //leg->AddEntry(pi0_p0d_wout_exp0,"#pi^{0} parent, P0D_wout","l");
  leg->Draw();
    

  if(false){
    c->SaveAs("ldm_expected_v2.png");
    
    TFile f("graph_expected_ldm.root","update"/*"recreate"*/);
    eta_fgd1_exp0->Write();
    eta_fgd2_exp0->Write();
    pi0_fgd1_exp0->Write();
    pi0_fgd2_exp0->Write();
    //eta_p0d_win_exp0->Write();
    //eta_p0d_wout_exp0->Write();
    //pi0_p0d_win_exp0->Write();
    //pi0_p0d_wout_exp0->Write();
    f.Close(); 
  }
}
////////////////////////////////////////////////////////////////////
 
TGraph* calculate_expected_ldm_rec(const char grname[],const char nexp_name[],const char eff_name[],float pot_scale=1., float maxMv=0.127){
  TFile f("graph_expected_ldm.root");
  TGraph* nexp; f.GetObject(nexp_name,nexp);
  TGraphAsymmErrors* eff; f.GetObject(eff_name,eff);
  
  Double_t x[200], y[200];
  int npoints=0;
  float Mv=0.005;
  while(Mv<maxMv){
     float nrec = pot_scale*nexp->Eval(Mv)*eff->Eval(Mv);
     std::cout<<Mv<<"  "<<nrec<<std::endl;
     x[npoints] = Mv;
     y[npoints] = nrec;
     npoints++;
     Mv += 0.005;
  }
  TGraph* gr = new TGraph(npoints,x,y);
  gr->SetName(grname);
  gr->SetTitle(grname);
  //gr->Draw("AC*");
  
  f.Close();
  return gr;
}

/////////////////////////////////////////////////////////////
void expected_ldm(){
    
    //prepare_nexp();
    //return;
    
    
    float POT_fgd = 1.8924481; //  2.098; //e+21 !!!
    float POT_p0d_win = 0.949728; //e+21 !!!
    float POT_p0d_wout = 1.148457; //e+21 !!!
    float POT_ldm_mc = 1.8; //e+21 !!!
    
    auto eta_fgd1_rec0 = calculate_expected_ldm_rec("eta_fgd1_rec0","eta_fgd1_exp0","fgd1_eta",POT_fgd/POT_ldm_mc,0.547);
    eta_fgd1_rec0->SetMarkerStyle(20);
    eta_fgd1_rec0->SetMarkerSize(1.3);
    eta_fgd1_rec0->SetMarkerColor(2);
    eta_fgd1_rec0->SetLineColor(2);
    eta_fgd1_rec0->SetLineWidth(4);
    
    auto pi0_fgd1_rec0 = calculate_expected_ldm_rec("pi0_fgd1_rec0","pi0_fgd1_exp0","fgd1_pi0",POT_fgd/POT_ldm_mc,0.127); 
    pi0_fgd1_rec0->SetMarkerStyle(20);
    pi0_fgd1_rec0->SetMarkerSize(1.3);
    pi0_fgd1_rec0->SetMarkerColor(3);
    pi0_fgd1_rec0->SetLineColor(3);
    pi0_fgd1_rec0->SetLineWidth(4);
    
    auto eta_fgd2_rec0 = calculate_expected_ldm_rec("eta_fgd2_rec0","eta_fgd2_exp0","fgd2_eta",POT_fgd/POT_ldm_mc,0.547); 
    eta_fgd2_rec0->SetMarkerStyle(20);
    eta_fgd2_rec0->SetMarkerSize(1.3);
    eta_fgd2_rec0->SetMarkerColor(4);
    eta_fgd2_rec0->SetLineColor(4);
    eta_fgd2_rec0->SetLineWidth(4);
    
    auto pi0_fgd2_rec0 = calculate_expected_ldm_rec("pi0_fgd2_rec0","pi0_fgd2_exp0","fgd2_pi0",POT_fgd/POT_ldm_mc,0.127);  
    pi0_fgd2_rec0->SetMarkerStyle(20);
    pi0_fgd2_rec0->SetMarkerSize(1.3);
    pi0_fgd2_rec0->SetMarkerColor(6);
    pi0_fgd2_rec0->SetLineColor(6);
    pi0_fgd2_rec0->SetLineWidth(4);

/*    auto eta_p0d_win_rec0 = calculate_expected_ldm_rec("eta_p0d_win_rec0","eta_p0d_win_exp0","p0d_win_eta",POT_p0d_win/POT_ldm_mc,0.547);  
    eta_p0d_win_rec0->SetMarkerStyle(20);
    eta_p0d_win_rec0->SetMarkerSize(1.3);
    eta_p0d_win_rec0->SetMarkerColor(7);
    eta_p0d_win_rec0->SetLineColor(7);
    eta_p0d_win_rec0->SetLineWidth(4);

    auto eta_p0d_wout_rec0 = calculate_expected_ldm_rec("eta_p0d_wout_rec0","eta_p0d_wout_exp0","p0d_wout_eta",POT_p0d_wout/POT_ldm_mc,0.547);  
    eta_p0d_wout_rec0->SetMarkerStyle(20);
    eta_p0d_wout_rec0->SetMarkerSize(1.3);
    eta_p0d_wout_rec0->SetMarkerColor(8);
    eta_p0d_wout_rec0->SetLineColor(8);
    eta_p0d_wout_rec0->SetLineWidth(4);

    auto pi0_p0d_win_rec0 = calculate_expected_ldm_rec("pi0_p0d_win_rec0","pi0_p0d_win_exp0","p0d_win_pi0",POT_p0d_win/POT_ldm_mc,0.127);  
    pi0_p0d_win_rec0->SetMarkerStyle(20);
    pi0_p0d_win_rec0->SetMarkerSize(1.3);
    pi0_p0d_win_rec0->SetMarkerColor(9);
    pi0_p0d_win_rec0->SetLineColor(9);
    pi0_p0d_win_rec0->SetLineWidth(4);

    auto pi0_p0d_wout_rec0 = calculate_expected_ldm_rec("pi0_p0d_wout_rec0","pi0_p0d_wout_exp0","p0d_wout_pi0",POT_p0d_wout/POT_ldm_mc,0.127);  
    pi0_p0d_wout_rec0->SetMarkerStyle(20);
    pi0_p0d_wout_rec0->SetMarkerSize(1.3);
    pi0_p0d_wout_rec0->SetMarkerColor(12);
    pi0_p0d_wout_rec0->SetLineColor(12);
    pi0_p0d_wout_rec0->SetLineWidth(4);*/


//////////////////////// 
  Double_t x[200], y[200];
  Double_t y1[200];
  int npoints=0;
  float Mv=0.005;
  while(Mv<0.547){
  //while(Mv<0.127){
     float nrec, nrec1;
     if(Mv<0.127){
         nrec = eta_fgd1_rec0->Eval(Mv)+pi0_fgd1_rec0->Eval(Mv)+eta_fgd2_rec0->Eval(Mv)+pi0_fgd2_rec0->Eval(Mv)/*+
         eta_p0d_win_rec0->Eval(Mv)+eta_p0d_wout_rec0->Eval(Mv)+pi0_p0d_win_rec0->Eval(Mv)+pi0_p0d_wout_rec0->Eval(Mv)*/;
         nrec1 = eta_fgd1_rec0->Eval(Mv)+pi0_fgd1_rec0->Eval(Mv)+eta_fgd2_rec0->Eval(Mv)+pi0_fgd2_rec0->Eval(Mv);
     } else {
         nrec = eta_fgd1_rec0->Eval(Mv)+eta_fgd2_rec0->Eval(Mv)/*+
         eta_p0d_win_rec0->Eval(Mv)+eta_p0d_wout_rec0->Eval(Mv)*/;
         nrec1 = eta_fgd1_rec0->Eval(Mv)+eta_fgd2_rec0->Eval(Mv);
     }
     std::cout<<Mv<<"  "<<nrec<<std::endl;
     x[npoints] = Mv;
     y[npoints] = nrec;
     y1[npoints] = nrec1;
     npoints++;
     Mv += 0.005;
  }
  auto all_all_rec0 = new TGraph(npoints,x,y);
  all_all_rec0->SetName("all_all_rec0");
  all_all_rec0->SetTitle("all_all_rec0");
  all_all_rec0->SetMarkerStyle(20);
  all_all_rec0->SetMarkerSize(1.3);
  all_all_rec0->SetMarkerColor(1);
  all_all_rec0->SetLineColor(1);
  all_all_rec0->SetLineWidth(4);
   
  auto all_fgd12_rec0 = new TGraph(npoints,x,y1);
  all_fgd12_rec0->SetName("all_fgd12_rec0");
  all_fgd12_rec0->SetTitle("all_fgd12_rec0");
  all_fgd12_rec0->SetMarkerStyle(20);
  all_fgd12_rec0->SetMarkerSize(1.3);
  all_fgd12_rec0->SetMarkerColor(14);
  all_fgd12_rec0->SetLineColor(14);
  all_fgd12_rec0->SetLineWidth(4);
    
//////////////////////// 
  mygStyleSetup();

  auto c = new TCanvas();
  c->SetLogy();
  TH1F *hfr = c->DrawFrame(0.,0.00001,0.6,300e+6);
  hfr->SetYTitle("#events");
  hfr->SetXTitle("M_{V}, GeV");
  hfr->SetTitle("e #chi -> e #chi,   m_{V}=3m_{#chi},      #alpha_{D}=0.5,     #epsilon=0.001");
  //hfr->SetTitle("Total detector systematic uncertainty vs M_{V}");
   
  eta_fgd1_rec0->Draw("same LP");
  pi0_fgd1_rec0->Draw("same LP");
  eta_fgd2_rec0->Draw("same L");
  pi0_fgd2_rec0->Draw("same L");
  //eta_p0d_win_rec0->Draw("same LP");
  //eta_p0d_wout_rec0->Draw("same L");
  //pi0_p0d_win_rec0->Draw("same LP");
  //pi0_p0d_wout_rec0->Draw("same L");
  all_fgd12_rec0-> Draw("same L"); 
  //all_all_rec0->Draw("same L");
   
    
  //TLegend* leg = new TLegend(0.47,0.47,0.87,0.87);
  TLegend* leg = new TLegend(0.47,0.55,0.88,0.85);
  leg->SetBorderSize(0);
  leg->AddEntry(eta_fgd1_rec0,"#eta parent, FGD1","lp");
  leg->AddEntry(eta_fgd2_rec0,"#eta parent, FGD2","l");
  leg->AddEntry(pi0_fgd1_rec0,"#pi^{0} parent, FGD1","lp");
  leg->AddEntry(pi0_fgd2_rec0,"#pi^{0} parent, FGD2","l");
  //leg->AddEntry(eta_p0d_win_rec0,"#eta parent, P0D_win","lp");
  //leg->AddEntry(eta_p0d_wout_rec0,"#eta parent, P0D_wout","l");
  //leg->AddEntry(pi0_p0d_win_rec0,"#pi^{0} parent, P0D_win","lp");
  //leg->AddEntry(pi0_p0d_wout_rec0,"#pi^{0} parent, P0D_wout","l");
  leg->AddEntry(all_fgd12_rec0,"FGD1+FGD2","l");
  //leg->AddEntry(all_all_rec0,"All channels, FGD1+FGD2+P0D","l");
  leg->Draw();
  
  c->SaveAs("escater_events_fgd.png");
  
  //write results in root file 
  if(true){
     TFile f("graph_expected_ldm.root","update");
     eta_fgd1_rec0->Write();
     pi0_fgd1_rec0->Write();
     eta_fgd2_rec0->Write();
     pi0_fgd2_rec0->Write();
     //eta_p0d_win_rec0->Write();
     //eta_p0d_wout_rec0->Write();
     //pi0_p0d_win_rec0->Write();
     //pi0_p0d_wout_rec0->Write();
     all_fgd12_rec0->Write(); 
     all_all_rec0->Write();
     f.Close();
  }
}







