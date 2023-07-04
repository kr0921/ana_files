
syst_list="sipion_syst
siproton_syst
all_syst
bfield_syst
momscale_syst
momresol_syst
tpcpid_syst
fgdpid_syst
ecal_emresol_syst
ecal_emscale_syst
tof_resol_syst
chargeideff_syst
tpctrackeff_syst
tpcfgdmatcheff_syst
fgdmass_syst
tpcclustereff_syst
tpc_ecal_matcheff_syst
ecal_pid_syst
ecal_emhippid_syst
fgd2shower_syst
nuetpcpileup_syst
nuep0dpileup_syst
nueecalpileup_syst
nueoofv_syst
nuparent_decaypos_syst
tpc_angres_syst
va_syst"


syst_list1="momresol_syst tpc_angres_syst"

### LDM ##################
###DO CALCULATIONS
#for syst in $syst_list
#do
# echo $syst
# root.exe -q dsyst.C\(\"$syst\",1\) > ${syst}.log 2>&1 
# root.exe -q dsyst.C\(\"$syst\",2\) >> ${syst}.log 2>&1 
#done

###BUILD PLOTS
#for syst in $syst_list
#do
# echo $syst
# root.exe -q dsyst.C\(\"$syst\",0\)
#done
### LDM ##################






###NEUT && GENIE
#for syst in $syst_list
#do
# echo $syst
# root.exe -q dsyst.C\(\"$syst\",-1\)
#done





#
for syst in $syst_list
do
 #echo $syst
 fgd1=`grep $syst dsyst.log|grep FGD1|grep nuEleElastic|grep FHC`
 fgd2=`grep $syst dsyst.log|grep FGD2|grep nuEleElastic|grep FHC`
 echo $fgd1"      "$fgd2
done
 
 echo "     "
 echo "     "
 echo "     "
 
for syst in $syst_list
do
 #echo $syst
 fgd1=`grep $syst dsyst.log|grep FGD1|grep nuEleElastic|grep RHC`
 fgd2=`grep $syst dsyst.log|grep FGD2|grep nuEleElastic|grep RHC`
 echo $fgd1"      "$fgd2
done
 
 echo "     "
 echo "     "
 echo "     "
 
for syst in $syst_list
do
 fgd1=`grep $syst dsyst.log|grep FGD1|grep ccnue|grep FHC`
 fgd2=`grep $syst dsyst.log|grep FGD2|grep ccnue|grep FHC`
 echo $fgd1"      "$fgd2
done
 
 echo "     "
 echo "     "
 echo "     "
 
for syst in $syst_list
do
 fgd1=`grep $syst dsyst.log|grep FGD1|grep ccnue|grep RHC`
 fgd2=`grep $syst dsyst.log|grep FGD2|grep ccnue|grep RHC`
 echo $fgd1"      "$fgd2
done
 
 echo "     "
 echo "     "
 echo "     "
 
for syst in $syst_list
do
 fgd1=`grep $syst dsyst.log|grep FGD1|grep otherBG|grep FHC`
 fgd2=`grep $syst dsyst.log|grep FGD2|grep otherBG|grep FHC`
 echo $fgd1"      "$fgd2
done
 
 echo "     "
 echo "     "
 echo "     "
 
for syst in $syst_list
do
 fgd1=`grep $syst dsyst.log|grep FGD1|grep otherBG|grep RHC`
 fgd2=`grep $syst dsyst.log|grep FGD2|grep otherBG|grep RHC`
 echo $fgd1"      "$fgd2
done





