// 1. In C++11 write a function summing all vector elements:
// std::vector xs = { 1, 2, 3, 4 };
// vectorSum(xs); // 10

#include <iostream>
#include <vector>

int vectorSum(const std::vector<int>& vec) {
    int sum = 0;
    for (const int& element : vec) {
        sum += element;
    }
    return sum;
}

int main() {
    std::vector<int> xs = {1, 2, 3, 4};
    int sum = vectorSum(xs);
    std::cout << "Sum: " << sum << std::endl;
    return 0;
}
