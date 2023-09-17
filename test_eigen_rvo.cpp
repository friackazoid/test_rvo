// g++ -I/usr/include/eigen3 -o test_rvo test_rvo.cpp
// g++ -S -I/usr/include/eigen3  test_rvo.cpp

#include <iostream>
#include <Eigen/Core>

void foobar (Eigen::VectorXd& v)
{
    v << 1,2,3,4,5,6;
}

Eigen::VectorXd bar()
{
    Eigen::VectorXd v(6);
    v << 1,2,3,4,5,6;
    return v;
}

Eigen::VectorXd foo()
{
    return Eigen::VectorXd{{1,2,3,4,5,6}};
}

int main (int /*argc*/, char** /* argv*/)
{

    auto v_foo = foo();
    std::cout << "v_foo: " <<v_foo.transpose() << std::endl;

    auto v_bar = bar();
    std::cout << "v_bar: " <<v_bar.transpose() << std::endl;

    Eigen::VectorXd v_foobar(6);
    foobar(v_foobar);
    std::cout << "v_foobar: " <<v_foobar.transpose() << std::endl;
    return 0;
}

