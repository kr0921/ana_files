
float dsyst_bdnmc(const char dsyst[], float Mv, int fgd){
    
TString syst(dsyst);

TString cut("( accum_level[][0]>14");
cut += " && ldm_Mv>";
std::stringstream ss;
std::string strf;
ss<<Mv-0.001; ss>>strf; cut += strf;
std::stringstream ss1;
std::string strf1;
cut += " && ldm_Mv<";
ss1<<Mv+0.001; ss1>>strf1; cut += strf1;
cut += " )";
std::cout<<"aaa "<<cut<<std::endl;

TString file1("");
TString file2("");
if(fgd == 1){
  file1="/meg/scratch/suslov/work_t2k/T2K/work/files/ldm_ntuples_v1/ldm_dsyst/fgd1_pi0_decay_prerun7geom.root";
  file2="/meg/scratch/suslov/work_t2k/T2K/work/files/ldm_ntuples_v1/ldm_dsyst/fgd1_eta_decay_prerun7geom.root";
}
if(fgd == 2){
  file1="/meg/scratch/suslov/work_t2k/T2K/work/files/ldm_ntuples_v1/ldm_dsyst/fgd2_pi0_decay_prerun7geom.root";
  file2="/meg/scratch/suslov/work_t2k/T2K/work/files/ldm_ntuples_v1/ldm_dsyst/fgd2_eta_decay_prerun7geom.root";
}

//=== Initialize DrawingTools   
DrawingTools* draw = new DrawingTools(file1.Data(),4);   
draw->SetStackFillStyle(3254);    
    
Experiment exp_fgd1("nd280");
DataSample* magnet_mc_pi0 = new DataSample(file1.Data());
DataSample* magnet_mc_eta = new DataSample(file2.Data());

SampleGroup ldm("ldm");
ldm.AddMCSample("magnet",magnet_mc_pi0);
ldm.AddMCSample("magnet",magnet_mc_eta);

exp_fgd1.AddSampleGroup( "ldm"  , ldm );    
exp_fgd1.GetMCSample("ldm" , "magnet")->SetCurrentTree(syst.Data());

//draw->DrawRelativeErrors(exp_fgd1,"selelec_mom",1,0,3000,"accum_level[][0]>14 && ldm_Mv<0.101 && ldm_Mv>0.099","","");
if(syst.Contains("sipion") || syst.Contains("tpcclustereff") || syst.Contains("tpctrackeff")  || syst.Contains("chargeideff") || syst.Contains("tpcfgdmatcheff")
    || syst.Contains("tpc_ecal_matcheff") || syst.Contains("ecal_pid")  || syst.Contains("fgdmass") || syst.Contains("ecal_emhippid")
    || syst.Contains("fgd2shower")  || syst.Contains("nuetpcpileup") || syst.Contains("nuep0dpileup")  || syst.Contains("nueecalpileup") || syst.Contains("nueoofv")
    || syst.Contains("siproton") ){
    //|| syst.Contains("va_syst") || syst.Contains("nuparent_decaypos") || syst.Contains("tpc_angres")){
    std::cout<<syst<<"   weighted systematics"<<std::endl;
   //return draw->DrawRelativeErrors(exp_fgd1,"selelec_mom",1,0,100000,(cut+" && weight_syst_total<10").Data(),"","SYS");
   return draw->DrawRelativeErrors(exp_fgd1,"selelec_mom",1,0,100000,(cut+" * (ldm_expectedEvents/3000.)").Data(),"","SYS");
} else{
   //return draw->DrawRelativeErrors(exp_fgd1,"selelec_mom",1,0,100000,cut.Data(),"","SYS");
   return draw->DrawRelativeErrors(exp_fgd1,"selelec_mom",1,0,100000,(cut+" * (ldm_expectedEvents/3000.)").Data(),"","SYS");
}

}

