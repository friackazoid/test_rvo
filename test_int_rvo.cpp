
#include <iostream>

void int_byref(int& i) {
  i = 42;
}

int int_byval() {
  return 42;
}


int main (int argc, char** ) {

    int i = 0;
    int_byref(i);
    std::cout << "i = " << i << std::endl;
    
    int j = int_byval();
    std::cout << "j = " << j << std::endl;
    
    return 0;

}
