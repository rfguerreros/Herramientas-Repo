#include<iostream>
#include<vector>
#include<random>
#include<ctime>


using namespace std;

int main(){

  mt19937 randomGen(time(0));
  uniform_int_distribution <int> diceRoll (1, 100);
  
  int NumberUnits = 10000;
  double FragmentationProb = 0.01;

  vector <int> R;
  R.resize(NumberUnits);
  R[0]=NumberUnits;

  cout << diceRoll(randomGen)  << endl;
  
  return 0;
}
