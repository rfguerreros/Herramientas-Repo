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
    for(int j = 0; j < Units[i]; j++){
      Map.insert(pair<int,int>(i,j));
    }
  }
  

  
  cout << Map.count(500) << endl;
  
  return 0;
}
