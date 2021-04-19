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

    remove("results/formula.txt");

    ofstream resultFile("results/formula.txt", std::ios::app);
  
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

    double f = (1 + sqrt(5)) / 2;

    amount = round(pow(f, amount) / sqrt(5));

    return amount; 
}