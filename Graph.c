//данная программа предназначена для построения графиков по массиву точек (root)
#include <iostream>
#include <cmath>

using namespace std;
void Graph()
{


 TCanvas *c1 = new TCanvas("c1","",200,10,700,500);
  c1->SetFillColor(42);//необходимо для задания цвета фона рисунка

  c1->SetGrid();

//c1->GetFrame()->SetFillColor(21);

  c1->GetFrame()->SetBorderSize(12);

// создаются массивы значений
 Int_t n=8;

 Float_t x[8] = {0,0.03,0.06,0.09,0.12,0.15,0.18,0.21};

 Float_t y[8] = {8.481773246,	8.328934042	,8.219326094,	8.171882006,	8.033009499,	7.972121129	,7.902117546,	7.80139132};
 
 Float_t y1[9] = {0};


// создаются массивы погрешностей (если погрешностей нет оставить 0)

 Float_t ex[8] = {0,0,0,0,0,0,0,0};
 Float_t ey[8] = {0.033909233,	0.039001102,	0.043158976	,0.04510407,	0.051354925,	0.054380249,	0.058093036,	0.063911044};

// апроксимация графика (нахождение коэфициентов в ур-ии y[i]=cf*x[i]+fr методом наименьших квадратов)

  double sx=0,sy=0,sxx=0,sxy=0;
  for(int i=0;i<n;i++){
    sx+=x[i];
    sy+=y[i];
    sxx+=x[i]*x[i];
    sxy+=x[i]*y[i];
  }
  double det=sxx*n-sx*sx;
  double fr,cf;
  fr=(sxx*sy-sxy*sx)/det;
  cf=(sxy*n-sx*sy)/det;
  
// заполнение массива точек прямой 
   for(int i=0;i<n;i++){
	   y1[i]=cf*x[i]+fr;
   }
 
// создание и построение график
 TGraphErrors *gr1 = new TGraphErrors(n,x,y1,ex,ex);
 TGraphErrors *gr = new TGraphErrors(n,x,y,ex,ey);

gr->SetTitle("Absorptivuty");

gr->SetMarkerColor(4);

gr->SetMarkerStyle(21);

gr->Draw("ALP");
gr1->SetLineColor(6);
gr1->Draw("same");

c1->Update();

}