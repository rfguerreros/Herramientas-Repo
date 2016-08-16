#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<random>
#include<ctime>


using namespace std;

int main(){

  long Y;
  long Z;
  long X;

  long S=0;
  
  long NumberUnits = 1000;
  
  
  mt19937 randomGen(time(0));
  uniform_int_distribution <int> diceRoll (1, 100);
  uniform_int_distribution <int> randI (0,NumberUnits);
  uniform_int_distribution <int> randJ(0,NumberUnits);
  
  
  vector <long> R;
  R.resize(NumberUnits);

  for(int i = 0; i < NumberUnits; i++){
    R[i]=1;
  }

  for(int i = 0; i < 100000; i++){
    Y=randI(randomGen);
    

    X=diceRoll(randomGen);
    
    if(X!=50){

      Z=randJ(randomGen);
      
      R[Y]=R[Y]+R[Z];
      R[Z]=0;
      
    } else if(X==50 && R[Y]>1){
	for(int k = 0; k < NumberUnits; k++){
	  if(R[k]==0){
	    R[k]=1;
	    S++;
	  }
	  if(S == R[Y]) break;
	}
	R[Y]=1;
    }
  }

  int c=0;
  for(int i = 0; i < NumberUnits; i++){
    if(R[i]>1){
    cout<<R[i]<<"-";
    }
    c=c+R[i];
  }

  cout << "\n" <<c << endl;
  
  
  return 0;
}
