

void mygStyleSetup(){
//gStyle//////////////////////////////////
 gStyle->SetOptStat(00000);
 //gStyle->SetOptStat(00000);
 //gStyle->SetOptTitle(0);
 gStyle->SetHistLineWidth(2);
 gStyle->SetLineWidth(3);
 gStyle -> SetFrameLineWidth(3);
 //gStyle->SetLabelSize(0.035,"X");
 gStyle->SetTitleXOffset(1.2);
 gStyle->SetTitleYOffset(1.35);
 gStyle->SetLabelColor(1,"X");
 gStyle->SetLabelColor(1,"Y");
 //gStyle->SetMarkerStyle(20);
 gStyle -> SetMarkerSize(1);
 gStyle -> SetLabelSize(0.045,"X");
 gStyle -> SetLabelSize(0.045,"Y");
 gStyle -> SetTitleSize(0.045,"XY");
 gStyle -> SetPadLeftMargin(0.14);
 gStyle -> SetPadBottomMargin(0.13);

 gStyle->SetLineStyleString(11,"50 80");
 gStyle->SetLineStyleString(12,"20 20");
 gStyle->SetLineStyleString(13,"20 120");
}

int read(const char file_name[], double ix[], double iy[]){
	ifstream myfile(file_name);
	int cnt=0;
	int num=0;
	double temp=0;
	string str;

	do	{
		if (!myfile.good())
		{
			cout<<"File ends or no file; number of raws is 0"<<endl;
			break;
		};

		temp =0;
		myfile>>temp;

		switch (cnt%2) {
			case 0:
				ix[num]	= temp;
				break;
			case 1:
				iy[num]	=	temp;
				num++;
				break;
      default:
        break;
		}
		cnt++;

	} while(myfile.good());

	myfile.close();
	return num;
}

TGraph* read_file(const char file_name[], int irul=0){
  ifstream in;
  in.open(file_name);

  Double_t x[200], y[200];
  int npoints=0;
  while (1) {
    Double_t x1,y1;
    in >> x1 >> y1;
    if (!in.good()) break;

    if(y1==0)continue;
    x[npoints] = x1/3.;  // LDM mass
    Double_t epsilon = 0.001*pow(y1,1./4.);
    y[npoints]= pow(epsilon,2)*0.5*pow(1./3.,4.);
  //  if(irul)std::cout<<"  "<<x1/*x[npoints]*/<<"  "<<y[npoints]<<std::endl;

    npoints++;
  }

  TGraph* gr = new TGraph(npoints,x,y);
  gr->SetName("YMx_limits");
  gr->SetTitle("YMx_limits");
  return gr;
}


void ana_sensitivity(){
  //canvas
  mygStyleSetup();

  const int N = 9;
  TGraph *lines[N];
  double x_t[1000], y_t[1000], x[N][1000], y[N][1000];
	int point_t, points[N];
  int colors[N] = {1,1,1,403,411,434,591,402,618};

  // text_bosxes parameters
  TText *t[N];
  char text[N][400] = {"Scalar Relic","Majorana Relic","Pseudo Dirac Fermion Relic", "BaBar","E137","LSND","MB-e","MB-N", "NA64"};
  int angle[N] = {36,36,33,0,17,0,50,0,0};
  double xy[N][2] = {{0.006,0.000000000005},{0.006,0.000000000003},{0.07,0.000000000025},{0.002,0.000000008},{0.0013,0.000000000007},{0.035,0.00000006},{0.11,0.00000006},{0.005,0.0000000012},
  {0.15,0.00000001}};

  auto gr0 =  read_file("data/fgd_data.dat",1);
  gr0->SetLineColor(1);
  gr0->SetLineWidth(3);

  auto gr1 =  read_file("data/fgd_sen.dat");
  gr1->SetLineColor(2);
  gr1->SetLineWidth(3);
  gr1->SetLineStyle(9);

  auto gr2 =  read_file("data/all_results_sys0.dat");
  gr2->SetLineColor(8);
  gr2->SetLineWidth(3);

  auto gr3 =  read_file("data/all_results_sys0.dat");
  gr3->SetLineColor(1);
  gr3->SetLineWidth(3);


  // Excluded
	point_t = read("lines/top_line",x_t,y_t);

  x_t[point_t] = 0.001;
  y_t[point_t] = 1.e-07;
  point_t++;

  x_t[point_t] = 1.97035;
  y_t[point_t] = 1.e-07;
  point_t++;

  TGraph* top_line = new TGraph(point_t, x_t, y_t);
  top_line->SetLineWidth(3);
  top_line->SetLineColorAlpha(590, 0.5);
  top_line->SetFillColorAlpha(590, 0.5);

  // other lines
  points[0] = read("lines/Scalar_relic_line",x[0],y[0]);
  points[1] = read("lines/Majorana_relic_line",x[1],y[1]);
  points[2] = read("lines/Pseudo_Dirac_fermion_relic_line",x[2],y[2]);
  points[3] = read("lines/BaBar",x[3],y[3]);
  points[4] = read("lines/E137",x[4],y[4]);
  points[5] = read("lines/LSND",x[5],y[5]);
  points[6] = read("lines/MB-e",x[6],y[6]);
  points[7] = read("lines/MB-N",x[7],y[7]);
  points[8] = read("lines/NA64",x[8],y[8]);


  for (size_t i = 0; i < N; i++) {
    lines[i] = new TGraph(points[i], x[i], y[i]);
    lines[i]->SetLineWidth(1);
    lines[i]->SetLineColor(colors[i]);
  }

  auto c = new TCanvas("c", "c", 1600, 900);
  c->SetLogy();
  c->SetLogx();
  gPad->SetTickx();
  gPad->SetTicky();

  TH1F *hfr = c->DrawFrame(0.001,1e-12,1.97035,1e-7);
  hfr->SetYTitle("Y=#epsilon^{2}#alpha_{D}(m_{#chi}/m_{V})^{4}");
  hfr->SetXTitle("M_{#chi}, GeV");
  //hfr->SetTitle("ND280 sensitivity to LDM");
  //hfr->SetTitle("LDM search at ND280");
  hfr->GetXaxis()->CenterTitle();
  hfr->GetYaxis()->CenterTitle();

  top_line->Draw("LF same");

  for (size_t i = 0; i < N; i++) {
    lines[i]->Draw("same");
  }
  gr0->Draw("same");
  gr1->Draw("same");
  //  gr2->Draw("same");
  //  gr3->Draw("same");

  //text_bosxes
  for (size_t i = 0; i < N; i++) {
    t[i] = new TText(xy[i][0],xy[i][1],text[i]);
    t[i]->SetTextAlign(22);
    t[i]->SetTextColor(colors[i]);
    t[i]->SetTextFont(43);
    t[i]->SetTextSize(18);
    t[i]->SetTextAngle(angle[i]);
    t[i]->Draw();
  }

  // legend
  TLegend* leg = new TLegend(0.6,0.17,0.8,0.3);
  leg->SetBorderSize(0);
  leg->AddEntry(gr0,"Data","lp");
  leg->AddEntry(gr1,"Expected","lp");
//  leg->AddEntry(gr2,"FGD + P0D 10\%  overall syst.","lp");
//  leg->AddEntry(gr3,"FGD + P0D 40\%  overall syst.","lp");
  leg->AddEntry(top_line,"Excluded","f");
  leg->Draw();
  
  c->RedrawAxis();
  c->Update();
  c->SaveAs("res.png");
  //c->SaveAs("sen.png");
}
