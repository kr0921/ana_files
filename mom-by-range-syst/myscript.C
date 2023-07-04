
//PROD7
//char DataFile[]="res_prod7/run4_data.root";
//char MCFile[]="res_prod7/run4_mc.root";
//char reldif_mu[]="(last_tpc_mom-mom_mu_range_tpc_rp)/last_tpc_mom";
//char reldif_p[]="(last_tpc_mom-mom_p_range_tpc_rp)/last_tpc_mom";
//PROD6
char DataFile[]="res_prod6/nd280Highland2_v2r45_1_data_run4_air.root";
char MCFile[]="res_prod6/nd280Highland2_v2r45_1_MC_run4air.root";
char reldif_mu[]="(last_tpc_mom-mom_mu_range_tpc)/last_tpc_mom";
char reldif_p[]="(last_tpc_mom-mom_p_range_tpc)/last_tpc_mom";


void DrawRelDiff(const char MyVar[], const char cut1[], const char title[]){
    
//
int nbins = 100;
float hlow = -2.;
float hhigh = 2.;
//int nbins = 50;
//float hlow = -2000.;//-10000.;
//float hhigh = 2000.;//20000.;
    
////////////////////    
DrawingTools draw(DataFile);
DataSample data(DataFile);
DataSample mc(MCFile);

draw.SetTitle(title);
draw.SetTitleX(MyVar);
draw.SetLegendPos("rt");
draw.SetLegendSize(0.15, 0.15);

TCanvas c;  
draw.Draw(data,mc,MyVar,nbins,hlow,hhigh,"particle",cut1,"", "AREA100");
c.SaveAs("000.pdf");
}

void DrawTpcMom(const char cut1[], const char title[]){

int nbins = 40;
float hlow = 0.;
float hhigh = 2000.;
    
////////////////////    
DrawingTools draw(DataFile);
DataSample data(DataFile);
DataSample mc(MCFile);

draw.SetTitle(title);
draw.SetTitleX("last_tpc_mom");
draw.SetLegendPos("rt");
draw.SetLegendSize(0.15, 0.15);

TCanvas c;  
draw.Draw(data,mc,"last_tpc_mom",nbins,hlow,hhigh,"particle",cut1,"", "AREA100");
c.SaveAs("000.pdf");
}

void DrawDir(const char cut1[], const char title[]){

int nbins = 20;
float hlow = -1.;
float hhigh = 1.;
    
////////////////////    
DrawingTools draw(DataFile);
DataSample data(DataFile);
DataSample mc(MCFile);

draw.SetTitle(title);
draw.SetTitleX("last_fgd_dir[2]");
draw.SetLegendPos("lt");
draw.SetLegendSize(0.15, 0.15);

TCanvas c;  
draw.Draw(data,mc,"last_fgd_dir[2]",nbins,hlow,hhigh,"particle",cut1,"", "AREA100");
c.SaveAs("000.pdf");
}







