#include<bits/stdc++.h>
using namespace std;

/*IMPORTANT: The below code uses 10cm as 1 unit of distance */

const int N = 100000; // Number of ants to be simulated
const int S = 1000; // Number of maximum steps to be simulated

/* x, y store the postition for each ant while t stores the time at which ant 
reached food (or current time if not reached yet) */
double x[N], y[N], t[N];

bool reached[N]; // stores whether the ith ant has reached food or not

/* Function to calculate whether the ant is inside the food boundary */
/* Returns true if ant is inside the food boundary else fasle */
bool in_boundary(double x, double y) {
  double x1 = (x-0.25)*(x-0.25)/9;
  double y1 = (y-0.25)*(y-0.25)/16;
  if(x1 + y1 < 1) return true;
  return false;
}

/* Calculates the avg time it takes N ants to reach food in maximum S seconds/steps */
double expected() {
  for(int j = 0; j < S; ++j) {
    for(int i = 0; i < N; ++i) {
      if(reached[i]) continue;
      int dir = rand() % 4;
      switch(dir) {
        case 0: x[i]++;
            break;
        case 1: y[i]++;
            break;
        case 2: x[i]--;
            break;
        case 3: y[i]--;
            break;
      }
      t[i]++;
      if(!in_boundary(x[i], y[i])) reached[i] = true;
    }
  }

  double total_time = 0;
  for(int i = 0; i < N; ++i) total_time += t[i];
  double avg_time = total_time/N;

  return avg_time;
}

int main() {
  memset(x, 0, sizeof(x));
  memset(y, 0, sizeof(y));
  memset(t, 0, sizeof(t));
  memset(reached, false, sizeof(reached));
  double expected_time = expected();
  cout<<expected_time<<" seconds"<<endl;
}