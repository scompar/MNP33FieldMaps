#include "TH2.h"
#include "TCanvas.h"
#include "TBox.h"
#include "TStyle.h"

void ReadMNP33(){

double zdip = 445.;
double zMS0 = 300.;
double zMS1 = 340.;
double zMS2 = 550.;
double zMS3 = 590.;
double zMS4 = 810.;
double zMS5 = 850.;

zMS0-=zdip;
zMS1-=zdip;
zMS2-=zdip;
zMS3-=zdip;
zMS4-=zdip;
zMS5-=zdip;

gStyle->SetOptStat(0);
gStyle->SetTitleYOffset(1.3);


FILE *fp;
 long double Bx;
 long double By;
 long double Bz;
 long double x,y,z;

TH2D *hx0 = new TH2D("hx0","By at x=0 cm (center of dipole)",51,-127.5,127.5,51,-127.5,127.5);
hx0->GetXaxis()->SetTitle("z(cm)");
hx0->GetYaxis()->SetTitle("y(cm)");
TH2D *hy0 = new TH2D("hy0","By at y=0 cm (center of dipole)",51,-127.5,127.5,51,-127.5,127.5);
hy0->GetXaxis()->SetTitle("z(cm)");
hy0->GetYaxis()->SetTitle("y(cm)");
TH2D *hz0 = new TH2D("hz0","By at z=0 cm (center of dipole)",51,-127.5,127.5,51,-127.5,127.5);
hz0->GetXaxis()->SetTitle("x(cm)");
hz0->GetYaxis()->SetTitle("y(cm)");

TH2D *hMS0Bx = new TH2D("hMS0Bx","Bx at MS0",35,-87.5,87.5,35,-87.,87.5);
hMS0Bx->GetXaxis()->SetTitle("x(cm)");
hMS0Bx->GetYaxis()->SetTitle("y(cm)");
TH2D *hMS1Bx = new TH2D("hMS1Bx","Bx at MS1",51,-127.5,127.5,51,-127.5,127.5);
hMS1Bx->GetXaxis()->SetTitle("x(cm)");
hMS1Bx->GetYaxis()->SetTitle("y(cm)");
TH2D *hMS2Bx = new TH2D("hMS2Bx","Bx at MS2",51,-127.5,127.5,51,-127.5,127.5);
hMS2Bx->GetXaxis()->SetTitle("x(cm)");
hMS2Bx->GetYaxis()->SetTitle("y(cm)");
TH2D *hMS3Bx = new TH2D("hMS3Bx","Bx at MS3",65,-162.5,162.5,65,-162.5,162.5);
hMS3Bx->GetXaxis()->SetTitle("x(cm)");
hMS3Bx->GetYaxis()->SetTitle("y(cm)");
TH2D *hMS4Bx = new TH2D("hMS4Bx","Bx at MS4",89,-222.5,222.5,89,-222.5,222.5);
hMS4Bx->GetXaxis()->SetTitle("x(cm)");
hMS4Bx->GetYaxis()->SetTitle("y(cm)");
TH2D *hMS5Bx = new TH2D("hMS5Bx","Bx at MS5",93,-232.5,232.5,93,-232.5,232.5);
hMS5Bx->GetXaxis()->SetTitle("x(cm)");
hMS5Bx->GetYaxis()->SetTitle("y(cm)");

TH2D *hMS0By = new TH2D("hMS0By","By at MS0",35,-87.5,87.5,35,-87.,87.5);
hMS0By->GetXaxis()->SetTitle("x(cm)");
hMS0By->GetYaxis()->SetTitle("y(cm)");
TH2D *hMS1By = new TH2D("hMS1By","By at MS1",51,-127.5,127.5,51,-127.5,127.5);
hMS1By->GetXaxis()->SetTitle("x(cm)");
hMS1By->GetYaxis()->SetTitle("y(cm)");
TH2D *hMS2By = new TH2D("hMS2By","By at MS2",51,-127.5,127.5,51,-127.5,127.5);
hMS2By->GetXaxis()->SetTitle("x(cm)");
hMS2By->GetYaxis()->SetTitle("y(cm)");
TH2D *hMS3By = new TH2D("hMS3By","By at MS3",65,-162.5,162.5,65,-162.5,162.5);
hMS3By->GetXaxis()->SetTitle("x(cm)");
hMS3By->GetYaxis()->SetTitle("y(cm)");
TH2D *hMS4By = new TH2D("hMS4By","By at MS4",89,-222.5,222.5,89,-222.5,222.5);
hMS4By->GetXaxis()->SetTitle("x(cm)");
hMS4By->GetYaxis()->SetTitle("y(cm)");
TH2D *hMS5By = new TH2D("hMS5By","By at MS5",93,-232.5,232.5,93,-232.5,232.5);
hMS5By->GetXaxis()->SetTitle("x(cm)");
hMS5By->GetYaxis()->SetTitle("y(cm)");

TH2D *hMS0Bz = new TH2D("hMS0Bz","Bz at MS0",35,-87.5,87.5,35,-87.,87.5);
hMS0Bz->GetXaxis()->SetTitle("x(cm)");
hMS0Bz->GetYaxis()->SetTitle("y(cm)");
TH2D *hMS1Bz = new TH2D("hMS1Bz","Bz at MS1",51,-127.5,127.5,51,-127.5,127.5);
hMS1Bz->GetXaxis()->SetTitle("x(cm)");
hMS1Bz->GetYaxis()->SetTitle("y(cm)");
TH2D *hMS2Bz = new TH2D("hMS2Bz","Bz at MS2",51,-127.5,127.5,51,-127.5,127.5);
hMS2Bz->GetXaxis()->SetTitle("x(cm)");
hMS2Bz->GetYaxis()->SetTitle("y(cm)");
TH2D *hMS3Bz = new TH2D("hMS3Bz","Bz at MS3",65,-162.5,162.5,65,-162.5,162.5);
hMS3Bz->GetXaxis()->SetTitle("x(cm)");
hMS3Bz->GetYaxis()->SetTitle("y(cm)");
TH2D *hMS4Bz = new TH2D("hMS4Bz","Bz at MS4",89,-222.5,222.5,89,-222.5,222.5);
hMS4Bz->GetXaxis()->SetTitle("x(cm)");
hMS4Bz->GetYaxis()->SetTitle("y(cm)");
TH2D *hMS5Bz = new TH2D("hMS5Bz","Bz at MS5",93,-232.5,232.5,93,-232.5,232.5);
hMS5Bz->GetXaxis()->SetTitle("x(cm)");
hMS5Bz->GetYaxis()->SetTitle("y(cm)");

char null[100];
fp = fopen("mnp33_fieldmap_5cm.dat","r");

for(int i=0;i<10;i++)fgets(null,80,fp); //skip header lines

for (int i=0;i<61 ;i++){
  for (int j=0;j<61;j++){
    for (int k=0;k<101;k++){
      fscanf(fp,"%Lf %Lf %Lf %Lf %Lf %Lf",&x,&y,&z,&Bx,&By,&Bz);
      
      if (x==0.) {
        if(z>hx0->GetXaxis()->GetXmin() && z<hx0->GetXaxis()->GetXmax() && y>hx0->GetYaxis()->GetXmin() && y<hx0->GetYaxis()->GetXmax()){
//        printf("x=0: x %3.2Lf y %3.2Lf z %3.2Lf Bx %5.5Lf By %5.5Lf Bz %5.5Lf\n",x,y,z,Bx,By,Bz);
        hx0->Fill(z,y,By);
        if(z!=0) hx0->Fill(-z,y,By);
        if(y!=0) hx0->Fill(z,-y,By);
        if(z!=0 && y!=0) hx0->Fill(-z,-y,By);
      }
      }
      if (y==0.) {
        hy0->Fill(z,x,By);
        if(z!=0) hy0->Fill(-z,x,By);
        if(x!=0) hy0->Fill(z,-x,By);
        if(z!=0 && x!=0) hy0->Fill(-z,-x,By);
      }
      if (z==0.) {
        hz0->Fill(x,y,By);	
        if(x!=0) hz0->Fill(-x,y,By);
        if(y!=0) hz0->Fill(x,-y,By);
        if(x!=0 && y!=0) hz0->Fill(-x,-y,By);
      }
      
      if (abs(z-abs(zMS0))<2.5){ 
        printf("MS0: x %3.2Lf y %3.2Lf z %3.2Lf Bx %5.5Lf By %5.5Lf Bz %5.5Lf\n",x,y,z,Bx,By,Bz);
        hMS0Bx->Fill(x,y,Bx);
        hMS0By->Fill(x,y,By);
        hMS0Bz->Fill(x,y,Bz);
        if(x!=0){
	  hMS0Bx->Fill(-x,y,Bx);
	  hMS0By->Fill(-x,y,By);
	  hMS0Bz->Fill(-x,y,Bz);
	}
        if(y!=0){
	  hMS0Bx->Fill(x,-y,Bx);
	  hMS0By->Fill(x,-y,By);
	  hMS0Bz->Fill(x,-y,Bz);
	}
        if(x!=0 && y!=0){
	  hMS0Bx->Fill(-x,-y,Bx);
	  hMS0By->Fill(-x,-y,By);
	  hMS0Bz->Fill(-x,-y,Bz);
	}
      }
      	
      if (abs(z-abs(zMS1))<2.5){
        printf("MS1: x %3.2Lf y %3.2Lf z %3.2Lf Bx %5.5Lf By %5.5Lf Bz %5.5Lf\n",x,y,z,Bx,By,Bz);
        hMS1Bx->Fill(x,y,Bx);
        hMS1By->Fill(x,y,By);
        hMS1Bz->Fill(x,y,Bz);
        if(x!=0){
	  hMS1Bx->Fill(-x,y,Bx);
	  hMS1By->Fill(-x,y,By);
	  hMS1Bz->Fill(-x,y,Bz);
	}
        if(y!=0){
	  hMS1Bx->Fill(x,-y,Bx);
	  hMS1By->Fill(x,-y,By);
	  hMS1Bz->Fill(x,-y,Bz);
        }
	if(x!=0 && y!=0){
	  hMS1Bx->Fill(-x,-y,Bx);
	  hMS1By->Fill(-x,-y,By);
	  hMS1Bz->Fill(-x,-y,Bz);
	}
      }
      
      if (abs(z-abs(zMS2))<2.5){
        printf("MS2: x %3.2Lf y %3.2Lf z %3.2Lf Bx %5.5Lf By %5.5Lf Bz %5.5Lf\n",x,y,z,Bx,By,Bz);
        hMS2Bx->Fill(x,y,Bx);
        hMS2By->Fill(x,y,By);
        hMS2Bz->Fill(x,y,Bz);
        if(x!=0){
	  hMS2Bx->Fill(-x,y,Bx);
	  hMS2By->Fill(-x,y,By);
	  hMS2Bz->Fill(-x,y,Bz);
	}
        if(y!=0){
	  hMS2Bx->Fill(x,-y,Bx);
	  hMS2By->Fill(x,-y,By);
	  hMS2Bz->Fill(x,-y,Bz);
        }
	if(x!=0 && y!=0){
	  hMS2Bx->Fill(-x,-y,Bx);
	  hMS2By->Fill(-x,-y,By);
	  hMS2Bz->Fill(-x,-y,Bz);
	}
      }
      
      if (abs(z-abs(zMS3))<2.5){
        printf("MS3: x %3.2Lf y %3.2Lf z %3.2Lf Bx %5.5Lf By %5.5Lf Bz %5.5Lf\n",x,y,z,Bx,By,Bz);
        hMS3Bx->Fill(x,y,Bx);
        hMS3By->Fill(x,y,By);
        hMS3Bz->Fill(x,y,Bz);
        if(x!=0){
	  hMS3Bx->Fill(-x,y,Bx);
	  hMS3By->Fill(-x,y,By);
	  hMS3Bz->Fill(-x,y,Bz);
	}
        if(y!=0){
	  hMS3Bx->Fill(x,-y,Bx);
	  hMS3By->Fill(x,-y,By);
	  hMS3Bz->Fill(x,-y,Bz);
        }
	if(x!=0 && y!=0){
	  hMS3Bx->Fill(-x,-y,Bx);
	  hMS3By->Fill(-x,-y,By);
	  hMS3Bz->Fill(-x,-y,Bz);
	}
      }
      
      if (abs(z-abs(zMS4))<2.5){ 
        printf("MS4: x %3.2Lf y %3.2Lf z %3.2Lf Bx %5.5Lf By %5.5Lf Bz %5.5Lf\n",x,y,z,Bx,By,Bz);
        hMS4Bx->Fill(x,y,Bx);
        hMS4By->Fill(x,y,By);
        hMS4Bz->Fill(x,y,Bz);
        if(x!=0){
	  hMS4Bx->Fill(-x,y,Bx);
	  hMS4By->Fill(-x,y,By);
	  hMS4Bz->Fill(-x,y,Bz);
	}
        if(y!=0){
	  hMS4Bx->Fill(x,-y,Bx);
	  hMS4By->Fill(x,-y,By);
	  hMS4Bz->Fill(x,-y,Bz);
        }
	if(x!=0 && y!=0){
	  hMS4Bx->Fill(-x,-y,Bx);
	  hMS4By->Fill(-x,-y,By);
	  hMS4Bz->Fill(-x,-y,Bz);
	}
      }
      if (abs(z-abs(zMS5))<2.5){
        printf("MS5: x %3.2Lf y %3.2Lf z %3.2Lf Bx %5.5Lf By %5.5Lf Bz %5.5Lf\n",x,y,z,Bx,By,Bz);
        hMS5Bx->Fill(x,y,Bx);
        hMS5By->Fill(x,y,By);
        hMS5Bz->Fill(x,y,Bz);
        if(x!=0){
	  hMS5Bx->Fill(-x,y,Bx);
	  hMS5By->Fill(-x,y,By);
	  hMS5Bz->Fill(-x,y,Bz);
	}
        if(y!=0){
	  hMS5Bx->Fill(x,-y,Bx);
	  hMS5By->Fill(x,-y,By);
	  hMS5Bz->Fill(x,-y,Bz);
        }
	if(x!=0 && y!=0){
	  hMS5Bx->Fill(-x,-y,Bx);
	  hMS5By->Fill(-x,-y,By);
	  hMS5Bz->Fill(-x,-y,Bz);
	}
      }
    }
  }
}
//TBox *b = new TBox(-0.15,-0.15,0.15,0.15);
//b->SetFillColor(kRed);

TCanvas *cx0 = new TCanvas("cx0","cx0",800,800);
cx0->SetRightMargin(0.13);
hx0->Draw("colz");
TCanvas *cy0 = new TCanvas("cy0","cy0",800,800);
cy0->SetRightMargin(0.13);
hy0->Draw("colz");
TCanvas *cz0 = new TCanvas("cz0","cz0",800,800);
cz0->SetRightMargin(0.13);
hz0->Draw("colz");


TCanvas *cMSBx = new TCanvas("cMSBx","cMSBx",1200,700);
cMSBx->Divide(3,2);
cMSBx->cd(1);
gPad->SetRightMargin(0.15);
hMS0Bx->Draw("colz");
cMSBx->cd(2);
gPad->SetRightMargin(0.15);
hMS1Bx->Draw("colz");
cMSBx->cd(3);
gPad->SetRightMargin(0.15);
hMS2Bx->Draw("colz");
cMSBx->cd(4);
gPad->SetRightMargin(0.15);
hMS3Bx->Draw("colz");
cMSBx->cd(5);
gPad->SetRightMargin(0.15);
hMS4Bx->Draw("colz");
cMSBx->cd(6);
gPad->SetRightMargin(0.15);
hMS5Bx->Draw("colz");

TCanvas *cMSBy = new TCanvas("cMSBy","cMSBy",1200,700);
cMSBy->Divide(3,2);
cMSBy->cd(1);
gPad->SetRightMargin(0.15);
hMS0By->Draw("colz");
cMSBy->cd(2);
gPad->SetRightMargin(0.15);
hMS1By->Draw("colz");
cMSBy->cd(3);
gPad->SetRightMargin(0.15);
hMS2By->Draw("colz");
cMSBy->cd(4);
gPad->SetRightMargin(0.15);
hMS3By->Draw("colz");
cMSBy->cd(5);
gPad->SetRightMargin(0.15);
hMS4By->Draw("colz");
cMSBy->cd(6);
gPad->SetRightMargin(0.15);
hMS5By->Draw("colz");

TCanvas *cMSBz = new TCanvas("cMSBz","cMSBz",1200,700);
cMSBz->Divide(3,2);
cMSBz->cd(1);
gPad->SetRightMargin(0.15);
hMS0Bz->Draw("colz");
cMSBz->cd(2);
gPad->SetRightMargin(0.15);
hMS1Bz->Draw("colz");
cMSBz->cd(3);
gPad->SetRightMargin(0.15);
hMS2Bz->Draw("colz");
cMSBz->cd(4);
gPad->SetRightMargin(0.15);
hMS3Bz->Draw("colz");
cMSBz->cd(5);
gPad->SetRightMargin(0.15);
hMS4Bz->Draw("colz");
cMSBz->cd(6);
gPad->SetRightMargin(0.15);
hMS5Bz->Draw("colz");

}
