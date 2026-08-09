//
// Created by ahmad on 8/8/26.
//

#ifndef C_PROJECTS_MATH_H
#define C_PROJECTS_MATH_H

template<typename T>
constexpr T maximum(T a, T b) {
    return (a > b) ? a : b;
}

//-- constexpr --> can evaluate in compile time or runtime
template<typename T, typename U>
constexpr auto maximum(T a, U b) {
    return (a > b) ? a : b;
}

//-- consteval --> stricter, must evaluate in compile time
consteval int square(int x) {
    return x * x;
}

#endif //C_PROJECTS_MATH_H
