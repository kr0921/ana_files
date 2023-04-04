
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
  draw.SetTitle("truth, accum_level[0]>14/13(FGD/P0D):accum_level[0]>0");
  draw.SetTitleX("selelec_true_mom, MeV");
  draw.SetTitleY("Eff");
  //draw.SetLineColor(2);


  //DataSample fgd2("res/DPhoton_Production_BdNMC_Oct_2020_Eta_decay_parent_FGD2.root");
  
  
  //draw.DrawEff(default,"selelec_true_mom",50,0.,5000.,nominator_cut/*"accum_level[0]>13"*/,"accum_level[0]>11 && particle==11","","","ughiuhui");
  draw.DrawEff(truth,"truelepton_mom",50,0.,5000.,/*nominator_cut*/"accum_level[0]>14 && particle==11"*/,"accum_level[0]>0 && particle==11","","","ughiuhui");

  auto h = draw.GetLastGraph();
  h->SetLineColor(color);
  h->SetMarkerColor(color);
//  h->Dump();
//  h->Draw();
  return (TGraphAsymmErrors*)h->Clone(hname);
}


void myEff_ldm_samples_validation_default(){

    auto fgd1 = getEffs("./fgd2_pi0_decay_prerun7geom.root","fgd1_pi0","accum_level[0]>12 && particle==11",2);
    auto fgd2 = getEffs("files_iter0/DPhoton_Production_BdNMC_Oct_2020_Pi0_decay_parent_FGD2.root","fgd2_pi0","accum_level[0]>12 && particle==11",3);
    auto fgd3 = getEffs("files_iter0/nd280Highland2_v2r45_1_MC_allruns_fgd2.root","fgd3_pi0","accum_level[0]>12 && particle==11",6);
    
    fgd2->SetTitle("default, accum_level[0]>12:accum_level[0]>11, particle=11");
  
    //mygStyleSetup();
    auto c = new TCanvas();
    //fgd1_eta->SetMaximum(0.5);
    //fgd1_eta->Draw();
    //fgd2_eta->Draw("plsame");
    fgd2->Draw();
    fgd1->Draw("plsame");
    fgd3->Draw("plsame");

    
    TLegend* leg = new TLegend(0.44,0.16,0.81,0.46);     
    //leg->SetBorderSize(0);
    leg->SetHeader("FGD2");                            
    leg->AddEntry(fgd1,"BDNMC new","lep");
    leg->AddEntry(fgd2,"BDNMC old","lep");
    leg->AddEntry(fgd3,"NEUT","lep");
    leg->Draw();
    
    c->SaveAs("effs_fgd2_default11-12.png");
    
        
}

void myEff_ldm_samples_validation(){

    auto fgd1 = getEffs("./fgd1_pi0_decay_prerun7geom.root","fgd1_pi0","accum_level[0]>14 && particle==11",2);
    auto fgd2 = getEffs("files_iter0/DPhoton_Production_BdNMC_Oct_2020_Pi0_decay_parent_FGD1.root","fgd2_pi0","accum_level[0]>14 && particle==11",3);
    auto fgd3 = getEffs("files_iter0/nd280Highland2_v2r45_1_MC_allruns_fgd1.root","fgd3_pi0","accum_level[0]>14 && particle==11",6);
    
    fgd2->SetTitle("true, accum_level[0]>14:accum_level[0]>0, particle=11");
  
    //mygStyleSetup();
    auto c = new TCanvas();
    //fgd1_eta->SetMaximum(0.5);
    //fgd1_eta->Draw();
    //fgd2_eta->Draw("plsame");
    fgd2->Draw();
    fgd1->Draw("plsame");
    fgd3->Draw("plsame");

    
    TLegend* leg = new TLegend(0.44,0.16,0.81,0.46);     
    //leg->SetBorderSize(0);
    leg->SetHeader("FGD1");                            
    leg->AddEntry(fgd1,"BDNMC new","lep");
    leg->AddEntry(fgd2,"BDNMC old","lep");
    leg->AddEntry(fgd3,"NEUT","lep");
    leg->Draw();
    
    //c->SaveAs("effs_fgd1_true0-14.png");
    
        
}


