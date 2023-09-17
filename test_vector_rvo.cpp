#include <fstream>
#include <iostream>
#include <vector>

using my_vec = std::vector<std::vector<double>>;

std::ostream& operator<<(std::ostream& os, const my_vec& v)
{
    for (const auto& row : v)
    {
        for (const auto& col : row)
        {
            os << col << " ";
        }
        os << std::endl;
    }
    return os;
}

void foobar(my_vec& v)
{
    //v = {{1,2,3,4,5,6}};
    v.push_back({});

    for (int i = 0; i < 6; ++i)
    {
        v[0].push_back(i+1);
    }
}


my_vec bar()
{
    my_vec v;
    v.push_back({1,2,3,4,5,6});
    return v;
}

my_vec foo()
{
    return my_vec{{1,2,3,4,5,6}};
}

int main (int /*argc*/, char** /* argv*/)
{

    auto v_foo = foo();
    std::cout << "v_foo: " <<v_foo << std::endl;

    auto v_bar = bar();
    std::cout << "v_bar: " <<v_bar << std::endl;

    my_vec v_foobar;
    foobar(v_foobar);
    std::cout << "v_foobar: " <<v_foobar << std::endl;
    return 0;
}

