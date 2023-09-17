using my_vec = std::vector<std::vector<double>>;

// my_vec bar()
//{                                                                                                                                                                                                                                       
//  my_vec v{};
//  for (int i = 0; i < 6; ++i)
//  {
//    v[0].push_back(i+1);
//  }      
//  return v;                                                                                                                                                                                                                           
//}

void bar(my_vec& v)
{                                                                                                                                                                                                                                       
  v.push_back({});
  for (int i = 0; i < 6; ++i)
  {
    v[0].push_back(i+1);
  }
}

void test_bar(benchmark::State& state)
{
  for (auto _ : state) {
    my_vec v;
    bar(v);
    benchmark::DoNotOptimize(v);
  }
}

// Register the function as a benchmark
BENCHMARK(test_bar);

my_vec foo()
{
    return my_vec{{1,2,3,4,5,6}};
}

void test_foo (benchmark::State& state)
{
  for (auto _ : state) {
    auto v = foo();
    benchmark::DoNotOptimize(v);
  }
}
BENCHMARK(test_foo);

