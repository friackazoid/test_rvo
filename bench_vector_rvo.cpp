// g++ bench_vector_rvo.cpp -std=c++11 -I/usr/include/eigen3 -L/usr/local/lib/ -lbenchmark -lpthread -o bench_vector_rvo

#include <vector>

#include <benchmark/benchmark.h>

using my_vec = std::vector<std::vector<double>>;

void vector_byref (my_vec& v)
{
    v.push_back({1,2,3,4,5,6});
}

void BM_vector_byref(benchmark::State& state)
{
    for (auto _ : state) {
        my_vec v;
        vector_byref(v);
        benchmark::DoNotOptimize(v);
    }
}
BENCHMARK(BM_vector_byref);

void vector_byref_iter (my_vec& v)
{
    v.resize(1);
    v[0].reserve(6);
    for (auto i = 0; i < 6; ++i) {
        v[0].push_back(i+1);
    }
}

void BM_vector_byref_iter(benchmark::State& state)
{
    for (auto _ : state) {
        my_vec v;
        vector_byref_iter(v);
        benchmark::DoNotOptimize(v);
    }
}
BENCHMARK(BM_vector_byref_iter);

my_vec vector_nrvo()
{
    my_vec v{};
    v.push_back({1,2,3,4,5,6});
    return v;
}

void BM_vector_nrvo(benchmark::State& state) 
{
    for (auto _ : state) {
        auto v = vector_nrvo();
        benchmark::DoNotOptimize(v);
    }
}
BENCHMARK(BM_vector_nrvo);

my_vec vector_rvo()
{
    return my_vec{{1,2,3,4,5,6}};
}

void BM_vector_rvo(benchmark::State& state) 
{
    for (auto _ : state) {
        auto v = vector_rvo();
        benchmark::DoNotOptimize(v);
    }
}
BENCHMARK(BM_vector_rvo);

BENCHMARK_MAIN();
