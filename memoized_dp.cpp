#include <iostream>
#include <cmath>
#include <ctime>
#include <chrono>
#include <fstream>
#include <algorithm>

using namespace std;
using namespace std::chrono;

int64_t fibonacci(int64_t amount, int64_t * memo_dp);

int main(){

    remove("results/memoized_dp.txt");

    ofstream resultFile("results/memoized_dp.txt", std::ios::app);
  
   
    int64_t memo_dp[51]={0};

    for(int i = 1; i <= 50; i++){

         auto start = high_resolution_clock::now();

        cout << fibonacci(i, memo_dp) << endl;

         auto stop = high_resolution_clock::now();

        auto duration = duration_cast<nanoseconds>(stop - start);

        resultFile << "x = " << i << " y = "
                   << duration.count() << "" << endl;
    }
    return 0;
}


int64_t fibonacci(int64_t amount, int64_t * memo_dp){

    if (amount <= 1){
        return amount;
    }

    
    if (memo_dp[amount] != 0){

        return memo_dp[amount];
    } else {
 
        memo_dp[amount] = fibonacci(amount - 1, memo_dp) + fibonacci(amount - 2,memo_dp);
 
        return memo_dp[amount];
    }
    
}