
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



void escater_pele_fgd(){
 auto f1 = new TFile("fgd1_pi0_decay_prerun7geom.root");
 TTree* truth;
 f1->GetObject("truth",truth);
 
 TH1D* h1 = new TH1D("h1","",100,0,5000); 
 truth->Draw("truelepton_mom>>h1","ldm_Mv<0.101 && ldm_Mv>0.099");
 h1->Scale(1./h1->Integral());
 h1->SetLineColor(2);
 h1->SetLineWidth(4);
 
 TH1D* h2 = new TH1D("h2","",100,0,5000); 
 truth->Draw("truelepton_mom>>h2","ldm_Mv<0.0201 && ldm_Mv>0.0199");
 h2->Scale(1./h2->Integral());
 h2->SetLineColor(4);
 h2->SetLineWidth(4);
 
 TH1D* h3 = new TH1D("h3","",100,0,5000); 
 truth->Draw("truelepton_mom>>h3","ldm_Mv<0.0501 && ldm_Mv>0.0499");
 h3->Scale(1./h3->Integral());
 h3->SetLineColor(3);
 h3->SetLineWidth(4);
 
 
 
 
//////////////////////////////////
 
   mygStyleSetup();
 
   auto c_fgd = new TCanvas();
   TH1F *hfr = c_fgd->DrawFrame(0.,0.0,2500.,0.25);
   //hfr->SetYTitle("#events/1.8e+21 POT");
   hfr->SetXTitle("p_{e}, MeV/c");
   hfr->SetTitle("e #chi -> e #chi,   m_{V}=3m_{#chi},      #alpha_{D}=0.5,     #epsilon=0.001");
   
 h2->Draw("same hist");
 h3->Draw("same hist");
 h1->Draw("same hist");
 
 
  TLegend* leg = new TLegend(0.53,0.55,0.74,0.78);
  leg->SetBorderSize(0);
  //leg->SetHeader("m_{V}=0.1 GeV");
  leg->AddEntry(h1,"m_{V}=0.1 GeV","l");
  leg->AddEntry(h3,"m_{V}=0.05 GeV","l");
  leg->AddEntry(h2,"m_{V}=0.02 GeV","l");
  leg->Draw();
 
  c_fgd->SaveAs("escater_pele_fgd.png");
}






