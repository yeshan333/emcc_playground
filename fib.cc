#include <iostream>

// 递归方法
int fibonacci_recursive(int n) {
    if (n <= 1)
        return n;
    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}

// 迭代方法
int fibonacci_iterative(int n) {
    if (n <= 1)
        return n;
    int a = 0, b = 1, c;
    for(int i = 2; i <= n; ++i){
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main() {
    int number = 10;
    std::cout << "Recursive Fibonacci of " << number << " is " << fibonacci_recursive(number) << std::endl;
    std::cout << "Iterative Fibonacci of " << number << " is " << fibonacci_iterative(number) << std::endl;
    return 0;
}