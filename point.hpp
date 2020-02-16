///////////////////////////////////////////////////////////////////////////////
// Simple mathematical point in C++14.
//
// Author: PotatoMaster101
// Date:   23/08/2019
///////////////////////////////////////////////////////////////////////////////

#ifndef POINT_HPP
#define POINT_HPP
#include <algorithm>        // std::min
#include <cstddef>

// A simple mathematical point.
//
// TYPES:
// T - point data type
// N - point dimension
template <class T, std::size_t N = 2>
class point {
public:
    // Represents the point value type.
    using value_type = T;
    // Represents the point value reference type.
    using reference = value_type&;
    // Represents the point value const reference type.
    using const_reference = const value_type&;
    // Represents the point size.
    using size_type = std::size_t;

    // Constructs an empty point.
    constexpr point() : data_()
    { assert0(); for (size_type i = 0; i < N; i++) data_[i] = T(); }
    // Constructs a 2D point.
    constexpr point(const T& x, const T& y) : data_()
    { assert2(); data_[0] = x; data_[1] = y; }
    // Constructs a 3D point.
    constexpr point(const T& x, const T& y, const T& z) : data_()
    { assert3(); data_[0] = x; data_[1] = y; data_[2] = z; }
    // Constructs a 2D point.
    template <class U>
    constexpr point(U&& x, U&& y) : data_()
    { assert2(); data_[0] = std::forward<U>(x); data_[1] = std::forward<U>(y); }
    // Constructs a 3D point.
    template <class U>
    constexpr point(U&& x, U&& y, U&& z) : data_()
    { assert3(); data_[0] = std::forward<U>(x); data_[1] = std::forward<U>(y); data_[2] = std::forward<U>(z); }

    // The rule of five.
    constexpr point(const point& p) = default;
    constexpr point& operator=(const point& p) = default;
    constexpr point(point&& p) = default;
    constexpr point& operator=(point&& p) = default;
    ~point() = default;

    // Returns the dimension of the point.
    constexpr size_type dimension() const noexcept
    { return N; }

    // Returns the X axis value.
    constexpr reference x() noexcept
    { assert1(); return data_[0]; }
    constexpr const_reference x() const noexcept
    { assert1(); return data_[0]; }

    // Returns the Y axis value.
    constexpr reference y() noexcept
    { assert2(); return data_[1]; }
    constexpr const_reference y() const noexcept
    { assert2(); return data_[1]; }

    // Returns the Z axis value.
    constexpr reference z() noexcept
    { assert3(); return data_[2]; }
    constexpr const_reference z() const noexcept
    { assert3(); return data_[2]; }

    // The [] operator.
    constexpr reference operator[](size_type n) noexcept
    { return data_[n]; }
    constexpr const_reference operator[](size_type n) const noexcept
    { return data_[n]; }

    // Arithmetic operators.
    constexpr point& operator+=(const point& p)
    { for (size_type i = 0; i < N; i++) data_[i] += p[i]; return *this; }
    constexpr point& operator-=(const point& p)
    { for (size_type i = 0; i < N; i++) data_[i] -= p[i]; return *this; }
    constexpr point& operator*=(const_reference v)
    { for (size_type i = 0; i < N; i++) data_[i] *= v; return *this; }
    constexpr friend point operator+(point lhs, const point& rhs)
    { return (lhs += rhs); }
    constexpr friend point operator-(point lhs, const point& rhs)
    { return (lhs -= rhs); }
    constexpr friend point operator*(point lhs, const_reference rhs)
    { return (lhs *= rhs); }

private:
    // Point data.
    T data_[N];

    // Asserts whether the dimension is 0.
    constexpr void assert0() const noexcept
    { static_assert(N != 0, "Dimension is 0."); }

    // Asserts whether the dimension is 1.
    constexpr void assert1() const noexcept
    { static_assert(N >= 1, "Dimension is less than 1."); }

    // Asserts whether the dimension is 2.
    constexpr void assert2() const noexcept
    { static_assert(N >= 2, "Dimension is less than 2."); }

    // Asserts whether the dimension is 3.
    constexpr void assert3() const noexcept
    { static_assert(N >= 3, "Dimension is less than 3."); }
};

// Represents a 2D point.
template <class T>
using point2 = point<T, 2>;

// Represents a 3D point.
template <class T>
using point3 = point<T, 3>;

// Returns a 2D point using X and Y values.
template <class T>
constexpr point2<T> make_point2(T&& x, T&& y) noexcept
{ return {std::forward<T>(x), std::forward<T>(y)}; }

// Returns a 3D point using X, Y and Z values.
template <class T>
constexpr point3<T> make_point3(T&& x, T&& y, T&& z) noexcept
{ return {std::forward<T>(x), std::forward<T>(y), std::forward<T>(z)}; }

// Returns a 2D point using another point.
template <class T, std::size_t N>
constexpr point2<T> make_point2(const point<T, N>& p) {
    point2<T> ret{T(), T()};
    auto lim = std::min(p.dimension(), static_cast<std::size_t>(2));
    for (std::size_t i = 0; i < lim; i++)
        ret[i] = p[i];
    return ret;
}

// Returns a 3D point using another point.
template <class T, std::size_t N>
constexpr point3<T> make_point3(const point<T, N>& p) {
    point3<T> ret{T(), T(), T()};
    auto lim = std::min(p.dimension(), static_cast<std::size_t>(3));
    for (std::size_t i = 0; i < lim; i++)
        ret[i] = p[i];
    return ret;
}

#endif

