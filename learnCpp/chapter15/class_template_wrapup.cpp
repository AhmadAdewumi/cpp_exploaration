#include <iostream>
#include <string>
#include <string_view>

template<typename T>
class Box{
    private:
        T value;
        static int objectCount;
        
    public:
        Box(T initialValue) : value{initialValue} {
            objectCount++;
        }

        //-- destructor
         ~Box(){
             objectCount--;
         };
        
        T& get(){
            return this->value;
        };
        
        const T& get() const{
            return this->value;
        };

        //-- lvalue objects ca;; this
        Box& set(T newValue) & {
            value = newValue;
            return *this;
        };

        //-- rvalue objects call this
        Box& set(T newValue) && {
            value = newValue;
            return *this;
        };
        
        void print() const;

};

template<typename T>
int Box<T>::objectCount = 0;

template<typename T>
void Box<T>::print() const{
    std::cout << "Value is: " << value;
}