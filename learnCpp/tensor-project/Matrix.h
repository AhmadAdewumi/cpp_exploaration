//
// Created by ahmad on 8/8/26.
//

#ifndef C_PROJECTS_MATRIX_H
#define C_PROJECTS_MATRIX_H
#include <initializer_list>

template<typename T, int Rows, int Cols>
class Matrix {
private:
    T m_data[Rows * Cols]{};

public:
    //constructor
    constexpr Matrix(std::initializer_list<T> list) {
        int i{0};

        for (T value: list) {
            m_data[i] = value;
            ++i;
        }
    }


    //-- index = row * number_of_cols + col
    constexpr T &operator()(int row, int col) {
        return m_data[row * Cols + col];
    }

    constexpr const T &operator()(int row, int col) const {
        return m_data[row * Cols + col];
    }

    static constexpr int rows() { return Rows; }
    static constexpr int cols() { return Cols; }
};


#endif //C_PROJECTS_MATRIX_H
