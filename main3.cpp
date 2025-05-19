// 3. Add an optional parameter to start aggregating with
// aggregate(xs, mul, 10); // 240
// aggregate(xs, concat, std::string("0")); // "01234"

#include <iostream>
#include <functional>
#include <stdexcept>
#include <string>
#include <vector>

int aggregate(const std::vector<int>& container, std::function<int(int, int)> op, int initial) {
  int result = initial;
  for (size_t i = 0; i < container.size(); ++i) {
    result = op(result, container[i]);
  }
  return result;
}

int aggregate(const std::vector<int>& container, std::function<int(int, int)> op) {
  if (container.empty()) {
    throw std::invalid_argument("Container is empty");
  }

  int result = container[0];
  for (size_t i = 1; i < container.size(); ++i) {
    result = op(result, container[i]);
  }
  return result;
}

std::string aggregate(const std::vector<std::string>& container, std::function<std::string(const std::string&, const std::string&)> op, const std::string& initial) {
  std::string result = initial;
  for (size_t i = 0; i < container.size(); ++i) {
    result = op(result, container[i]);
  }
  return result;
}

std::string aggregate(const std::vector<std::string>& container, std::function<std::string(const std::string&, const std::string&)> op) {
  if (container.empty()) {
    throw std::invalid_argument("Container is empty");
  }

  std::string result = container[0];
  for (size_t i = 1; i < container.size(); ++i) {
    result = op(result, container[i]);
  }
  return result;
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
  std::vector<int> xs = {1, 2, 3, 4};

  int product_result = aggregate(xs, mul);
  std::cout << "Product: " << product_result << std::endl;

  int product_with_init = aggregate(xs, mul, 10);
  std::cout << "Product with init 10: " << product_with_init << std::endl;

  int sum_result = aggregate(xs, add);
  std::cout << "Sum: " << sum_result << std::endl;

  int sum_with_init = aggregate(xs, add, 5);
  std::cout << "Sum with init 5: " << sum_with_init << std::endl;

  std::vector<std::string> ys = {"1", "2", "3", "4"};
  std::string concat_result = aggregate(ys, concat);
  std::cout << "Concat: " << concat_result << std::endl;

  std::string concat_with_init = aggregate(ys, concat, std::string("0"));
  std::cout << "Concat with '0': " << concat_with_init << std::endl;

  return 0;
}
