
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



TGraphAsymmErrors* getEffs(const char* myfile, const char* hname, const char* nominator_cut, int color=1){
 //char myfile1[] = "res/DPhoton_Production_BdNMC_Oct_2020_Eta_decay_parent_FGD1.root";
    
  DrawingTools draw(myfile);
  DataSample mc(myfile);
  //draw.SetTitle("default, accum_level[0]>14/13(FGD/P0D):accum_level[0]>0");
  //draw.SetTitle("truth, accum_level[0]>14/13(FGD/P0D):accum_level[0]>0");
  draw.SetTitleX("ldm_Mv, GeV");
  draw.SetTitleY("Eff");
  //draw.SetLineColor(2);


  //DataSample fgd2("res/DPhoton_Production_BdNMC_Oct_2020_Eta_decay_parent_FGD2.root");
  
  
  draw.DrawEff(/*default*/truth,"ldm_Mv",1000,0.,0.6,nominator_cut/*"accum_level[0]>13"*/,"accum_level[0]>0","","","ughiuhui");
  //draw.DrawEff(/*default*/truth,"truelepton_mom",50,0.,5000.,nominator_cut/*"accum_level[0]>13"*/,"accum_level[0]>0","","","ughiuhui");

  auto h = draw.GetLastGraph();
  h->SetLineColor(color);
  h->SetMarkerColor(color);
//  h->Dump();
//  h->Draw();
  return (TGraphAsymmErrors*)h->Clone(hname);
}


void myEff_ldm_samples(){
    //gStyle->SetMarkerColor(3);
    
    
    
    auto fgd1_eta = getEffs("./fgd1_eta_decay_prerun7geom.root","fgd1_eta","accum_level[0]>14",2);
    auto fgd2_eta = getEffs("./fgd2_eta_decay_prerun7geom.root","fgd2_eta","accum_level[0]>14",4);
    auto fgd1_pi0 = getEffs("./fgd1_pi0_decay_prerun7geom.root","fgd1_pi0","accum_level[0]>14",3);
    auto fgd2_pi0 = getEffs("./fgd2_pi0_decay_prerun7geom.root","fgd2_pi0","accum_level[0]>14",6);

    //auto p0d_win_eta = getEffs("res/DPhoton_Production_BdNMC_Oct_2020_Eta_decay_parent_P0D_WaterIn.root","p0d_win_eta","accum_level[0]>13",7);
    //auto p0d_wout_eta = getEffs("res/DPhoton_Production_BdNMC_Oct_2020_Eta_decay_parent_P0D_WaterOut.root","p0d_wout_eta","accum_level[0]>13",8);
    //auto p0d_win_pi0 = getEffs("res/DPhoton_Production_BdNMC_Oct_2020_Pi0_decay_parent_P0D_WaterIn.root","p0d_win_pi0","accum_level[0]>13",9);
    //auto p0d_wout_pi0 = getEffs("res/DPhoton_Production_BdNMC_Oct_2020_Pi0_decay_parent_P0D_WaterOut.root","p0d_wout_pi0","accum_level[0]>13",11);
    
    //mygStyleSetup();
    auto c = new TCanvas();
    //fgd1_eta->SetMaximum(0.5);
    fgd1_eta->Draw();
    fgd2_eta->Draw("plsame");
    fgd1_pi0->Draw("plsame");
    fgd2_pi0->Draw("plsame");
    //p0d_win_eta->Draw("plsame");
    //p0d_wout_eta->Draw("plsame");
    //p0d_win_pi0->Draw("plsame");
    //p0d_wout_pi0->Draw("plsame");

    
    TLegend* leg = new TLegend(0.5,0.57,0.87,0.87);     
    //leg->SetBorderSize(0);
    //leg->SetHeader("tHjb events");                            
    leg->AddEntry(fgd1_eta,"#eta decay parent, FGD1","lep");
    leg->AddEntry(fgd2_eta,"#eta decay parent, FGD2","lep");
    leg->AddEntry(fgd1_pi0,"#pi^{0} decay parent, FGD1","lep");
    leg->AddEntry(fgd2_pi0,"#pi^{0} decay parent, FGD2","lep");
    
    //leg->AddEntry(p0d_win_eta,"#eta decay parent, P0D-wIn","lep");
    //leg->AddEntry(p0d_wout_eta,"#eta decay parent, P0D-wOut","lep");
    //leg->AddEntry(p0d_win_pi0,"#pi^{0} decay parent, P0D-wIn","lep");
    //leg->AddEntry(p0d_wout_pi0,"#pi^{0} decay parent, P0D-wOut","lep");
    leg->Draw();
    
    //c->SaveAs("effs_v2.png");
    
    
  TFile f("graph_expected_ldm.root","recreate"/*"update"*/);
  fgd1_eta->Write();
  fgd2_eta->Write();
  fgd1_pi0->Write();
  fgd2_pi0->Write();
  //p0d_win_eta->Write();
  //p0d_wout_eta->Write();
  //p0d_win_pi0->Write();
  //p0d_wout_pi0->Write();
  f.Close();  
    
    
    
}


