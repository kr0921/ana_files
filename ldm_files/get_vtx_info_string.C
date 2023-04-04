
get_vtx_info_string(const char root_file_name[]){

//TFile *_file0 = TFile::Open("/meg/scratch/suslov/work_t2k/T2K/work/files/ExoticsReader/Exotics/DPhoton/Production_BdNMC/Oct_2020/Eta_decay_parent/FGD1/oa_nt_ldma_90400020-0000_fyglq4l4sdh2_anal_000_bsdv01_2.root");

TFile *_file0 = TFile::Open(root_file_name);
TTree* oldtree = (TTree*)_file0->Get("TruthDir/NRooTrackerVtx");
oldtree->Draw("Vtx.Vtx.EvtCode.fString >> h");
cout<<h->GetXaxis()->GetBinLabel(1)<<endl;
}

