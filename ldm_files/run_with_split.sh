#!/bin/bash
# This script to run over large list file by spliting it 

#Usage:sh run_with_split.sh [parameter(dat)_file] [file_list] [N_parts] [job_name]
#Example: sh run_with_split.sh myLDMAnalysis.FGD1.parameters.dat production006_B_mcp_genie_2010-11-air_magnet_run3_anal.list 300 production006_B_mcp_genie_2010-11-air_magnet_run3_anal

function mynjobs {
 jobs| wc -l
}

function mywait {
  njobs=`mynjobs`
  while [ "$njobs" -gt $1 ]
  do
    sleep $2
    njobs=`mynjobs`
  done
}

rm -rf $4
mkdir $4
cd $4
split -a 5 -d -n l/$3 ../$2
mylist=`ls x00*`
echo $mylist

for mypart in $mylist
do
  echo "../bin/RunLDMAnalysis.exe -v -o $mypart.root -p ../$1 $mypart > $mypart.log 2>&1"
  nice ../bin/RunLDMAnalysis.exe -v -o $mypart.root -p ../$1 $mypart > $mypart.log 2>&1 &
  mywait 4 60
done
wait
echo "Run hadd..."
echo "hadd $4.root x00*.root > hadd.log 2>&1"
hadd $4.root x00*.root > hadd.log 2>&1
###rm x00*

