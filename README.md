# Point
Simple mathematical point representation in C++14. 

# Compile
Compile with flag `-std=c++14` or `-std=c++17`. 

# Example
```cpp
constexpr auto a = make_point3(7, 8, 9);
constexpr auto b = make_point3(1, 2, 3);
constexpr auto c = a + b;
constexpr auto d = a * 9;
std::cout << c[0] << " " << c[1] << " " << c[2] << std::endl;
std::cout << d[0] << " " << d[1] << " " << d[2] << std::endl;
```