/////////////////////////////////
dsyst_neut_fgd(const char dsyst[],bool fhc=true,const char cut[]="accum_level[][0]>14",const char descr[]="all_bg",int fgd=1){
//TString syst("momresol_syst");
TString syst(dsyst);
    
    
//=== Initialize DrawingTools   
DrawingTools* draw = new DrawingTools("/meg/scratch/suslov/work_t2k/T2K/work/files/ldm_ntuples_v1/ldm_dsyst/neut_fhc_run2air_p6T_fgd1.root",4);   
draw->SetStackFillStyle(3254);    
    
Experiment exp_fgd("nd280");

DataSample* magnet_mc_run2a;
DataSample* magnet_mc_run2w;
DataSample* magnet_mc_run3a;
DataSample* magnet_mc_run4a;
DataSample* magnet_mc_run4w;
DataSample* magnet_mc_run5w;
DataSample* magnet_mc_run6a;
DataSample* magnet_mc_run7w;
DataSample* magnet_mc_run8a;
DataSample* magnet_mc_run8w;
DataSample* magnet_mc_run9w;
if (fgd==1){
   magnet_mc_run2a = new DataSample("/meg/scratch/suslov/work_t2k/T2K/work/files/ldm_ntuples_v1/ldm_dsyst/neut_fhc_run2air_p6T_fgd1.root");
   magnet_mc_run2w = new DataSample("/meg/scratch/suslov/work_t2k/T2K/work/files/ldm_ntuples_v1/ldm_dsyst/neut_fhc_run2water_p6T_fgd1.root");
   magnet_mc_run3a = new DataSample("/meg/scratch/suslov/work_t2k/T2K/work/files/ldm_ntuples_v1/ldm_dsyst/neut_fhc_run3air_p6T_fgd1.root");
   magnet_mc_run4a = new DataSample("/meg/scratch/suslov/work_t2k/T2K/work/files/ldm_ntuples_v1/ldm_dsyst/neut_fhc_run4air_p6T_fgd1.root");
   magnet_mc_run4w = new DataSample("/meg/scratch/suslov/work_t2k/T2K/work/files/ldm_ntuples_v1/ldm_dsyst/neut_fhc_run4water_p6T_fgd1.root");
   magnet_mc_run5w = new DataSample("/meg/scratch/suslov/work_t2k/T2K/work/files/ldm_ntuples_v1/ldm_dsyst/neut_rhc_run5water_p6T_fgd1.root");
   magnet_mc_run6a = new DataSample("/meg/scratch/suslov/work_t2k/T2K/work/files/ldm_ntuples_v1/ldm_dsyst/neut_rhc_run6air_p6T_fgd1.root");
   magnet_mc_run7w = new DataSample("/meg/scratch/suslov/work_t2k/T2K/work/files/ldm_ntuples_v1/ldm_dsyst/neut_rhc_run7water_p6T_fgd1.root");
   magnet_mc_run8a = new DataSample("/meg/scratch/suslov/work_t2k/T2K/work/files/ldm_ntuples_v1/ldm_dsyst/neut_fhc_run8air_p6T_fgd1.root");
   magnet_mc_run8w = new DataSample("/meg/scratch/suslov/work_t2k/T2K/work/files/ldm_ntuples_v1/ldm_dsyst/neut_fhc_run8water_p6T_fgd1.root");
   magnet_mc_run9w = new DataSample("/meg/scratch/suslov/work_t2k/T2K/work/files/ldm_ntuples_v1/ldm_dsyst/neut_rhc_run9water_p6T_fgd1.root");
}
if (fgd==2){
   magnet_mc_run2a = new DataSample("/meg/scratch/suslov/work_t2k/T2K/work/files/ldm_ntuples_v1/ldm_dsyst/neut_fhc_run2air_p6T_fgd2.root");
   magnet_mc_run2w = new DataSample("/meg/scratch/suslov/work_t2k/T2K/work/files/ldm_ntuples_v1/ldm_dsyst/neut_fhc_run2water_p6T_fgd2.root");
   magnet_mc_run3a = new DataSample("/meg/scratch/suslov/work_t2k/T2K/work/files/ldm_ntuples_v1/ldm_dsyst/neut_fhc_run3air_p6T_fgd2.root");
   magnet_mc_run4a = new DataSample("/meg/scratch/suslov/work_t2k/T2K/work/files/ldm_ntuples_v1/ldm_dsyst/neut_fhc_run4air_p6T_fgd2.root");
   magnet_mc_run4w = new DataSample("/meg/scratch/suslov/work_t2k/T2K/work/files/ldm_ntuples_v1/ldm_dsyst/neut_fhc_run4water_p6T_fgd2.root");
   magnet_mc_run5w = new DataSample("/meg/scratch/suslov/work_t2k/T2K/work/files/ldm_ntuples_v1/ldm_dsyst/neut_rhc_run5water_p6T_fgd2.root");
   magnet_mc_run6a = new DataSample("/meg/scratch/suslov/work_t2k/T2K/work/files/ldm_ntuples_v1/ldm_dsyst/neut_rhc_run6air_p6T_fgd2.root");
   magnet_mc_run7w = new DataSample("/meg/scratch/suslov/work_t2k/T2K/work/files/ldm_ntuples_v1/ldm_dsyst/neut_rhc_run7water_p6T_fgd2.root");
   magnet_mc_run8a = new DataSample("/meg/scratch/suslov/work_t2k/T2K/work/files/ldm_ntuples_v1/ldm_dsyst/neut_fhc_run8air_p6T_fgd2.root");
   magnet_mc_run8w = new DataSample("/meg/scratch/suslov/work_t2k/T2K/work/files/ldm_ntuples_v1/ldm_dsyst/neut_fhc_run8water_p6T_fgd2.root");
   magnet_mc_run9w = new DataSample("/meg/scratch/suslov/work_t2k/T2K/work/files/ldm_ntuples_v1/ldm_dsyst/neut_rhc_run9water_p6T_fgd2.root");
}


SampleGroup run2a("run2a");
run2a.AddMCSample("magnet",magnet_mc_run2a);
SampleGroup run2w("run2w");
run2w.AddMCSample("magnet",magnet_mc_run2w);
SampleGroup run3a("run3a");
run3a.AddMCSample("magnet",magnet_mc_run3a);
SampleGroup run4a("run4a");
run4a.AddMCSample("magnet",magnet_mc_run4a);
SampleGroup run4w("run4w");
run4w.AddMCSample("magnet",magnet_mc_run4w);
SampleGroup run5w("run5w");
run5w.AddMCSample("magnet",magnet_mc_run5w);
SampleGroup run6a("run6a");
run6a.AddMCSample("magnet",magnet_mc_run6a);
SampleGroup run7w("run7w");
run7w.AddMCSample("magnet",magnet_mc_run7w);
SampleGroup run8a("run8a");
run8a.AddMCSample("magnet",magnet_mc_run8a);
SampleGroup run8w("run8w");
run8w.AddMCSample("magnet",magnet_mc_run8w);
SampleGroup run9w("run9w");
run9w.AddMCSample("magnet",magnet_mc_run9w);

if(fhc)exp_fgd.AddSampleGroup( "run2a"  , run2a );    
if(fhc)exp_fgd.AddSampleGroup( "run2w"  , run2w ); 
if(fhc)exp_fgd.AddSampleGroup( "run3a"  , run3a ); 
if(fhc)exp_fgd.AddSampleGroup( "run4a"  , run4a ); 
if(fhc)exp_fgd.AddSampleGroup( "run4w"  , run4w ); 
if(!fhc)exp_fgd.AddSampleGroup( "run5w"  , run5w ); 
if(!fhc)exp_fgd.AddSampleGroup( "run6a"  , run6a ); 
if(!fhc)exp_fgd.AddSampleGroup( "run7w"  , run7w ); 
if(fhc)exp_fgd.AddSampleGroup( "run8a"  , run8a ); 
if(fhc)exp_fgd.AddSampleGroup( "run8w"  , run8w ); 
if(!fhc)exp_fgd.AddSampleGroup( "run9w"  , run9w ); 
exp_fgd.SetCurrentTree(syst.Data());

float RelErr = draw->DrawRelativeErrors(exp_fgd,"selelec_mom",1,0,100000,cut,"","SYS");
if(fgd==1){
   if(fhc)std::cout<<"FGD1_FHC   "<<descr<<"   "<<syst<<"   RelErr= "<<RelErr<<std::endl;
   if(!fhc)std::cout<<"FGD1_RHC   "<<descr<<"   "<<syst<<"   RelErr= "<<RelErr<<std::endl;
}
if(fgd==2){
   if(fhc)std::cout<<"FGD2_FHC   "<<descr<<"   "<<syst<<"   RelErr= "<<RelErr<<std::endl;
   if(!fhc)std::cout<<"FGD2_RHC   "<<descr<<"   "<<syst<<"   RelErr= "<<RelErr<<std::endl;
}
//draw->Draw(exp_fgd,"selelec_mom",5,0,3000,"particle","accum_level[0]>14","","");
//draw->Draw(*mc,"selelec_mom",20,0,2000,category2.Data(),cut.Data(),"", "",data_fgd2->GetPOT()/mc->GetPOT());

}


