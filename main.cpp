#include <iostream>
//#include "array.h"
#include "hash.h"
#include <ctime>
using namespace std;
int main() {

    vector<int> nums = {3,2,4};
    int  target = 6;
    clock_t start = clock();

    vector<int> results = twoSum(nums,target);
    clock_t end = clock();
    double cpu_time_used = static_cast<double>(end - start) / CLOCKS_PER_SEC;
    std::cout << "CPU time used: " << cpu_time_used << " s\n";
    for(auto result:results)
    cout << result;
    std::cout<< endl;
    return 0;
}
