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

  long NumberUnits = 10000;

  long Counter = 0;
  long C=0;
  long r,a,b,A,B;

  mt19937 randomGen(time(0));
  uniform_int_distribution <int> diceRoll (1, 100);
  uniform_int_distribution <int> randI (0,NumberUnits);
  
  map<int,int> Map;
  
  vector <long> Units;

  Units.resize(NumberUnits);
  
  for(int i = 0; i < NumberUnits; i++){
    Units[i]=1;
  }
      
  for(int i = 0; i < NumberUnits; i++){
    if (Units[i]==0) continue;
    for(int j = 0; j < Units[i]; j++){
      Map[C+j]=Units[i];
      Counter++;
    }
    C=Counter;
  }

  
  
  return 0;
}
