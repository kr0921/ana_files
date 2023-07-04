
char fdata0[] = "./nd280Highland2_v2r45_1_data.root";
//char fmc0[] = "./nd280Highland2_v2r45_1_MC.root";
char fmc0[] = "res/nd280Highland2_v2r45_1_data_run3b_air.root";

void DrawRelDiff(const char MyVar[], const char cut1[], const char title[],const char fdata[],const char descr_data[],const char fmc[],const char descr_mc[]){
    
//
int nbins = 100;
float hlow = -2.;
float hhigh = 2.;
//int nbins = 50;
//float hlow = -2000.;//-10000.;
//float hhigh = 2000.;//20000.;
    
////////////////////    
DrawingTools draw(fdata);
DataSample data(fdata);
DataSample mc(fmc);

draw.SetTitle(title);
draw.SetTitleX(MyVar);
draw.SetLegendPos("rt");
draw.SetLegendSize(0.15, 0.15);

TCanvas c;  
//draw.Draw(data,mc,MyVar,nbins,hlow,hhigh,"all",cut1,"", "AREA100");

draw.Draw(data,MyVar,nbins,hlow,hhigh,"all"/*"particle"*/,cut1,"", "AREA100");
auto h = draw.GetLastHisto();
h->SetLineColor(3);
h->SetLineWidth(4);
h->SetFillColor(3);
h->SetMarkerColor(3);
h->SetTitle(title);
h->SetName("Data");

draw.Draw(mc,MyVar,nbins,hlow,hhigh,"all"/*"particle"*/,cut1,"", "AREA100");
auto h_mc = draw.GetLastHisto();
h_mc->SetLineColor(2);
h_mc->SetFillColor(2);
h_mc->SetMarkerColor(2);
h_mc->SetTitle(title);
h_mc->SetName("MC");


double kstest = h->KolmogorovTest(h_mc,"X");
std::cout<<" KStest= "<<kstest<<std::endl;
TString str("KStest=");
std::stringstream ss;
std::string strf;
ss<<kstest;
ss>>strf;
str += strf;

TLatex latex;

c.Clear();
h->SetMaximum(h->GetMaximum()*1.4);
h->Draw("HIST");
h_mc->Draw("same");

latex.DrawLatex(-1.8,h->GetMaximum()*0.5,str.Data());

auto leg = new TLegend(0.1,0.7,0.38,0.9);
leg->AddEntry(h,descr_data,"f");
leg->AddEntry(h_mc,descr_mc,"lep");
leg->Draw();
c.Update();

c.SaveAs("000.pdf");
}