//////////////////////////////////
void myscript(int irul){
gStyle->SetStatX(0.6);	// Statistic box X
gStyle->SetStatY(0.9);	// Statistic box Y
gStyle->SetFillColor(10);   // Background color (white), for TLegends
    
TString myvar0(reldif_p);
TString myvar1(reldif_mu);
//
TString a0("");
TString basic_cut(" last_tpc_nnodes>18 && last_tpc_mom>0 && startpos[2]> -2000");
//TString accum_level("accum_level[0][0]>7");
TString dircut1(" && abs(last_fgd_dir[2])>0.6");
TString dircut2(" && abs(last_fgd_dir[2])<0.6");


TString posfgd1(" && accum_level[0][0]>7 && last_tpc_mom>350 && last_tpc_mom<700");
TString posfgd2(" && accum_level[0][1]>7 && last_tpc_mom>350 && last_tpc_mom<700");
TString posdsecal(" && accum_level[0][2]>7 && last_tpc_mom>450 && last_tpc_mom<800");
TString negfgd1(" && accum_level[0][3]>7 && last_tpc_mom>50 && last_tpc_mom<250");
TString negfgd2(" && accum_level[0][4]>6 && last_tpc_mom>50 && last_tpc_mom<250");
TString negdsecal(" && accum_level[0][5]>7 && last_tpc_mom>100 && last_tpc_mom<300");
TString negfgd1ecal(" && accum_level[0][6]>7 && last_tpc_mom>250 && last_tpc_mom<500");
TString negfgd1smrd(" && accum_level[0][7]>7 && last_tpc_mom>500 && last_tpc_mom<1200");
TString negfgd2ecal(" && accum_level[0][8]>7 && last_tpc_mom>200 && last_tpc_mom<450");
TString negfgd2smrd(" && accum_level[0][9]>7 && last_tpc_mom>400 && last_tpc_mom<900");
//

//TString v0("(0.7932*last_tpc_mom+99.41-mom_p_range_tpc)/(0.7932*last_tpc_mom+99.41)");  //0.7932*last_tpc_mom+99.41
//TString v1("(0.6794*last_tpc_mom+162.6-mom_p_range_tpc)/(0.6794*last_tpc_mom+162.6)");  //0.6794*last_tpc_mom+162.6
//TString v2("(0.8685*last_tpc_mom+104.4-mom_p_range_tpc)/(0.8685*last_tpc_mom+104.4)");  //0.8685*last_tpc_mom+104.4
//TString v3("(0.755*last_tpc_mom+43.27-mom_mu_range_tpc)/(0.755*last_tpc_mom+43.27)");  //0.755*last_tpc_mom+43.27
//TString v4("(0.6374*last_tpc_mom+58.39-mom_mu_range_tpc)/(0.6374*last_tpc_mom+58.39)");  //0.6374*last_tpc_mom+58.39   negfgd2
//TString v5("(0.8499*last_tpc_mom+43.52-mom_mu_range_tpc)/(0.8499*last_tpc_mom+43.52)");  //0.8499*last_tpc_mom+43.52   negDsECal
//TString v6("(0.8633*last_tpc_mom+22.45-mom_mu_range_tpc)/(0.8633*last_tpc_mom+22.45)");  //0.8633*last_tpc_mom+22.45   FGD1->ECal
//TString v7("(0.8824*last_tpc_mom+96.74-mom_mu_range_tpc)/(0.8824*last_tpc_mom+96.74)");  //0.8824*last_tpc_mom+96.74   FGD1->ECal-SMRD
//TString v8("(0.8622*last_tpc_mom+18.55-mom_mu_range_tpc)/(0.8622*last_tpc_mom+18.55)");  //0.8622*last_tpc_mom+18.55   FGD2->ECal
//TString v9("(0.7075*last_tpc_mom+198.3-mom_mu_range_tpc)/(0.7075*last_tpc_mom+198.3)");  //0.7075*last_tpc_mom+198.3   FGD2->ECal-SMRD





gROOT->ProcessLine(".! rm report.pdf");




//////////
if(irul==-2){
   TString mycut = basic_cut+" && accum_level[0][0]>7"; // && last_tpc_mom>350 && last_tpc_mom<700";
   DrawDir(mycut.Data(), "posFGD1");
   gROOT->ProcessLine(".! pdfunite 000.pdf report.pdf");
   //
   TString mycut = basic_cut+" && accum_level[0][1]>7"; // && last_tpc_mom>350 && last_tpc_mom<700";
   DrawDir(mycut.Data(), "posFGD2");
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   //
   TString mycut = basic_cut+" && accum_level[0][2]>7"; // && last_tpc_mom>350 && last_tpc_mom<700";
   DrawDir(mycut.Data(), "posDsEcal");
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   //
   TString mycut = basic_cut+" && accum_level[0][3]>7"; // && last_tpc_mom>350 && last_tpc_mom<700";
   DrawDir(mycut.Data(), "negFGD1");
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   //
   TString mycut = basic_cut+" && accum_level[0][4]>6"; // && last_tpc_mom>350 && last_tpc_mom<700";
   DrawDir(mycut.Data(), "negFGD2");
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   //
   TString mycut = basic_cut+" && accum_level[0][5]>7"; // && last_tpc_mom>350 && last_tpc_mom<700";
   DrawDir(mycut.Data(), "negDsECal");
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   //
   TString mycut = basic_cut+" && accum_level[0][6]>7"; // && last_tpc_mom>350 && last_tpc_mom<700";
   DrawDir(mycut.Data(), "FGD1->ECal");
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   //
   TString mycut = basic_cut+" && accum_level[0][7]>7"; // && last_tpc_mom>350 && last_tpc_mom<700";
   DrawDir(mycut.Data(), "FGD1->ECal-SMRD");
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   //
   TString mycut = basic_cut+" && accum_level[0][8]>7"; // && last_tpc_mom>350 && last_tpc_mom<700";
   DrawDir(mycut.Data(), "FGD2->ECal");
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   //
   TString mycut = basic_cut+" && accum_level[0][9]>7"; // && last_tpc_mom>350 && last_tpc_mom<700";
   DrawDir(mycut.Data(), "FGD2->ECal-SMRD");
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
}

if(irul==-1){
   TString mycut = basic_cut+" && accum_level[0][0]>7";
   DrawTpcMom(mycut.Data(), "posFGD1");
   gROOT->ProcessLine(".! pdfunite 000.pdf report.pdf");
   //
   TString mycut = basic_cut+" && accum_level[0][1]>7";
   DrawTpcMom(mycut.Data(), "posFGD2");
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   //
   TString mycut = basic_cut+" && accum_level[0][2]>7";
   DrawTpcMom(mycut.Data(), "posDsEcal");
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   //
   TString mycut = basic_cut+" && accum_level[0][3]>7";
   DrawTpcMom(mycut.Data(), "negFGD1");
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   //
   TString mycut = basic_cut+" && accum_level[0][4]>6";
   DrawTpcMom(mycut.Data(), "negFGD2");
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   //
   TString mycut = basic_cut+" && accum_level[0][5]>7";
   DrawTpcMom(mycut.Data(), "negDsECal");
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   //
   TString mycut = basic_cut+" && accum_level[0][6]>7";
   DrawTpcMom(mycut.Data(), "FGD1->ECal");
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   //
   TString mycut = basic_cut+" && accum_level[0][7]>7";
   DrawTpcMom(mycut.Data(), "FGD1->ECal-SMRD");
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   //
   TString mycut = basic_cut+" && accum_level[0][8]>7";
   DrawTpcMom(mycut.Data(), "FGD2->ECal");
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   //
   TString mycut = basic_cut+" && accum_level[0][9]>7";
   DrawTpcMom(mycut.Data(), "FGD2->ECal-SMRD");
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
}


if(irul==0){
   TString mycut = basic_cut+posfgd1;
   DrawRelDiff(myvar0.Data(), mycut.Data(), "posFGD1");
   //DrawRelDiff(v0.Data(), mycut.Data(), "posFGD1");
   gROOT->ProcessLine(".! pdfunite 000.pdf report.pdf");
   //
   TString mycut = basic_cut+posfgd2;
   DrawRelDiff(myvar0.Data(), mycut.Data(), "posFGD2");
   //DrawRelDiff(v1.Data(), mycut.Data(), "posFGD2");
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   //
   TString mycut = basic_cut+posdsecal;
   DrawRelDiff(myvar0.Data(), mycut.Data(), "posDsEcal");
   //DrawRelDiff(v2.Data(), mycut.Data(), "posDsEcal");
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   //
   TString mycut = basic_cut+negfgd1;
   DrawRelDiff(myvar1.Data(), mycut.Data(), "negFGD1");
   //DrawRelDiff(v3.Data(), mycut.Data(), "negFGD1");
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   //
   TString mycut = basic_cut+negfgd2;
   DrawRelDiff(myvar1.Data(), mycut.Data(), "negFGD2");
   //DrawRelDiff(v4.Data(), mycut.Data(), "negFGD2");
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   //
   TString mycut = basic_cut+negdsecal;
   DrawRelDiff(myvar1.Data(), mycut.Data(), "negDsECal");
   //DrawRelDiff(v5.Data(), mycut.Data(), "negDsECal");
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   //
   TString mycut = basic_cut+negfgd1ecal;
   DrawRelDiff(myvar1.Data(), mycut.Data(), "FGD1->ECal");
   //DrawRelDiff(v6.Data(), mycut.Data(), "FGD1->ECal");
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   //
   TString mycut = basic_cut+negfgd1smrd;
   DrawRelDiff(myvar1.Data(), mycut.Data(), "FGD1->ECal-SMRD");
   //DrawRelDiff(v7.Data(), mycut.Data(), "FGD1->ECal-SMRD");
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   //
   TString mycut = basic_cut+negfgd2ecal;
   DrawRelDiff(myvar1.Data(), mycut.Data(), "FGD2->ECal");
   //DrawRelDiff(v8.Data(), mycut.Data(), "FGD2->ECal");
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   //
   TString mycut = basic_cut+negfgd2smrd;
   DrawRelDiff(myvar1.Data(), mycut.Data(), "FGD2->ECal-SMRD");
   //DrawRelDiff(v9.Data(), mycut.Data(), "FGD2->ECal-SMRD");
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");

    
} else if(irul==1) {
   TString mycut = basic_cut+dircut1+posfgd1;
   DrawRelDiff(myvar0.Data(), mycut.Data(), "posFGD1, cos#theta>0.6");
   gROOT->ProcessLine(".! pdfunite 000.pdf report.pdf");
   //
   TString mycut = basic_cut+dircut1+posfgd2;
   DrawRelDiff(myvar0.Data(), mycut.Data(), "posFGD2, cos#theta>0.6");
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   //
   TString mycut = basic_cut+dircut1+posdsecal;
   DrawRelDiff(myvar0.Data(), mycut.Data(), "posDsEcal, cos#theta>0.6");
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   //
   TString mycut = basic_cut+dircut1+negfgd1;
   DrawRelDiff(myvar1.Data(), mycut.Data(), "negFGD1, cos#theta>0.6");
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   //
   TString mycut = basic_cut+dircut1+negfgd2;
   DrawRelDiff(myvar1.Data(), mycut.Data(), "negFGD2, cos#theta>0.6");
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   //
   TString mycut = basic_cut+dircut1+negdsecal;
   DrawRelDiff(myvar1.Data(), mycut.Data(), "negDsECal, cos#theta>0.6");
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   //
   TString mycut = basic_cut+dircut1+negfgd1ecal;
   DrawRelDiff(myvar1.Data(), mycut.Data(), "FGD1->ECal, cos#theta>0.6");
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   //
   TString mycut = basic_cut+dircut1+negfgd1smrd;
   DrawRelDiff(myvar1.Data(), mycut.Data(), "FGD1->ECal-SMRD, cos#theta>0.6");
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   //
   TString mycut = basic_cut+dircut1+negfgd2ecal;
   DrawRelDiff(myvar1.Data(), mycut.Data(), "FGD2->ECal, cos#theta>0.6");
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   //
   TString mycut = basic_cut+dircut1+negfgd2smrd;
   DrawRelDiff(myvar1.Data(), mycut.Data(), "FGD2->ECal-SMRD, cos#theta>0.6");
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");

    
} else if(irul==2) {
   TString mycut = basic_cut+dircut2+posfgd1;
   DrawRelDiff(myvar0.Data(), mycut.Data(), "posFGD1, |cos#theta<0.6|");
   //DrawRelDiff(v0.Data(), mycut.Data(), "posFGD1, |cos#theta<0.6|");
   gROOT->ProcessLine(".! pdfunite 000.pdf report.pdf");
   //
   TString mycut = basic_cut+dircut2+posfgd2;
   DrawRelDiff(myvar0.Data(), mycut.Data(), "posFGD2, |cos#theta<0.6|");
   //DrawRelDiff(v1.Data(), mycut.Data(), "posFGD2, |cos#theta<0.6|");
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   //
   TString mycut = basic_cut+dircut2+posdsecal;
   DrawRelDiff(myvar0.Data(), mycut.Data(), "posDsEcal, |cos#theta<0.6|");
   //DrawRelDiff(v2.Data(), mycut.Data(), "posDsEcal, |cos#theta<0.6|");
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   //
   TString mycut = basic_cut+dircut2+negfgd1;
   DrawRelDiff(myvar1.Data(), mycut.Data(), "negFGD1, |cos#theta<0.6|");
   //DrawRelDiff(v3.Data(), mycut.Data(), "negFGD1, |cos#theta<0.6|");
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   //
   TString mycut = basic_cut+dircut2+negfgd2;
   DrawRelDiff(myvar1.Data(), mycut.Data(), "negFGD2, |cos#theta<0.6|");
   //DrawRelDiff(v4.Data(), mycut.Data(), "negFGD2, |cos#theta<0.6|");
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   //
   TString mycut = basic_cut+dircut2+negdsecal;
   DrawRelDiff(myvar1.Data(), mycut.Data(), "negDsECal, |cos#theta<0.6|");
   //DrawRelDiff(v5.Data(), mycut.Data(), "negDsECal, |cos#theta<0.6|");
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   //
   TString mycut = basic_cut+dircut2+negfgd1ecal;
   DrawRelDiff(myvar1.Data(), mycut.Data(), "FGD1->ECal, |cos#theta<0.6|");
   //DrawRelDiff(v6.Data(), mycut.Data(), "FGD1->ECal, |cos#theta<0.6|");
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   //
   TString mycut = basic_cut+dircut2+negfgd1smrd;
   DrawRelDiff(myvar1.Data(), mycut.Data(), "FGD1->ECal-SMRD, |cos#theta<0.6|");
   //DrawRelDiff(v7.Data(), mycut.Data(), "FGD1->ECal-SMRD, |cos#theta<0.6|");
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   //
   TString mycut = basic_cut+dircut2+negfgd2ecal;
   DrawRelDiff(myvar1.Data(), mycut.Data(), "FGD2->ECal, |cos#theta<0.6|");
   //DrawRelDiff(v8.Data(), mycut.Data(), "FGD2->ECal, |cos#theta<0.6|");
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   //
   TString mycut = basic_cut+dircut2+negfgd2smrd;
   DrawRelDiff(myvar1.Data(), mycut.Data(), "FGD2->ECal-SMRD, |cos#theta<0.6|");
   //DrawRelDiff(v9.Data(), mycut.Data(), "FGD2->ECal-SMRD, |cos#theta<0.6|");
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
}
}













