#include <algorithm>
#include <vector>
#include "benchmarkFunctions.h"
#include <parallel/algorithm>

double dataPrep::gen_rand::operator()() { 
            return (rand()/(double)RAND_MAX) * range;
        }
int parrallelsortVector(std::vector<int> vec){
    __gnu_parallel::sort(vec.begin(),vec.end());
    return 0;
}
int sortVector(std::vector<int> vec){
    sort(vec.begin(),vec.end());
    return 0;
}