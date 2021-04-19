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

    remove("results/recurison.txt");

    ofstream resultFile("results/recurison.txt", std::ios::app);
  

    for(int64_t i = 1; i <= 50; i++){

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
    if (amount <= 1)
        return amount;
    return fibonacci(amount-1) + fibonacci(amount-2);
    
}