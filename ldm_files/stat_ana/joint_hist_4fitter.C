
/////////////////////////////////
 TFile *_file0 = TFile::Open("data/LDM2FGD_ana0.095.root","UPDATE")

(*hData_VR1_FGD1_FHC_obs_selelec_mom)=(*hData_VR1_FGD1_FHC_obs_selelec_mom)+(*hData_VR1_FGD2_FHC_obs_selelec_mom)+(*hData_VR1_FGD1_RHC_obs_selelec_mom)+(*hData_VR1_FGD2_RHC_obs_selelec_mom)
(*hccnueNom_VR1_FGD1_FHC_obs_selelec_mom)=(*hccnueNom_VR1_FGD1_FHC_obs_selelec_mom)+(*hccnueNom_VR1_FGD2_FHC_obs_selelec_mom)+(*hccnueNom_VR1_FGD1_RHC_obs_selelec_mom)+(*hccnueNom_VR1_FGD2_RHC_obs_selelec_mom)
(*hnuEleElasticNom_VR1_FGD1_FHC_obs_selelec_mom)=(*hnuEleElasticNom_VR1_FGD1_FHC_obs_selelec_mom)+(*hnuEleElasticNom_VR1_FGD2_FHC_obs_selelec_mom)+(*hnuEleElasticNom_VR1_FGD1_RHC_obs_selelec_mom)+(*hnuEleElasticNom_VR1_FGD2_RHC_obs_selelec_mom)
(*hotherBGNom_VR1_FGD1_FHC_obs_selelec_mom)=(*hotherBGNom_VR1_FGD1_FHC_obs_selelec_mom)+(*hotherBGNom_VR1_FGD2_FHC_obs_selelec_mom)+(*hotherBGNom_VR1_FGD1_RHC_obs_selelec_mom)+(*hotherBGNom_VR1_FGD2_RHC_obs_selelec_mom)

(*hData_VR1_FGD1_FHC_obs_selelec_costheta_ldm)=(*hData_VR1_FGD1_FHC_obs_selelec_costheta_ldm)+(*hData_VR1_FGD2_FHC_obs_selelec_costheta_ldm)+(*hData_VR1_FGD1_RHC_obs_selelec_costheta_ldm)+(*hData_VR1_FGD2_RHC_obs_selelec_costheta_ldm)
(*hccnueNom_VR1_FGD1_FHC_obs_selelec_costheta_ldm)=(*hccnueNom_VR1_FGD1_FHC_obs_selelec_costheta_ldm)+(*hccnueNom_VR1_FGD2_FHC_obs_selelec_costheta_ldm)+(*hccnueNom_VR1_FGD1_RHC_obs_selelec_costheta_ldm)+(*hccnueNom_VR1_FGD2_RHC_obs_selelec_costheta_ldm)
(*hnuEleElasticNom_VR1_FGD1_FHC_obs_selelec_costheta_ldm)=(*hnuEleElasticNom_VR1_FGD1_FHC_obs_selelec_costheta_ldm)+(*hnuEleElasticNom_VR1_FGD2_FHC_obs_selelec_costheta_ldm)+(*hnuEleElasticNom_VR1_FGD1_RHC_obs_selelec_costheta_ldm)+(*hnuEleElasticNom_VR1_FGD2_RHC_obs_selelec_costheta_ldm)
(*hotherBGNom_VR1_FGD1_FHC_obs_selelec_costheta_ldm)=(*hotherBGNom_VR1_FGD1_FHC_obs_selelec_costheta_ldm)+(*hotherBGNom_VR1_FGD2_FHC_obs_selelec_costheta_ldm)+(*hotherBGNom_VR1_FGD1_RHC_obs_selelec_costheta_ldm)+(*hotherBGNom_VR1_FGD2_RHC_obs_selelec_costheta_ldm)




hData_VR1_FGD1_FHC_obs_selelec_mom->Write()
hccnueNom_VR1_FGD1_FHC_obs_selelec_mom->Write()
hnuEleElasticNom_VR1_FGD1_FHC_obs_selelec_mom->Write()
hotherBGNom_VR1_FGD1_FHC_obs_selelec_mom->Write()

_file0->Write()
_file0->Close()

