#include <stdio.h>

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
    printf("Recursive Fibonacci of %d is %d\n", number, fibonacci_recursive(number));
    printf("Iterative Fibonacci of %d is %d\n", number, fibonacci_iterative(number));
    return 0;
}