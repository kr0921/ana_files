


myruns="nd280Highland2_v2r45_1_data_run7b
nd280Highland2_v2r45_1_data_run7c_water
nd280Highland2_v2r45_1_data_run8_air_fhc
nd280Highland2_v2r45_1_data_run8_water_fhc
nd280Highland2_v2r45_1_data_run9a_water_rhc
nd280Highland2_v2r45_1_data_run9b_water_rhc
nd280Highland2_v2r45_1_data_run9c_water_rhc
nd280Highland2_v2r45_1_data_run9d_water_rhc
nd280Highland2_v2r45_1_MC_run7water
nd280Highland2_v2r45_1_MC_run8air
nd280Highland2_v2r45_1_MC_run8water
nd280Highland2_v2r45_1_MC_run9water"

for myrun in $myruns
do
bin/RunMomRangeSystematics.exe -o ${myrun}.root ${myrun}.list
done



