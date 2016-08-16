#include<iostream>
#include<vector>
#include<random>
#include<ctime>


using namespace std;

int main(){

  int NumberUnits = 100;
  
  
  mt19937 randomGen(time(0));
  uniform_int_distribution <int> diceRoll (1, 100);
  uniform_int_distribution <int> randI (0,NumberUnits);
  uniform_int_distribution <int> randJ(0,NumberUnits);
  
  
  vector <int> R;
  R.resize(NumberUnits);

  for(int i = 0; i < NumberUnits; i++){
    R[i]=1;
  }

  for(int i = 0; i < NumberUnits; i++){
    if(diceRoll(randomGen)!=50){
      R[randI(randomGen)]=R[randI(randomGen)]+R[randJ(randomGen)];
      R[randJ(randomGen)]=0;
    } //else(diceRoll(randomGen)==50 && R[i]!=1){
	
    //}
  }
 

  
  
  return 0;
}