//////////////////////////////////
void myscript_tstability(int irul,const char f1[],const char descr1[]){
gStyle->SetStatX(0.6);	// Statistic box X
gStyle->SetStatY(0.9);	// Statistic box Y
gStyle->SetFillColor(10);   // Background color (white), for TLegends
    
TString myvar0("(last_tpc_mom-mom_p_range_tpc)/last_tpc_mom");
TString myvar1("(last_tpc_mom-mom_mu_range_tpc)/last_tpc_mom");
//
TString a0("");
TString basic_cut(" last_tpc_nnodes>18 && last_tpc_mom>0 && startpos[2]> -2000");
//TString accum_level("accum_level[0][0]>7");
TString dircut1(" && abs(last_fgd_dir[2])>0.6");
TString dircut2(" && abs(last_fgd_dir[2])<0.6");

gROOT->ProcessLine(".! rm report.pdf");


//   TString mycut = basic_cut+" && accum_level[0][0]>7";
//   DrawRelDiff(myvar0.Data(), mycut.Data(), "posFGD1, DATA",
//               "./nd280Highland2_v2r45_1_data.root","All runs","res/nd280Highland2_v2r45_1_data_run3b_air.root","data_run3b_air");
//   gROOT->ProcessLine(".! pdfunite 000.pdf report.pdf");
//return;

//////////


if(irul==0){
   char f0[] = "./nd280Highland2_v2r45_1_data.root";
   char descr0[] = "All runs";
    
   TString mycut = basic_cut+" && accum_level[0][0]>7";
   DrawRelDiff(myvar0.Data(), mycut.Data(), "posFGD1", f0, descr0, f1, descr1);
   gROOT->ProcessLine(".! pdfunite 000.pdf report.pdf");
   //
   TString mycut = basic_cut+" && accum_level[0][1]>7";
   DrawRelDiff(myvar0.Data(), mycut.Data(), "posFGD2", f0, descr0, f1, descr1);
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   //
   TString mycut = basic_cut+" && accum_level[0][2]>7";
   DrawRelDiff(myvar0.Data(), mycut.Data(), "posDsEcal", f0, descr0, f1, descr1);
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   //
   TString mycut = basic_cut+" && accum_level[0][3]>7";
   DrawRelDiff(myvar1.Data(), mycut.Data(), "negFGD1", f0, descr0, f1, descr1);
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   //
   TString mycut = basic_cut+" && accum_level[0][4]>6";
   DrawRelDiff(myvar1.Data(), mycut.Data(), "negFGD2", f0, descr0, f1, descr1);
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   //
   TString mycut = basic_cut+" && accum_level[0][5]>7";
   DrawRelDiff(myvar1.Data(), mycut.Data(), "negDsECal", f0, descr0, f1, descr1);
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   //
   TString mycut = basic_cut+" && accum_level[0][6]>7";
   DrawRelDiff(myvar1.Data(), mycut.Data(), "FGD1->ECal", f0, descr0, f1, descr1);
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   //
   TString mycut = basic_cut+" && accum_level[0][7]>7";
   DrawRelDiff(myvar1.Data(), mycut.Data(), "FGD1->ECal-SMRD", f0, descr0, f1, descr1);
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   //
   TString mycut = basic_cut+" && accum_level[0][8]>7";
   DrawRelDiff(myvar1.Data(), mycut.Data(), "FGD2->ECal", f0, descr0, f1, descr1);
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   //
   TString mycut = basic_cut+" && accum_level[0][9]>7";
   DrawRelDiff(myvar1.Data(), mycut.Data(), "FGD2->ECal-SMRD", f0, descr0, f1, descr1);
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");

    
} else if(irul==1) {
   char f0[] = "res/nd280Highland2_v2r45_1_data_beforeRun7.root";
   char descr0[] = "data before Run7";
    
   TString mycut = basic_cut+" && accum_level[0][0]>7";
   DrawRelDiff(myvar0.Data(), mycut.Data(), "posFGD1", f0, descr0, f1, descr1);
   gROOT->ProcessLine(".! pdfunite 000.pdf report.pdf");
   //
   TString mycut = basic_cut+" && accum_level[0][1]>7";
   DrawRelDiff(myvar0.Data(), mycut.Data(), "posFGD2", f0, descr0, f1, descr1);
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   //
   TString mycut = basic_cut+" && accum_level[0][2]>7";
   DrawRelDiff(myvar0.Data(), mycut.Data(), "posDsEcal", f0, descr0, f1, descr1);
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   //
   TString mycut = basic_cut+" && accum_level[0][3]>7";
   DrawRelDiff(myvar1.Data(), mycut.Data(), "negFGD1", f0, descr0, f1, descr1);
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   //
   TString mycut = basic_cut+" && accum_level[0][4]>6";
   DrawRelDiff(myvar1.Data(), mycut.Data(), "negFGD2", f0, descr0, f1, descr1);
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   //
   TString mycut = basic_cut+" && accum_level[0][5]>7";
   DrawRelDiff(myvar1.Data(), mycut.Data(), "negDsECal", f0, descr0, f1, descr1);
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   //
   TString mycut = basic_cut+" && accum_level[0][6]>7";
   DrawRelDiff(myvar1.Data(), mycut.Data(), "FGD1->ECal", f0, descr0, f1, descr1);
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   //
   TString mycut = basic_cut+" && accum_level[0][7]>7";
   DrawRelDiff(myvar1.Data(), mycut.Data(), "FGD1->ECal-SMRD", f0, descr0, f1, descr1);
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   //
   TString mycut = basic_cut+" && accum_level[0][8]>7";
   DrawRelDiff(myvar1.Data(), mycut.Data(), "FGD2->ECal", f0, descr0, f1, descr1);
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   //
   TString mycut = basic_cut+" && accum_level[0][9]>7";
   DrawRelDiff(myvar1.Data(), mycut.Data(), "FGD2->ECal-SMRD", f0, descr0, f1, descr1);
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");

    
} else if(irul==2) {
   char f0[] = "res/nd280Highland2_v2r45_1_mc_beforeRun7.root";
   char descr0[] = "MC before Run7";
    
   TString mycut = basic_cut+" && accum_level[0][0]>7";
   DrawRelDiff(myvar0.Data(), mycut.Data(), "posFGD1", f0, descr0, f1, descr1);
   gROOT->ProcessLine(".! pdfunite 000.pdf report.pdf");
   //
   TString mycut = basic_cut+" && accum_level[0][1]>7";
   DrawRelDiff(myvar0.Data(), mycut.Data(), "posFGD2", f0, descr0, f1, descr1);
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   //
   TString mycut = basic_cut+" && accum_level[0][2]>7";
   DrawRelDiff(myvar0.Data(), mycut.Data(), "posDsEcal", f0, descr0, f1, descr1);
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   //
   TString mycut = basic_cut+" && accum_level[0][3]>7";
   DrawRelDiff(myvar1.Data(), mycut.Data(), "negFGD1", f0, descr0, f1, descr1);
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   //
   TString mycut = basic_cut+" && accum_level[0][4]>6";
   DrawRelDiff(myvar1.Data(), mycut.Data(), "negFGD2", f0, descr0, f1, descr1);
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   //
   TString mycut = basic_cut+" && accum_level[0][5]>7";
   DrawRelDiff(myvar1.Data(), mycut.Data(), "negDsECal", f0, descr0, f1, descr1);
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   //
   TString mycut = basic_cut+" && accum_level[0][6]>7";
   DrawRelDiff(myvar1.Data(), mycut.Data(), "FGD1->ECal", f0, descr0, f1, descr1);
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   //
   TString mycut = basic_cut+" && accum_level[0][7]>7";
   DrawRelDiff(myvar1.Data(), mycut.Data(), "FGD1->ECal-SMRD", f0, descr0, f1, descr1);
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   //
   TString mycut = basic_cut+" && accum_level[0][8]>7";
   DrawRelDiff(myvar1.Data(), mycut.Data(), "FGD2->ECal", f0, descr0, f1, descr1);
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   //
   TString mycut = basic_cut+" && accum_level[0][9]>7";
   DrawRelDiff(myvar1.Data(), mycut.Data(), "FGD2->ECal-SMRD", f0, descr0, f1, descr1);
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");

    
}

/*
   TString mycut = basic_cut+dircut1+" && accum_level[0][0]>7";
   DrawRelDiff(myvar0.Data(), mycut.Data(), "posFGD1, cos#theta>0.6");
   gROOT->ProcessLine(".! pdfunite 000.pdf report.pdf");
   //
   TString mycut = basic_cut+dircut1+" && accum_level[0][1]>7";
   DrawRelDiff(myvar0.Data(), mycut.Data(), "posFGD2, cos#theta>0.6");
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   //
   TString mycut = basic_cut+dircut1+" && accum_level[0][2]>7";
   DrawRelDiff(myvar0.Data(), mycut.Data(), "posDsEcal, cos#theta>0.6");
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   //
   TString mycut = basic_cut+dircut1+" && accum_level[0][3]>7";
   DrawRelDiff(myvar1.Data(), mycut.Data(), "negFGD1, cos#theta>0.6");
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   //
   TString mycut = basic_cut+dircut1+" && accum_level[0][4]>6";
   DrawRelDiff(myvar1.Data(), mycut.Data(), "negFGD2, cos#theta>0.6");
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   //
   TString mycut = basic_cut+dircut1+" && accum_level[0][5]>7";
   DrawRelDiff(myvar1.Data(), mycut.Data(), "negDsECal, cos#theta>0.6");
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   //
   TString mycut = basic_cut+dircut1+" && accum_level[0][6]>7";
   DrawRelDiff(myvar1.Data(), mycut.Data(), "FGD1->ECal, cos#theta>0.6");
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   //
   TString mycut = basic_cut+dircut1+" && accum_level[0][7]>7";
   DrawRelDiff(myvar1.Data(), mycut.Data(), "FGD1->ECal-SMRD, cos#theta>0.6");
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   //
   TString mycut = basic_cut+dircut1+" && accum_level[0][8]>7";
   DrawRelDiff(myvar1.Data(), mycut.Data(), "FGD2->ECal, cos#theta>0.6");
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   //
   TString mycut = basic_cut+dircut1+" && accum_level[0][9]>7";
   DrawRelDiff(myvar1.Data(), mycut.Data(), "FGD2->ECal-SMRD, cos#theta>0.6");
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");

    
} else if(irul==2) {
   TString mycut = basic_cut+dircut2+" && accum_level[0][0]>7";
   DrawRelDiff(myvar0.Data(), mycut.Data(), "posFGD1, |cos#theta<0.6|");
   gROOT->ProcessLine(".! pdfunite 000.pdf report.pdf");
   //
   TString mycut = basic_cut+dircut2+" && accum_level[0][1]>7";
   DrawRelDiff(myvar0.Data(), mycut.Data(), "posFGD2, |cos#theta<0.6|");
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   //
   TString mycut = basic_cut+dircut2+" && accum_level[0][2]>7";
   DrawRelDiff(myvar0.Data(), mycut.Data(), "posDsEcal, |cos#theta<0.6|");
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   //
   TString mycut = basic_cut+dircut2+" && accum_level[0][3]>7";
   DrawRelDiff(myvar1.Data(), mycut.Data(), "negFGD1, |cos#theta<0.6|");
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   //
   TString mycut = basic_cut+dircut2+" && accum_level[0][4]>6";
   DrawRelDiff(myvar1.Data(), mycut.Data(), "negFGD2, |cos#theta<0.6|");
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   //
   TString mycut = basic_cut+dircut2+" && accum_level[0][5]>7";
   DrawRelDiff(myvar1.Data(), mycut.Data(), "negDsECal, |cos#theta<0.6|");
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   //
   TString mycut = basic_cut+dircut2+" && accum_level[0][6]>7";
   DrawRelDiff(myvar1.Data(), mycut.Data(), "FGD1->ECal, |cos#theta<0.6|");
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   //
   TString mycut = basic_cut+dircut2+" && accum_level[0][7]>7";
   DrawRelDiff(myvar1.Data(), mycut.Data(), "FGD1->ECal-SMRD, |cos#theta<0.6|");
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   //
   TString mycut = basic_cut+dircut2+" && accum_level[0][8]>7";
   DrawRelDiff(myvar1.Data(), mycut.Data(), "FGD2->ECal, |cos#theta<0.6|");
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   //
   TString mycut = basic_cut+dircut2+" && accum_level[0][9]>7";
   DrawRelDiff(myvar1.Data(), mycut.Data(), "FGD2->ECal-SMRD, |cos#theta<0.6|");
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
}
*/
}













