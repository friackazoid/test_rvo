// g++ bench_array_rvo.cpp -std=c++11 -L/usr/local/lib/ -lbenchmark -lpthread -o bench_array_rvo

#include <array>

#include <benchmark/benchmark.h>

using my_vec = std::array<double, 6>;

void array_byref (my_vec& v)
{
    v = {1,2,3,4,5,6};
}

void BM_array_byref(benchmark::State& state)
{
    for (auto _ : state) {
        my_vec v;
        array_byref(v);
        benchmark::DoNotOptimize(v);
    }
}
BENCHMARK(BM_array_byref);

void array_byref_iter (my_vec& v)
{
    for (auto i = 0; i < 6; ++i) {
        v[i] = i+1;
    }
}

void BM_array_byref_iter(benchmark::State& state)
{
    for (auto _ : state) {
        my_vec v;
        array_byref_iter(v);
        benchmark::DoNotOptimize(v);
    }
}
BENCHMARK(BM_array_byref_iter);

my_vec array_nrvo()
{
    my_vec v{1,2,3,4,5,6};
    return v;
}

void BM_array_nrvo(benchmark::State& state) 
{
    for (auto _ : state) {
        auto v = array_nrvo();
        benchmark::DoNotOptimize(v);
    }
}
BENCHMARK(BM_array_nrvo);

my_vec array_rvo()
{
    return my_vec{1,2,3,4,5,6};
}

void BM_array_rvo(benchmark::State& state) 
{
    for (auto _ : state) {
        auto v = array_rvo();
        benchmark::DoNotOptimize(v);
    }
}
BENCHMARK(BM_array_rvo);

BENCHMARK_MAIN();
