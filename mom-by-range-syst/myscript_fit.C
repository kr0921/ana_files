
//PROD7
char DataFile[]="res_prod7/run4_data.root";
char MCFile[]="res_prod7/run4_mc.root";
char reldif_mu[]="(last_tpc_mom-mom_mu_range_tpc_rp)/last_tpc_mom";
char reldif_p[]="(last_tpc_mom-mom_p_range_tpc_rp)/last_tpc_mom";
//PROD6
//char DataFile[]="res_prod6/nd280Highland2_v2r45_1_data_run4_air.root";
//char MCFile[]="res_prod6/nd280Highland2_v2r45_1_MC_run4air.root";
//char reldif_mu[]="(last_tpc_mom-mom_mu_range_tpc)/last_tpc_mom";
//char reldif_p[]="(last_tpc_mom-mom_p_range_tpc)/last_tpc_mom";



//void get_hist_interval(TH1F* h){
//    for(int ibin=1; ibin<=h_depo_w.GetNbinsX(); ibin++){
//       double yy = h_depo_w.GetBinContent(ibin);
//       if(yy > 0.20)h_depo_w.SetBinContent(ibin,0.20);
//    }
//    
//}




Double_t myfunction(Double_t *x, Double_t *par)
{
   //Float_t xx =x[0];
   //Double_t f = TMath::Abs(par[0]*sin(par[1]*xx)/xx);
    
    //Double_t f = TMath::exp(pow((x[0]-par[0])/par[1],2));//par[2]*exp((-0.5)*pow((x[0]-par[0])/par[1],2))* (1./sqrt(2.*TMath::Pi)*par[1]);
    
   Double_t f = 0.;
   if (x[0]<=par[0]){
       //f = par[3]*TMath::Gaus(x[0],par[0],par[1],false);
       Double_t d = TMath::Abs((x[0]-par[0])/par[1]);
       f = par[3]/(1+pow(d,2));
       //f = par[4]*TMath::Exp(-0.5*pow(d,par[3]));
   } else {
       //f = par[3]*TMath::Gaus(x[0],par[0],par[2],false);
       Double_t d = TMath::Abs((x[0]-par[0])/par[2]);
       f = par[3]/(1+pow(d,2));
       //f = par[4]*TMath::Exp(-0.5*pow(d,par[5]));
   }
   return f;
}


double minW68(TH1* h){
    double my_minw68 = 9999999.;
    double tots = h->Integral(1,h->GetNbinsX())+h->GetBinContent(0)+h->GetBinContent(h->GetNbinsX()+1);
    
    for(int i=1; i<=h->GetNbinsX(); i++){
        if((h->Integral(i,h->GetNbinsX())+h->GetBinContent(h->GetNbinsX()+1))/tots<0.69)break;
        
        int ii1=i+1;
        int ii2=h->GetNbinsX();
        while(ii2-ii1 >= 2 ){
          int ix=(ii1+ii2)/2.;
          if(h->Integral(i,ix)/tots>0.68)ii2=ix;
          else ii1=ix;
        }
        if( (double)(ii2-i)*h->GetBinWidth(i)<my_minw68) my_minw68=(double)(ii2-i)*h->GetBinWidth(i);
        
//        for(int ii=i+1; ii<=h->GetNbinsX(); ii++){
//            if((h->Integral(1,ii)+h->GetBinContent(0))/tots<0.69)continue;
//            if(h->Integral(i,ii)/tots>0.68 && (double)(ii-i)*h->GetBinWidth(i)<my_minw68) my_minw68=(double)(ii-i)*h->GetBinWidth(i);
//        }
    }
    return my_minw68;
}




