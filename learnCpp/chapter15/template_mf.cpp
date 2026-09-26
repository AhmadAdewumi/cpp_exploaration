#include <iostream>

//---- TEMPLATE MEMBER FUNCTIONS---
template<typename T, typename U, typename V>
class Triad{
    private:
        T first;
        U second;
        V third;

    public:
        Triad(T d1, U d2, V d3) : first{d1}, second{d2}, third{d3} {}

        T getFirst() const{
            return first;
        }

        U getSecond() const{
            return second;
        }

        V getThird() const{
            return third;
        }

        void print() const;
};

template<typename T, typename U, typename V>
void Triad< T,  U,  V>::print() const{
    std::cout << "[ " << first << ", " << second << ", " << third << " ]";
}

int main()
{
	Triad<int, int, int> t1{ 1, 2, 3 };
	t1.print();
	std::cout << '\n';
	std::cout << t1.getFirst() << '\n';

	using namespace std::literals::string_literals;
	const Triad t2{ 1, 2.3, "Hello"s };
	t2.print();
	std::cout << '\n';

	return 0;
}

//---- GET IN JOOR --- RUNS ON FIRST TRIAL