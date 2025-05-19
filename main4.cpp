// 4. Write a recursive aggregate version.
// Do not simulate a cycle via recursion.
// Let's also make it work with plain arrays.
// And with both function pointers and lambdas.

#include <iostream>
#include <functional>
#include <stdexcept>
#include <string>

template <typename T, typename BinaryOp>
T aggregate(const T* arr, size_t size, BinaryOp op, T initial) {
  if (size == 0) {
    return initial;
  }
  return op(arr[0], aggregate(arr + 1, size - 1, op, initial));
}

template <typename T, typename BinaryOp>
T aggregate(const T* arr, size_t size, BinaryOp op) {
  if (size == 0) {
    throw std::invalid_argument("Array is empty");
  }
  if (size == 1) {
    return arr[0];
  }
  return op(arr[0], aggregate(arr + 1, size - 1, op));
}

int mul(int a, int b) {
  return a * b;
}

int add(int a, int b) {
  return a + b;
}

std::string concat(const std::string& a, const std::string& b) {
  return a + b;
}

int main() {
  int xs[] = {1, 2, 3, 4};
  size_t xs_size = sizeof(xs) / sizeof(xs[0]);

  int product_result = aggregate(xs, xs_size, mul);
  std::cout << "Product: " << product_result << std::endl;

  int product_with_init = aggregate(xs, xs_size, mul, 10);
  std::cout << "Product with init 10: " << product_with_init << std::endl;

  int sum_result = aggregate(xs, xs_size, add);
  std::cout << "Sum: " << sum_result << std::endl;

  // Using lambda
  int max_result = aggregate(xs, xs_size, [](int a, int b) { return a > b ? a : b; });
  std::cout << "Max: " << max_result << std::endl;

  std::string ys[] = {"1", "2", "3", "4"};
  size_t ys_size = sizeof(ys) / sizeof(ys[0]);

  // Using function pointer with strings
  std::string concat_result = aggregate(ys, ys_size, concat);
  std::cout << "Concat: " << concat_result << std::endl;

  std::string concat_with_init = aggregate(ys, ys_size, concat, std::string("0"));
  std::cout << "Concat with '0': " << concat_with_init << std::endl;

  // Using lambda with strings
  std::string concat_lambda = aggregate(ys, ys_size, 
    [](const std::string& a, const std::string& b) { return a + "-" + b; });
  std::cout << "Concat with separator: " << concat_lambda << std::endl;

  return 0;
}