void DrawRelDiff(const char MyVar[], const char cut1[], const char title[]){
    
//
int nbins = 100;
float hlow = -2.;
float hhigh = 2.;
    
////////////////////    
DrawingTools draw(DataFile);
DataSample data(DataFile);
DataSample mc(MCFile);

draw.SetTitle(title);
draw.SetTitleX(MyVar);
draw.SetLegendPos("rt");
draw.SetLegendSize(0.15, 0.15);

draw.SetOptStat(1000002211);
TCanvas c;

draw.Draw(data,MyVar,5000,hlow,hhigh,"all"/*"particle"*/,cut1,"", "AREA100");
auto h0 = draw.GetLastHisto();
draw.Draw(mc,MyVar,5000,hlow,hhigh,"all"/*"particle"*/,cut1,"", "AREA100");
auto h0_mc = draw.GetLastHisto();

draw.Draw(data,MyVar,nbins,hlow,hhigh,"all"/*"particle"*/,cut1,"", "AREA100");
//self.Draw.Draw(self.Input[I].DataSamp, par_name, bins[0], bins[1], bins[2], "all", cut_level, Superpose,"AREA100")
auto h = draw.GetLastHisto();
h->SetLineColor(2);
h->SetMarkerColor(2);
h->SetTitle(title);
h->SetName("Data");

draw.Draw(mc,MyVar,nbins,hlow,hhigh,"all"/*"particle"*/,cut1,"", "AREA100");
auto h_mc = draw.GetLastHisto();
h_mc->SetLineColor(3);
h_mc->SetMarkerColor(3);
h_mc->SetTitle(title);
h_mc->SetName("MC");

gStyle->SetOptFit(1);

float hmean = h->GetMean();
float hmeanerr = h->GetMeanError();
float hRMS = h->GetRMS();
float hRMSerr = h->GetRMSError();
float xlow = hmean-2.*hRMS;
float xhigh = hmean+2.*hRMS;

//auto Func = new TF1("gaus", "gaus", -0.5, 0.5);
auto Func = new TF1("myfunc", myfunction, -0.5, 0.5, 4);
Func->SetLineColor(2);
//Func->SetParameters(h->GetMean(),h->GetRMS()/2.,h->GetRMS()/2.,1.5,1.5,22);
Func->SetParameters(h->GetMean(),h->GetRMS()/2.,h->GetRMS()/2.,22);
Func->SetParLimits(0,-0.7,0.7);
Func->SetParLimits(1,0.01,50);
Func->SetParLimits(2,0.01,50);
//Func->SetParLimits(3,0.5,8);
//Func->SetParLimits(4,0.5,8);

c.Clear();
gStyle->SetStatX(0.30);
gStyle->SetStatY(0.9);
gStyle->SetStatW(0.10);
h->Fit(Func, "", "", xlow, xhigh);
c.Update();
TPaveStats *hs = (TPaveStats*)c.GetPrimitive("stats");
hs->SetLineColor(2);
float p0 = Func->GetParameter(0);
float p0e = Func->GetParError(0);
float p1 = Func->GetParameter(1);
float p1e = Func->GetParError(1);
float p2 = Func->GetParameter(2);
float p2e = Func->GetParError(2);
float p3 = 0;//Func->GetParameter(3);
float p3e = 0;//Func->GetParError(3);
float p4 = 0;//Func->GetParameter(4);
float p4e = 0;//Func->GetParError(4);

c.Clear();
gStyle->SetStatX(0.898);
gStyle->SetStatY(0.9);
gStyle->SetStatW(0.10);
h_mc->Draw();
Func->SetLineColor(3);
h_mc->Fit(Func, "", "same", xlow, xhigh);
c.Update();
TPaveStats *hs_mc = (TPaveStats*)c.GetPrimitive("stats");
hs_mc->SetLineColor(3);
float p0_mc = Func->GetParameter(0);
float p0e_mc = Func->GetParError(0);
float p1_mc = Func->GetParameter(1);
float p1e_mc = Func->GetParError(1);
float p2_mc = Func->GetParameter(2);
float p2e_mc = Func->GetParError(2);
float p3_mc = Func->GetParameter(3);
float p3e_mc = Func->GetParError(3);
float p4_mc = Func->GetParameter(4);
float p4e_mc = Func->GetParError(4);


if(h->GetMaximum()>h_mc->GetMaximum()){
    h_mc->SetMaximum(h->GetMaximum()*1.1);
    h->SetMaximum(h->GetMaximum()*1.1);
}else{
    h_mc->SetMaximum(h_mc->GetMaximum()*1.1);
    h->SetMaximum(h_mc->GetMaximum()*1.1);
}

c.Clear();
h_mc->Draw();
h->Draw("same");
//h->Draw("same");
//h_mc->Fit(Func, "", "sames", xlow, xhigh);
//hs->Draw("same");
//hs_mc->Draw("same");
c.SaveAs("000.pdf");


//print tables
float hmc_mean = h_mc->GetMean();
float hmc_meanerr = h_mc->GetMeanError();
float hmc_RMS = h_mc->GetRMS();
float hmc_RMSerr = h_mc->GetRMSError();

std::cout
<<"\\begin{table}[htbp]\n"
<<"\\begin{center}\n"
<<"\\begin{tabular}{|c|c|c|}\n"
<<"	\\hline\n"
<<"	Selection & \\multicolumn{2}{|c|}{$"<<title<<"$}  \\\\ \\hline\n"
<<"	Event type & MC & DATA \\\\ \n"
<<"	\\hline\n"
<<"	Mean & "<<hmc_mean<<" $\\pm$ "<<hmc_meanerr<<" & "<<hmean<<" $\\pm$ "<<hmeanerr<<" \\\\ \n"
<<"	\\hline \n"
<<"	RMS & "<<hmc_RMS<<" $\\pm$ "<<hmc_RMSerr<<" & "<<hRMS<<" $\\pm$ "<<hRMSerr<<" \\\\ \n" 
<<"	\\hline \n" 
<<"	minW68/2 & "<<minW68(h0_mc)/2.<<" $\\pm$ "<<hmc_RMSerr<<" & "<<minW68(h0)/2.<<" $\\pm$ "<<hRMSerr<<" \\\\ \n" 
<<"	\\hline \n" 

<<"	$p0$ & "<<p0_mc<<" $\\pm$ "<<p0e_mc<<" & "<<p0<<" $\\pm$ "<<p0e<<" \\\\ \n"
<<"	\\hline \n"
<<"	$p1$ & "<<p1_mc<<" $\\pm$ "<<p1e_mc<<" & "<<p1<<" $\\pm$ "<<p1e<<" \\\\ \n"
<<"	\\hline \n"
<<"	$p2$ & "<<p2_mc<<" $\\pm$ "<<p2e_mc<<" & "<<p2<<" $\\pm$ "<<p2e<<" \\\\ \n"
<<"	\\hline \n"
//<<"	$p3$ & "<<p3_mc<<" $\\pm$ "<<p3e_mc<<" & "<<p3<<" $\\pm$ "<<p3e<<" \\\\ \n"
//<<"	\\hline \n"
//<<"	$p4$ & "<<p4_mc<<" $\\pm$ "<<p4e_mc<<" & "<<p4<<" $\\pm$ "<<p4e<<" \\\\ \n"
//<<"	\\hline \n"
<<"\\end{tabular}\n"
<<"\\caption{Parameters of PROD7 distribution } \\vspace{0.2in}\n"
<<"\\label{xxx}\n"
<<"\\end{center}\n"
<<"\\end{table}\n"
<<std::endl;

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
void myscript_fit(int irul){
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






gROOT->ProcessLine(".! rm report.pdf");



if(irul==0){
   TString mycut = basic_cut+posfgd1;
   DrawRelDiff(myvar0.Data(), mycut.Data(), "posFGD1");
   gROOT->ProcessLine(".! pdfunite 000.pdf report.pdf");
   //
   TString mycut = basic_cut+posfgd2;
   DrawRelDiff(myvar0.Data(), mycut.Data(), "posFGD2");
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   //
   TString mycut = basic_cut+posdsecal;
   DrawRelDiff(myvar0.Data(), mycut.Data(), "posDsEcal");
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   //
   TString mycut = basic_cut+negfgd1;
   DrawRelDiff(myvar1.Data(), mycut.Data(), "negFGD1");
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   //
   TString mycut = basic_cut+negfgd2;
   DrawRelDiff(myvar1.Data(), mycut.Data(), "negFGD2");
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   //
   TString mycut = basic_cut+negdsecal;
   DrawRelDiff(myvar1.Data(), mycut.Data(), "negDsECal");
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   //
   TString mycut = basic_cut+negfgd1ecal;
   DrawRelDiff(myvar1.Data(), mycut.Data(), "FGD1->ECal");
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   //
   TString mycut = basic_cut+negfgd1smrd;
   DrawRelDiff(myvar1.Data(), mycut.Data(), "FGD1->ECal-SMRD");
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   //
   TString mycut = basic_cut+negfgd2ecal;
   DrawRelDiff(myvar1.Data(), mycut.Data(), "FGD2->ECal");
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   //
   TString mycut = basic_cut+negfgd2smrd;
   DrawRelDiff(myvar1.Data(), mycut.Data(), "FGD2->ECal-SMRD");
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
   gROOT->ProcessLine(".! pdfunite 000.pdf report.pdf");
   //
   TString mycut = basic_cut+dircut2+posfgd2;
   DrawRelDiff(myvar0.Data(), mycut.Data(), "posFGD2, |cos#theta<0.6|");
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   //
   TString mycut = basic_cut+dircut2+posdsecal;
   DrawRelDiff(myvar0.Data(), mycut.Data(), "posDsEcal, |cos#theta<0.6|");
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   //
   TString mycut = basic_cut+dircut2+negfgd1;
   DrawRelDiff(myvar1.Data(), mycut.Data(), "negFGD1, |cos#theta<0.6|");
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   //
   TString mycut = basic_cut+dircut2+negfgd2;
   DrawRelDiff(myvar1.Data(), mycut.Data(), "negFGD2, |cos#theta<0.6|");
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   //
   TString mycut = basic_cut+dircut2+negdsecal;
   DrawRelDiff(myvar1.Data(), mycut.Data(), "negDsECal, |cos#theta<0.6|");
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   //
   TString mycut = basic_cut+dircut2+negfgd1ecal;
   DrawRelDiff(myvar1.Data(), mycut.Data(), "FGD1->ECal, |cos#theta<0.6|");
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   //
   TString mycut = basic_cut+dircut2+negfgd1smrd;
   DrawRelDiff(myvar1.Data(), mycut.Data(), "FGD1->ECal-SMRD, |cos#theta<0.6|");
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   //
   TString mycut = basic_cut+dircut2+negfgd2ecal;
   DrawRelDiff(myvar1.Data(), mycut.Data(), "FGD2->ECal, |cos#theta<0.6|");
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
   //
   TString mycut = basic_cut+dircut2+negfgd2smrd;
   DrawRelDiff(myvar1.Data(), mycut.Data(), "FGD2->ECal-SMRD, |cos#theta<0.6|");
   gROOT->ProcessLine(".! pdfunite report.pdf 000.pdf 111.pdf && mv 111.pdf report.pdf");
}
}













