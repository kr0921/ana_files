
#Example: sh checkGRooTrackerVtx.sh production006_B_mcp_anti-genie_2010-11-air_magnet_run6_anal.list

rm 000_ok_files_list 000_bad_files_list

file_list=`cat $1`

echo "{" > 000.C
echo "TTree* ttt; _file0->GetObject(\"TruthDir/GRooTrackerVtx\",ttt); " >> 000.C
echo "if(ttt)std::cout<<\"000000 \"<<_file0->GetName()<<std::endl; " >> 000.C
echo "if(!ttt)std::cout<<\"111111 \"<<_file0->GetName()<<std::endl; " >> 000.C
echo "}" >> 000.C

nnn=0
for file in $file_list
do
 #echo $file
 root.exe -q $file 000.C > 000.log 2>&1
 grep 000000 000.log|awk '{print $2}' >> 000_ok_files_list
 grep 111111 000.log|awk '{print $2}' >> 000_bad_files_list
 nnn=$(( $nnn + 1 ))
 echo $nnn
done