/////////////////////////////////
dsyst_genie_fgd(const char dsyst[],bool fhc=true,const char cut[]="accum_level[][0]>14",const char descr[]="all_bg",int fgd=1){
//TString syst("momresol_syst");
TString syst(dsyst);
    
    
//=== Initialize DrawingTools   
DrawingTools* draw;
if (fgd==1) draw = new DrawingTools("/meg/scratch/suslov/work_t2k/T2K/work/files/ldm_ntuples_v1/ldm_dsyst/production006_B_mcp_genie_2010-11-air_magnet_run2_anal_fgd1.root",4);   
if (fgd==2) draw = new DrawingTools("/meg/scratch/suslov/work_t2k/T2K/work/files/ldm_ntuples_v1/ldm_dsyst/production006_B_mcp_genie_2010-11-air_magnet_run2_anal_fgd2.root",4);   
draw->SetStackFillStyle(3254);    
    
Experiment exp_fgd("nd280");

DataSample* magnet_mc_run2a;
DataSample* magnet_mc_run2w;
DataSample* magnet_mc_run3a;
DataSample* magnet_mc_run4a;
DataSample* magnet_mc_run4w;
DataSample* magnet_mc_run5w;
DataSample* magnet_mc_run6a;
DataSample* magnet_mc_run7w;
DataSample* magnet_mc_run8a;
DataSample* magnet_mc_run8w;
if (fgd==1){
   magnet_mc_run2a = new DataSample("/meg/scratch/suslov/work_t2k/T2K/work/files/ldm_ntuples_v1/ldm_dsyst/production006_B_mcp_genie_2010-11-air_magnet_run2_anal_fgd1.root");
   magnet_mc_run2w = new DataSample("/meg/scratch/suslov/work_t2k/T2K/work/files/ldm_ntuples_v1/ldm_dsyst/production006_B_mcp_genie_2010-11-water_magnet_run2_anal_fgd1.root");
   magnet_mc_run3a = new DataSample("/meg/scratch/suslov/work_t2k/T2K/work/files/ldm_ntuples_v1/ldm_dsyst/production006_B_mcp_genie_2010-11-air_magnet_run3_anal_fgd1.root");
   magnet_mc_run4a = new DataSample("/meg/scratch/suslov/work_t2k/T2K/work/files/ldm_ntuples_v1/ldm_dsyst/production006_B_mcp_genie_2010-11-air_magnet_run4_anal_fgd1.root");
   magnet_mc_run4w = new DataSample("/meg/scratch/suslov/work_t2k/T2K/work/files/ldm_ntuples_v1/ldm_dsyst/production006_B_mcp_genie_2010-11-water_magnet_run4_anal_fgd1.root");
   magnet_mc_run5w = new DataSample("/meg/scratch/suslov/work_t2k/T2K/work/files/ldm_ntuples_v1/ldm_dsyst/production006_B_mcp_anti-genie_2010-11-water_magnet_run5_anal_fgd1.root");
   magnet_mc_run6a = new DataSample("/meg/scratch/suslov/work_t2k/T2K/work/files/ldm_ntuples_v1/ldm_dsyst/production006_B_mcp_anti-genie_2010-11-air_magnet_run6_anal_fgd1.root");
   magnet_mc_run7w = new DataSample("/meg/scratch/suslov/work_t2k/T2K/work/files/ldm_ntuples_v1/ldm_dsyst/production006_L_mcp_anti-genie_2015-08-water_magnet_run7_anal_fgd1.root");
   magnet_mc_run8a = new DataSample("/meg/scratch/suslov/work_t2k/T2K/work/files/ldm_ntuples_v1/ldm_dsyst/production006_L_mcp_genie_2015-08-air_magnet_run8_anal_fgd1.root");
   magnet_mc_run8w = new DataSample("/meg/scratch/suslov/work_t2k/T2K/work/files/ldm_ntuples_v1/ldm_dsyst/production006_L_mcp_genie_2015-08-water_magnet_run8_anal_fgd1.root");
}
if (fgd==2){
   magnet_mc_run2a = new DataSample("/meg/scratch/suslov/work_t2k/T2K/work/files/ldm_ntuples_v1/ldm_dsyst/production006_B_mcp_genie_2010-11-air_magnet_run2_anal_fgd2.root");
   magnet_mc_run2w = new DataSample("/meg/scratch/suslov/work_t2k/T2K/work/files/ldm_ntuples_v1/ldm_dsyst/production006_B_mcp_genie_2010-11-water_magnet_run2_anal_fgd2.root");
   magnet_mc_run3a = new DataSample("/meg/scratch/suslov/work_t2k/T2K/work/files/ldm_ntuples_v1/ldm_dsyst/production006_B_mcp_genie_2010-11-air_magnet_run3_anal_fgd2.root");
   magnet_mc_run4a = new DataSample("/meg/scratch/suslov/work_t2k/T2K/work/files/ldm_ntuples_v1/ldm_dsyst/production006_B_mcp_genie_2010-11-air_magnet_run4_anal_fgd2.root");
   magnet_mc_run4w = new DataSample("/meg/scratch/suslov/work_t2k/T2K/work/files/ldm_ntuples_v1/ldm_dsyst/production006_B_mcp_genie_2010-11-water_magnet_run4_anal_fgd2.root");
   magnet_mc_run5w = new DataSample("/meg/scratch/suslov/work_t2k/T2K/work/files/ldm_ntuples_v1/ldm_dsyst/production006_B_mcp_anti-genie_2010-11-water_magnet_run5_anal_fgd2.root");
   magnet_mc_run6a = new DataSample("/meg/scratch/suslov/work_t2k/T2K/work/files/ldm_ntuples_v1/ldm_dsyst/production006_B_mcp_anti-genie_2010-11-air_magnet_run6_anal_fgd2.root");
   magnet_mc_run7w = new DataSample("/meg/scratch/suslov/work_t2k/T2K/work/files/ldm_ntuples_v1/ldm_dsyst/production006_L_mcp_anti-genie_2015-08-water_magnet_run7_anal_fgd2.root");
   magnet_mc_run8a = new DataSample("/meg/scratch/suslov/work_t2k/T2K/work/files/ldm_ntuples_v1/ldm_dsyst/production006_L_mcp_genie_2015-08-air_magnet_run8_anal_fgd2.root");
   magnet_mc_run8w = new DataSample("/meg/scratch/suslov/work_t2k/T2K/work/files/ldm_ntuples_v1/ldm_dsyst/production006_L_mcp_genie_2015-08-water_magnet_run8_anal_fgd2.root");
}

SampleGroup run2a("run2a");
run2a.AddMCSample("magnet",magnet_mc_run2a);
SampleGroup run2w("run2w");
run2w.AddMCSample("magnet",magnet_mc_run2w);
SampleGroup run3a("run3a");
run3a.AddMCSample("magnet",magnet_mc_run3a);
SampleGroup run4a("run4a");
run4a.AddMCSample("magnet",magnet_mc_run4a);
SampleGroup run4w("run4w");
run4w.AddMCSample("magnet",magnet_mc_run4w);
SampleGroup run5w("run5w");
run5w.AddMCSample("magnet",magnet_mc_run5w);
SampleGroup run6a("run6a");
run6a.AddMCSample("magnet",magnet_mc_run6a);
SampleGroup run7w("run7w");
run7w.AddMCSample("magnet",magnet_mc_run7w);
SampleGroup run8a("run8a");
run8a.AddMCSample("magnet",magnet_mc_run8a);
SampleGroup run8w("run8w");
run8w.AddMCSample("magnet",magnet_mc_run8w);

if(fhc)exp_fgd.AddSampleGroup( "run2a"  , run2a );    
if(fhc)exp_fgd.AddSampleGroup( "run2w"  , run2w ); 
if(fhc)exp_fgd.AddSampleGroup( "run3a"  , run3a ); 
if(fhc)exp_fgd.AddSampleGroup( "run4a"  , run4a ); 
if(fhc)exp_fgd.AddSampleGroup( "run4w"  , run4w ); 
if(!fhc)exp_fgd.AddSampleGroup( "run5w"  , run5w ); 
if(!fhc)exp_fgd.AddSampleGroup( "run6a"  , run6a ); 
if(!fhc)exp_fgd.AddSampleGroup( "run7w"  , run7w ); 
if(fhc)exp_fgd.AddSampleGroup( "run8a"  , run8a ); 
if(fhc)exp_fgd.AddSampleGroup( "run8w"  , run8w ); 
exp_fgd.SetCurrentTree(syst.Data());

float RelErr = draw->DrawRelativeErrors(exp_fgd,"selelec_mom",1,0,100000,cut,"","SYS");
if(fgd==1){
   if(fhc)std::cout<<"FGD1_FHC   "<<descr<<"   "<<syst<<"   RelErr= "<<RelErr<<std::endl;
   if(!fhc)std::cout<<"FGD1_RHC   "<<descr<<"   "<<syst<<"   RelErr= "<<RelErr<<std::endl;
}
if(fgd==2){
   if(fhc)std::cout<<"FGD2_FHC   "<<descr<<"   "<<syst<<"   RelErr= "<<RelErr<<std::endl;
   if(!fhc)std::cout<<"FGD2_RHC   "<<descr<<"   "<<syst<<"   RelErr= "<<RelErr<<std::endl;
}
}

