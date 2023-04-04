/*{
//char myfile[] = "fgd1_pi0_decay_prerun7geom.root";
char myfile[] = "files_iter0/nd280Highland2_v2r45_1_MC_allruns_fgd1.root";
//char myfile[] = "files_iter0/DPhoton_Production_BdNMC_Oct_2020_Pi0_decay_parent_FGD1.root";

  DrawingTools draw(myfile);
  DataSample mc(myfile);
  draw.SetOptStat("emri");
  
  draw.Draw(mc,"selelec_mom-selelec_true_mom",1000,-3000,3000,"particle","accum_level[0]>0 && particle==11","",""); 
    
}*/

TProfile* validation_plots0(const char myfile[]){

  auto file = new TFile(myfile);
  TTree* t;
  file->GetObject("default",t);
    
  auto ph = new TProfile("p","p",50,0,5000);   
  t->Draw("(selelec_mom-selelec_true_mom)/selelec_true_mom:selelec_true_mom>>p","accum_level[0]>13 && particle==11");
  return ph;
}

void validation_plots_fgd1(){
  //char myfile[] = "fgd1_pi0_decay_prerun7geom.root";
  //char myfile[] = "files_iter0/nd280Highland2_v2r45_1_MC_allruns_fgd1.root";
  //char myfile[] = "files_iter0/DPhoton_Production_BdNMC_Oct_2020_Pi0_decay_parent_FGD1.root";

  auto p1=validation_plots0("fgd1_pi0_decay_prerun7geom.root");
  p1->SetLineColor(2);

  auto p2=validation_plots0("files_iter0/nd280Highland2_v2r45_1_MC_allruns_fgd1.root");
  p2->SetLineColor(3);

  auto p3=validation_plots0("files_iter0/DPhoton_Production_BdNMC_Oct_2020_Pi0_decay_parent_FGD1.root");
  p3->SetLineColor(4);

  //auto p4=validation_plots0("files_iter0/production006B_mcp_anti-genie_2010-11-air_magnet_run2456_anal_fgd1.root");
  //p4->SetLineColor(7);

  gStyle->SetOptStat(0000000);  
  auto c = new TCanvas();
  //c->SetLogx();
  //c->SetLogy();
  TH1F *hfr = c->DrawFrame(0.,-1.,5000,1);
  hfr->SetYTitle("< (selelec_mom-selelec_true_mom)/selelec_true_mom >");
  hfr->SetXTitle("selelec_true_mom, MeV");
  hfr->SetTitle("accum_level[0]>13 && particle==11");
  //hfr->SetTitle("T2K sensetivity to LDM");
  //hfr->SetTitle("e #chi -> e #chi,   m_{V}=3m_{#chi},      #alpha_{D}=0.5");  //,     #epsilon=0.001");
  
  p1->Draw("same");
  p2->Draw("same");
  p3->Draw("same");
  //p4->Draw("same");

  TLegend* leg = new TLegend(0.19,0.59,0.54,0.84);
  leg->SetBorderSize(0);
  leg->SetHeader("FGD1");
  leg->AddEntry(p1,"BDNMC new","lp");
  leg->AddEntry(p3,"BDNMC old","lp");
  leg->AddEntry(p2,"NEUT","lp");
  leg->Draw();
  
  c->SaveAs("selelec_mom_fgd1.png");
}

void validation_plots_fgd2(){
  //char myfile[] = "fgd1_pi0_decay_prerun7geom.root";
  //char myfile[] = "files_iter0/nd280Highland2_v2r45_1_MC_allruns_fgd1.root";
  //char myfile[] = "files_iter0/DPhoton_Production_BdNMC_Oct_2020_Pi0_decay_parent_FGD1.root";

  auto p1=validation_plots0("fgd2_pi0_decay_prerun7geom.root");
  p1->SetLineColor(2);

  auto p2=validation_plots0("files_iter0/nd280Highland2_v2r45_1_MC_allruns_fgd2.root");
  p2->SetLineColor(3);

  auto p3=validation_plots0("files_iter0/DPhoton_Production_BdNMC_Oct_2020_Pi0_decay_parent_FGD2.root");
  p3->SetLineColor(4);

  //auto p4=validation_plots0("files_iter0/production006B_mcp_anti-genie_2010-11-air_magnet_run2456_anal_fgd1.root");
  //p4->SetLineColor(7);

  gStyle->SetOptStat(0000000);  
  auto c = new TCanvas();
  //c->SetLogx();
  //c->SetLogy();
  TH1F *hfr = c->DrawFrame(0.,-1.,5000,1);
  hfr->SetYTitle("< (selelec_mom-selelec_true_mom)/selelec_true_mom >");
  hfr->SetXTitle("selelec_true_mom, MeV");
  hfr->SetTitle("accum_level[0]>13 && particle==11");
  //hfr->SetTitle("e #chi -> e #chi,   m_{V}=3m_{#chi},      #alpha_{D}=0.5");  //,     #epsilon=0.001");
  
  p1->Draw("same");
  p2->Draw("same");
  p3->Draw("same");
  //p4->Draw("same");

  TLegend* leg = new TLegend(0.19,0.59,0.54,0.84);
  leg->SetBorderSize(0);
  leg->SetHeader("FGD2");
  leg->AddEntry(p1,"BDNMC new","lp");
  leg->AddEntry(p3,"BDNMC old","lp");
  leg->AddEntry(p2,"NEUT","lp");
  leg->Draw();
  
  c->SaveAs("selelec_mom_fgd2.png");
}

///////////////////////////////////
void validation_plots(){
   validation_plots_fgd1(); 
   validation_plots_fgd2(); 
}

