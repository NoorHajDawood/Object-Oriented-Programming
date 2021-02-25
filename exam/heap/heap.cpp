#include <iostream>
using namespace std;

template <class T>
class Heap
{
public:
    Heap(int size = 100);
    ~Heap();

    Heap<T> &operator=(const Heap<T>& other);
    Heap<T> &operator+=(const T& t);
    Heap<T> &operator-=(const T &t);
    bool oprator!=(const Heap<T> &other) const;

    bool is_in(T t) const;
    bool empty() const;
    const T& get_min() const;

private:
    T *arr;
    int size;
};


// Heap(int size) : size(size) { arr = new T[size]; }
// ~Heap() { delete[] arr; }

// Heap<T> &operator+=(const Heap<T> &other)
// {
//     T *tmp = new T *[size + other.size];
//     memcpy(tmp, arr);
//     memcpy(tmp + size, other.arr);
//     delete[] arr;
//     arr = tmp;
//     return *this;
// }

// bool is_in(T t)
// {
//     for (int i = 0; i < size; ++i)
//         if (arr[i] == t)
//             return true;
//     return false;
// }