/////////////////////////////////////////////
TGraph* dsyst_bdnmc_graph(const char dsyst[],const char gname[], int fgd, float maxMv=130.){
  Double_t x[200], y[200];
  int npoints=0;

  float Mv=0.005;
  while(Mv<maxMv){
     float esyst = dsyst_bdnmc(dsyst, Mv, fgd);
     std::cout<<dsyst<<"  "<<gname<<"  "<<Mv<<"  "<<esyst<<std::endl<<std::endl<<std::endl<<std::endl;
     x[npoints] = Mv;
     y[npoints] = esyst;
     npoints++;
     Mv += 0.005;
  }
  TGraph* gr = new TGraph(npoints,x,y);
  gr->SetName(gname);
  return gr;
}



//////////////////////////////////////////////
dsyst(const char _syst_[], int irul=0){
//TString syst("all_syst");
TString syst(_syst_);

//NEUT /////////////////////////////
if(irul==-1){
   bool fhc=true;
   int fgd = 1;
   dsyst_genie_fgd(syst.Data(),fhc,"accum_level[][0]>14 && nuElectronElasticTopo==10","nuEleElastic",fgd);  //nuEleElastic fgd1_fhc
   dsyst_neut_fgd(syst.Data(),fhc,"accum_level[][0]>14 && nuElectronElasticTopo==1","ccnue",fgd);  //ccnue fgd1_fhc
   dsyst_neut_fgd(syst.Data(),fhc,"accum_level[][0]>14 && !(nuElectronElasticTopo==10 || nuElectronElasticTopo==1)","otherBG",fgd);  //otherBG fgd1_fhc
   fgd = 2;
   dsyst_genie_fgd(syst.Data(),fhc,"accum_level[][0]>14 && fgd2nuElectronElasticTopo==10","nuEleElastic",fgd);  //nuEleElastic fgd2_fhc
   dsyst_neut_fgd(syst.Data(),fhc,"accum_level[][0]>14 && fgd2nuElectronElasticTopo==1","ccnue",fgd);  //ccnue fgd2_fhc
   dsyst_neut_fgd(syst.Data(),fhc,"accum_level[][0]>14 && !(fgd2nuElectronElasticTopo==10 || fgd2nuElectronElasticTopo==1)","otherBG",fgd);  //otherBG fgd2_fhc
   
   bool fhc=false;
   fgd = 1;
   dsyst_genie_fgd(syst.Data(),fhc,"accum_level[][0]>14 && nuElectronElasticTopo==10","nuEleElastic",fgd);  //nuEleElastic fgd1_rhc
   dsyst_neut_fgd(syst.Data(),fhc,"accum_level[][0]>14 && nuElectronElasticTopo==1","ccnue",fgd);  //ccnue fgd1_rhc
   dsyst_neut_fgd(syst.Data(),fhc,"accum_level[][0]>14 && !(nuElectronElasticTopo==10 || nuElectronElasticTopo==1)","otherBG",fgd);  //otherBG fgd1_rhc
   fgd = 2;
   dsyst_genie_fgd(syst.Data(),fhc,"accum_level[][0]>14 && fgd2nuElectronElasticTopo==10","nuEleElastic",fgd);  //nuEleElastic fgd2_rhc
   dsyst_neut_fgd(syst.Data(),fhc,"accum_level[][0]>14 && fgd2nuElectronElasticTopo==1","ccnue",fgd);  //ccnue fgd2_rhc
   dsyst_neut_fgd(syst.Data(),fhc,"accum_level[][0]>14 && !(fgd2nuElectronElasticTopo==10 || fgd2nuElectronElasticTopo==1)","otherBG",fgd);  //otherBG fgd2_rhc
}


//LDM/////////////////////////////////

//fgd1
if(irul==1){
   TFile f((syst+".root").Data(),"recreate");
   int fgd = 1;
   auto fgd1 = dsyst_bdnmc_graph(syst.Data(),"fgd1_ldm", fgd,0.546);
   fgd1->Draw("AC*");
   f.cd(); fgd1->Write();
   f.Close();
   return;
}

//fgd2
if(irul==2){
   TFile f((syst+".root").Data(),"update"/*"recreate"*/);
   int fgd = 2;
   auto fgd2 = dsyst_bdnmc_graph(syst.Data(),"fgd2_ldm", fgd,0.546);
   fgd2->Draw("AC*");
   f.cd(); fgd2->Write();
   f.Close();
   return;
}




///////////////////////
//Draw plot
if(irul==0){  
  TString sdir("./syst/");
  TFile f((sdir+syst+".root").Data());
  
  auto c = new TCanvas();
  TH1F *hfr = c->DrawFrame(0.,0.,0.6,0.2);
  hfr->SetYTitle("Relative error");
  hfr->SetXTitle("M_{V}, GeV");
  hfr->SetTitle(syst.Data());
  
  
  fgd1_ldm->SetMarkerStyle(20);
  fgd1_ldm->SetMarkerSize(0.99);
  fgd1_ldm->SetMarkerColor(2);
  fgd1_ldm->SetLineColor(2);
  fgd1_ldm->SetLineWidth(4);
  fgd1_ldm->Draw("same PL");

  fgd2_ldm->SetMarkerStyle(20);
  fgd2_ldm->SetMarkerSize(0.99);
  fgd2_ldm->SetMarkerColor(4);
  fgd2_ldm->SetLineColor(4);
  fgd2_ldm->SetLineWidth(4);
  fgd2_ldm->Draw("same PL");
  
  TLegend* leg = new TLegend(0.45,0.61,0.79,0.86);
  leg->AddEntry(fgd1_ldm,"FGD1 selection","lp");
  leg->AddEntry(fgd2_ldm,"FGD2 selection","lp");
  leg->Draw();
  
  c->SaveAs((syst+".png").Data());
}

}



