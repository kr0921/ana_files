

double level_90low(TH1* h){
    //double my_minw68 = 9999999.;
    double tots = h->Integral(1,h->GetNbinsX())+h->GetBinContent(0)+h->GetBinContent(h->GetNbinsX()+1);
    
//    for(int i=1; i<=h->GetNbinsX(); i++){
//        if((h->Integral(i,h->GetNbinsX())+h->GetBinContent(h->GetNbinsX()+1))/tots<0.69)break;
        
        int i=1;
        int ii1=i+1;
        int ii2=h->GetNbinsX();
        int ix=(ii1+ii2)/2.;
        double lev90 = -999.;
        while(ii2-ii1 >= 2 ){
          ix=(ii1+ii2)/2.;
          if(h->Integral(i,ix)/tots>0.1)ii2=ix;
          else ii1=ix;
        }
        lev90 = h->GetBinCenter(ix);
std::cout<<ix<<"  lev90="<<lev90<<"    lev="<<h->Integral(i,ix)/tots<<std::endl;
        //if( (double)(ii2-i)*h->GetBinWidth(i)<my_minw68) my_minw68=(double)(ii2-i)*h->GetBinWidth(i);
        
//        for(int ii=i+1; ii<=h->GetNbinsX(); ii++){
//            if((h->Integral(1,ii)+h->GetBinContent(0))/tots<0.69)continue;
//            if(h->Integral(i,ii)/tots>0.68 && (double)(ii-i)*h->GetBinWidth(i)<my_minw68) my_minw68=(double)(ii-i)*h->GetBinWidth(i);
//        }
//    }
    return lev90;
}

double level_low(TH1* h, float cut){
    double tots = h->Integral(1,h->GetNbinsX())+h->GetBinContent(0)+h->GetBinContent(h->GetNbinsX()+1);
    int ibin = h->FindBin(cut);
    return h->Integral(0,ibin)/tots;
}


void lim90(float bckg, float sgn){ 
    TRandom3 r; 
    TH1F* h1=new TH1F("h1","test1",10000,0,1000); 
    for (int i=0;i<10000;i++) h1->Fill(r.Poisson(bckg+sgn)); 
    h1->Draw();
    
    //level_90low(h1);
    std::cout<<" bg_lev="<<level_low(h1,bckg)<<std::endl;
}


