#include <benchmark/benchmark.h>
#include "benchmarkFunctions.h"
#include "../src/grid.h"
#include <algorithm>


static void BM_Vector_Creation_2D(benchmark::State& state) {
  std::vector<std::vector<int>> grid;
  for (auto _ : state){
    grid.reserve(state.range(0)*state.range(0));
    int len = state.range(0);
    std::vector< std::vector<int> > g(state.range(0), std::vector<int>(state.range(0)));            
    grid=std::move(g);
  }   
}
// Register the function as a benchmark
BENCHMARK(BM_Vector_Creation_2D)->RangeMultiplier(2)->Range(1<<8,1<<12)->Unit(benchmark::TimeUnit::kMicrosecond);


static void BM_Vector_Creation(benchmark::State& state) {
          std::vector<int> grid;

  for (auto _ : state){
    grid.reserve(state.range(0));
    int len = state.range(0);
    std::vector< int > g(state.range(0));            
    grid=std::move(g);
  }
    
}


static void BM_Vector_Sort(benchmark::State& state){
  for (auto _ : state){
    int len = state.range(0);
    std::vector<int> vec(len);
    std::generate_n(vec.begin(), len, dataPrep::gen_rand());
    sortVector(vec);
  }
  state.SetComplexityN(state.range(0));
}
BENCHMARK(BM_Vector_Sort)->RangeMultiplier(2)->Range(1<<2,1<<8)->Complexity();


static void BM_Vector_Sort_Parrallel(benchmark::State& state){
  for (auto _ : state){
    int64_t len = state.range(0);
    std::vector<int> vec(len);
    std::generate_n(vec.begin(), len, dataPrep::gen_rand());
    parrallelsortVector(vec);
  }
   state.SetComplexityN(state.range(0));
}
BENCHMARK(BM_Vector_Sort_Parrallel)->RangeMultiplier(2)->Range(1<<2,1<<8)->Complexity();


static void BM_Grid_Load_Data(benchmark::State& state){
  std::string path = "./data/data_"+std::to_string(state.range(0))+".csv";
  for (auto _ : state){
    Grid g(state.range(0));
    g.loadGridFromDataPath(path);
  }
     state.SetComplexityN(state.range(0));

}
BENCHMARK(BM_Grid_Load_Data)->RangeMultiplier(2)->Range(1<<8,1<<10)->Complexity()->Unit(benchmark::TimeUnit::kMicrosecond);


static void BM_Grid_Initialise(benchmark::State& state){
  for (auto _ : state){
    Grid g(state.range(0));
  }
     state.SetComplexityN(state.range(0));
}
BENCHMARK(BM_Grid_Initialise)->RangeMultiplier(2)->Range(1<<8,1<<11)->Complexity()->Unit(benchmark::TimeUnit::kMicrosecond);
BENCHMARK_MAIN();