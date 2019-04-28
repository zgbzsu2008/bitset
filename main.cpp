#include <algorithm>
#include <bitset>
#include <cstddef>
#include <iostream>
#include <string>

// # @to_string
template <std::size_t N>
std::ostream& operator<<(std::ostream& out, std::bitset<N> b)
{
  out << b.to_string();
  return out;
}

int main()
{
  // #01 @bitset可以用标准逻辑运算符操作位集
  std::bitset<4> b1("0010");
  std::bitset<4> b2(6);
  std::cout << "#01 " << b1 << '&' << b2 << '=' << (b1 & b2) << '\n';
  std::cout << "#01 " << b1 << '|' << b2 << '=' << (b1 | b2) << '\n';
  std::cout << "#01 " << b1 << '^' << b2 << '=' << (b1 ^ b2) << '\n';
  std::cout << "#01 " << '~' << b1 << '=' << (~b1) << '\n';
  int shift = 2;
  std::cout << "#01 " << b1 << "<<" << shift << '=' << (b1 << shift) << '\n';
  std::cout << "#01 " << b2 << ">>" << shift << '=' << (b2 >> shift) << '\n';

  // #02 @all
  std::bitset<8> b("01011101");
  std::cout << std::boolalpha << b << '\n';
  std::cout << "#02 all: " << b.all() << '\n';

  // #03 @any
  std::cout << "#03 any: " << b.any() << '\n';

  // #04 @any
  std::cout << "#04 none: " << b.none() << '\n';

  // #05 @count
  std::cout << "#05 count: " << b.count() << '\n';

  // #06 @test
  std::cout << "#06 test(1): " << b.test(1) << '\n';

  // #07 @filp
  std::cout << "#07 filp(2): " << b.flip(2) << '\n';

  // #08 @set
  std::cout << "#08 set(3): " << b.set(3) << '\n';

  // #09 @reset
  std::cout << "#09 reset(4): " << b.reset(4) << '\n';

  // #10 @to_ulong
  std::cout << "#10 to_ulong = " << b.to_ulong() << '\n';

  // #11 @to_ullong
  std::cout << "#11 to_ullong = " << b.to_ullong() << '\n'; // c++11

  // #12 hash
  std::hash<std::bitset<8>> hash_fn; // c++11
  std::cout << "#12 hash(" << b << ") = " << hash_fn(b) << '\n';
  return 0;
}