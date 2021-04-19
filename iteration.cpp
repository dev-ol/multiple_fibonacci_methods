#include <iostream>
#include <cmath>
#include <ctime>
#include <chrono>
#include <fstream>
#include <algorithm>

using namespace std;
using namespace std::chrono;

int64_t fibonacci(int64_t amount);

int main(){
    // removing old file data
    remove("results/iteration.txt");

    ofstream resultFile("results/iteration.txt", std::ios::app);
  

    for(int i = 1; i <= 50; i++){
        
        auto start = high_resolution_clock::now();

        cout << fibonacci(i) << endl;

        auto stop = high_resolution_clock::now();

        auto duration = duration_cast<nanoseconds>(stop - start);

        resultFile << "x = " << i << " y = "
                   << duration.count() << "" << endl;
    }
    return 0;
}


int64_t fibonacci(int64_t amount){
    
     if (amount <= 1){
        return amount;
    }

    int64_t pos2 = 0;
    int64_t pos = 1;
    int64_t result;
  
  for (int i = 1; i < amount; i++){
    result = pos2 + pos;
    pos2 = pos;
    pos = result;
  }

  return result;
    
}