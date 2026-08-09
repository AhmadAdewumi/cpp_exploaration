//
// Created by ahmad on 8/8/26.
//

#ifndef C_PROJECTS_STATICARRAY_H
#define C_PROJECTS_STATICARRAY_H

template<typename T, int Size>
class StaticArray {
public:
    T m_data[Size]{};

public:
    constexpr int size() const {
        return Size;
    }

    constexpr T &operator[](int index) {
        return m_data[index];
    }

    constexpr const T &operator[](int index) const {
        return m_data[index];
    }

    constexpr T sum(const StaticArray<T, Size> &array) const {
        T result{};
        for (int i{0}; i < Size; ++i) {
            result += array[i];
        }

        return result;
    }
};

#endif //C_PROJECTS_STATICARRAY_H
