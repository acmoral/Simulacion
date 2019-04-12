#include<iostream>
#include<cmath>
using namespace std;

const double ERR=1e-7;//error

double f(int n,double x,double t){
  return cos(n*t-x*sin(t));//función que se va a integrar
}
//simpson para pequeños intervalos, integrados ne total se obtiene algo mas preciso. 
double IntegralPorSimpson(int n,double x,double a,double b,int N){
  int DosN=2*N;//se divide en 2N partes
  double h=(b-a)/DosN;//tamaño de cada dx a sumar
  int i; double t;
  double suma=0;
  for(i=0;i<=DosN;i++){
    t=a+h*i;
    
    if(i==0|| i==DosN)
      suma+=f(n,x,t);//se suman los extremos como f(a) 
    else if(i%2==1)
      suma+=4*f(n,x,t);//los f(m) del medio son los pares
    else
      suma+=2*f(n,x,t);// el resto son f(b)
  }  
  return suma*h/3;
}

double Bessel(int n,double x){
  return 1/M_PI*IntegralPorSimpson(n,x,0,M_PI,50);
}

int main(void){
  int n=0; double x;
  
  for(x=0;x<10;x+=0.1)
    cout<<x<<" "<<Bessel(n,x)<<endl;
  
  return 0;
}
