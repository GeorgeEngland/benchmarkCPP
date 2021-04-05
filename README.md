# benchmarkCPP
##Build & Run tests:
g++ ./src/grid.cpp ./test/solution.cpp ./test/benchmarkFunctions.cpp -std=c++17 -isystem benchmark/include -Lbenchmark/build/src -lbenchmark -O2  -lpthread -fopenmp -o mybenchmark && ./mybenchmark

