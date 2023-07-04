#!/bin/bash
# This script to run over large list file by spliting it 

#Usage:sh run_with_split_on_farm.sh [parameter(dat)_file] [file_list] [N_parts] [job_name]
#Example: sh run_with_split_on_farm.sh myLDMAnalysis.FGD1.parameters.dat test0.list 15 test0


function mynjobs {
 qstat| grep run_ldmana| wc -l
 #jobs| wc -l
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

echo "#!/bin/bash" > run_ldmana.sh
echo ". ../setup.sh" >> run_ldmana.sh
echo "../bin/RunLDMAnalysis.exe -v -o \$1.root -p ../$1 \$1 > \$1.log 2>&1" >> run_ldmana.sh

for mypart in $mylist
do
  echo "../bin/RunLDMAnalysis.exe -v -o $mypart.root -p ../$1 $mypart > $mypart.log 2>&1"

  sbatch  run_ldmana.sh $mypart
  sleep 1
  mywait 99 60
done
mywait 0 60
echo "Run hadd..."
echo "hadd $4.root x00*.root > hadd.log 2>&1"
hadd $4.root x00*.root > hadd.log 2>&1
###rm x00*

