#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<random>
#include<ctime>
#include<map>

using namespace std;

int main(){

  ofstream salida("salida.data");
  
  //Parametros de la simulacion
  long NumberUnits = 10000;
  long time = 1000000;
  long nu = 0.01;

  //Variables de contador
  long Counter = 0;
  long C=0;
  long r,a,b,A,B;
  
  //Parametros numeros aleatorios
  mt19937 randomGen(time(0));
  uniform_int_distribution <int> diceRoll (1, 10000);
  uniform_int_distribution <int> randI (0,NumberUnits);
  
  //Creacion de Map
  map<int,int> Map;
  
  //Creacion de vector representando unidades de batalla
  vector <long> Units;

  Units.resize(NumberUnits);
  
  //Se ubica una unidad en cada posicion del vector
  for(int i = 0; i < NumberUnits; i++){
    Units[i]=1;
  }

  //Inicio de iteracion temporal
  for(int t=0;t<time;t++){
  
    //Asignacion de peso de probabilidad dependiendo de poder de batalla
    for(int i = 0; i < NumberUnits; i++){
      if (Units[i]==0) continue;
      for(int j = 0; j < Units[i]; j++){
	Map[C+j]=i;
	Counter++;
      }
      C=Counter;
    }

    //a es variable aleatoria sobre los valores de Map
    a=randI(randomGen);
    b=Map[a];
  
    //Si todas las unidades están sobre un componente del vector se reparten
    if(Units[b]==NumberUnits){
    
    }
    
    //A es variable aleatoria sobre los valores de Map, se evita que b=B
    do{
      A=randI(randomGen);
      B=Map[B];
    }
    while(b==B);

    //Variable de probabilidad
    r=diceRoll(randomGen);
    
    //Decisión entre separarse y unirse
    if(r<=(nu*10000)){
      if(Units[b]>1){
	int d=0;
	for(int i=0;i<NumberUnits;i++){
	  if(Units[i]==0){
	    Units[i]=Units[i]+1;
	    d++;
	  }
	  if(d==(Units[b]-1))break;
	}
      }
      Units[b]=1;
    }
    else{
      Units[b]=Units[b]+Units[B];
      Units[B]=0;
    }
  
  }
  //Fin iteracion temporal

  return 0;
}
