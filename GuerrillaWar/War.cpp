#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<random>
#include<ctime>
#include<map>

using namespace std;

int main(){

  long NumberUnits = 1000;

  long Counter = 0;
  long C=0;
  
  mt19937 randomGen(time(0));
  uniform_int_distribution <int> diceRoll (1, 100);
  uniform_int_distribution <int> randI (0,NumberUnits);
  

  map<int,int> Map;
  
  vector <long> Units;

  Units.resize(NumberUnits);
  
  for(int i = 0; i < NumberUnits; i++){
    Units[i]=1;
  }
  
  Units[0]=0;
  Units[1]=0;
  Units[2]=3;
  
  for(int i = 0; i < NumberUnits; i++){
    if (Units[i]==0) continue;
    for(int j = 0; j < Units[i]; j++){
      Map.insert(pair<long,long>(C+j,Units[i]));
      Counter++;
    }
    C=Counter;
  
  }
  

  
  cout << Map[0] <<" "<< Map[1]<<" "<< Map[3]<< endl;
  
  return 0;
}
