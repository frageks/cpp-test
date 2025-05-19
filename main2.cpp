// 2. Let's separate iteration and an operation to be done.
// Write a function aggregating a vector with any given function:
// aggregate(xs, add); // 10
// aggregate(xs, mul); // 24

#include <functional>
#include <iostream>
#include <stdexcept>
#include <vector>

int aggregate(const std::vector<int>& container, std::function<int(int, int)> op) {
  if (container.begin() == container.end()) {
    throw std::runtime_error("Container is empty");
  }

  auto it = container.begin();
  int result = *it;
  ++it;

  for (; it != container.end(); ++it) {
    result = op(result, *it);
  }

  return result;
}

int add(int a, int b) {
  return a + b;
}

int mul(int a, int b) {
  return a * b;
}

int main() {
  std::vector<int> xs = {1, 2, 3, 4};

  int sum_result = aggregate(xs, add);
  std::cout << "Sum: " << sum_result << std::endl;

  int product_result = aggregate(xs, mul);
  std::cout << "Product: " << product_result << std::endl;

  return 0;
}
