// g++ bench_eigen_rvo.cpp -std=c++11 -I/usr/include/eigen3 -L/usr/local/lib/ -lbenchmark -lpthread -o bench_eigen_rvo

#include <Eigen/Core>

#include <benchmark/benchmark.h>

void eigen_byref_iter (Eigen::VectorXd& v)
{
    v.resize(6);
    v[0] = 1;
    v[1] = 2;
    v[2] = 3;
    v[3] = 4;
    v[4] = 5;
    v[5] = 6;
}

void BM_eigen_byref_iter(benchmark::State& state)
{
    for (auto _ : state) {
        Eigen::VectorXd v;
        eigen_byref_iter(v);
        benchmark::DoNotOptimize(v);
    }
}
BENCHMARK(BM_eigen_byref_iter);

void eigen_byref (Eigen::VectorXd& v)
{
    v << 1,2,3,4,5,6;
}

void BM_eigen_byref(benchmark::State& state)
{
    for (auto _ : state) {
        Eigen::VectorXd v(6);
        eigen_byref(v);
        benchmark::DoNotOptimize(v);
    }
}
BENCHMARK(BM_eigen_byref);

Eigen::VectorXd eigen_nrvo()
{
    Eigen::VectorXd v(6);
    v << 1,2,3,4,5,6;
    return v;
}

void BM_eigen_nrvo(benchmark::State& state) 
{
    for (auto _ : state) {
        auto v = eigen_nrvo();
        benchmark::DoNotOptimize(v);
    }
}
BENCHMARK(BM_eigen_nrvo);

Eigen::VectorXd eigen_rvo()
{
    return Eigen::VectorXd{{1,2,3,4,5,6}};
}

void BM_eigen_rvo(benchmark::State& state) 
{
    for (auto _ : state) {
        auto v = eigen_rvo();
        benchmark::DoNotOptimize(v);
    }
}
BENCHMARK(BM_eigen_rvo);

BENCHMARK_MAIN();
