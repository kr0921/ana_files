root [0] DrawingTools draw("./nd280Highland2_v2r45_1_data.root");
root [1] DataSample data("./nd280Highland2_v2r45_1_data.root");
root [3] draw.Draw(data,"(last_tpc_mom-mom_mu_range_tpc)/last_tpc_mom",100,-2.,2.,"all"," last_tpc_nnodes>18 && last_tpc_mom>0 && startpos[2]> -2000 && accum_level[0][3]>7","", "AREA100");
 --------------------------------------------------------
 Statistics
  entries   = 6431 (not weighted; under/overflow included) 
  integral  = 100
  underflow = 0.0466708
  overflow  = 0
 --------------------------------------------------------

root [7] default->Draw("(last_tpc_mom-mom_mu_range_tpc)/last_tpc_mom>>h(100,-2.,2.)"," last_tpc_nnodes>18 && last_tpc_mom>0 && startpos[2]> -2000 && accum_leve(Long64_t)6431
root [8] h->Draw()
default->Draw("(last_tpc_mom-mom_mu_range_tpc)/last_tpc_mom"," last_tpc_nnodes>18 && last_tpc_mom>0 && startpos[2]> -2000 && accum_level[0][3]>7")

