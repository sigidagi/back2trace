#include <iostream>

int sum(int a, int b) {
    int *p = nullptr;
    return a + *p + b;
}

int forward(int a, int b) {
    return sum(a, b);
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    
    int res = forward(1, 2);
    std::cout << "res: " << res << std::endl;
    return 0;
}


