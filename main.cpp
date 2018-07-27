#include <cassert>
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

struct tag_lower {};
struct tag_upper {};

template <typename T> struct LowerUpper {
  const tuple<T, tag_upper> upper_tagged;
  const tuple<T, tag_lower> lower_tagged;

  const T &upper() const noexcept { return get<0>(upper_tagged); }
  const T &lower() const noexcept { return get<0>(lower_tagged); }
};

template <typename T, typename tag>
auto return_vector(const int size, const T value) -> tuple<vector<T>, tag> {
  auto ret = vector<T>(size, value);
  return {ret, {}};
}

int main(int argc, char **argv) {
  constexpr auto lower_size{4};
  constexpr auto upper_size{5};

  const auto lower = return_vector<int, tag_lower>(lower_size, 0);
  const auto upper = return_vector<int, tag_upper>(upper_size, 0);

  const LowerUpper<vector<int>> lower_upper{upper, lower}; // This is OK.
  // Compilation error
  // const LowerUpper<vector<int>> lower_upper{lower, upper};

  assert(lower_upper.lower().size() == lower_size);
  assert(lower_upper.upper().size() == upper_size);
  return 0;
}
