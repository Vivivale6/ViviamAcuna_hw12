#include <iostream>
#include <cstdlib>
#include <ctime>
#include <math.h>

using namespace std;

int main(){
  //Se declaran las condiciones iniciales
  double c=1.0;
  double t=0.5;

  // Se declaran los valores de y que se van actualizando
  double *y;
  double *y_viejo;
  double *y_nuevo;
  double delta_x=0.1;
  double delta_t=0.0001;

  //Se declaran las condiciones de x
  double min = -2.0;
  double max = 2.0;
  double x = 0.0;
  int nt = 700 ;
  int nx = ((max-min)/delta_x) +1;
  

  int i ;
  int j;

  //Se inicializan los punteros 
  y = new double[nx];
  y_viejo= new double[nx];
  y_nuevo= new double[nx];

  for (i =0; i<nx; i++){
    
    // Se inicializa la funcion con las condiciones
    x = min + i*delta_x;
    
    if(x >= -0.5  && x <= 0.5){
      
      y_viejo[i]= 0.5;
      
    }else{
      
      y_viejo[i]= 0.0;
      
      }
  }
  for (j=1; j< nt; j++){
    
    y_nuevo[0]=0;
    
    y_viejo[nx-1]=0;
    
    for (i=1; i<nx-1;i++){
      //Se realiza la condicion 
      
      y_nuevo[i] = y_viejo[i] - c*(delta_t/delta_x)*(y_viejo[i] - y_viejo[i-1]);
    }
    
    for (i=0; i < nx; i++){
      
      //Se actualizan los valores de y nuevo
      
      y_viejo[i]= y_nuevo[i];
    }
    
   if (j*700/4==0){
     
     // Se imprimen los 5 snapshots
      
      for (i=0; i < nx ; i++){
	
    	cout << x <<" " << y_nuevo[i]<< endl;
	
	x+= delta_x;
      } 
    
    }
   
  }

  return 0;
}
