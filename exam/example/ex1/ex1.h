#include <iostream>

using namespace std;

class Bad_Index : public exception
{
public:
    Bad_Index(int i = -1) : index(i) {}
    friend ostream &operator<<(ostream &out, const Bad_Index &e)
    {
        out << "Bad-Index value is " << e.index << endl;
        return out;
    }

private:
    int index;
};

class arraybase
{
public:
    arraybase(int n) : len(n >= 0 ? n : 0) {}
    arraybase(const arraybase &other) : len(other.len) {}
    virtual ~arraybase() = 0;
    arraybase &operator=(const arraybase &other)
    {
        if (this != &other)
        {
            len = other.len;
        }
        return *this;
    }

protected:
    int len;
};
arraybase::~arraybase() {}
template <class T>
class array : public arraybase
{
public:
    array(int n = 0) : arraybase(n), arr(0)
    {
        if (len > 0)
            arr = new T[len];
    }
    array(T *parr, int n) : arraybase(n)
    {
        copyArr(parr, n);
    }
    array(const array<T> &other) : arraybase(other) { copyArr(other.arr, len); }
    ~array() { delete[] arr; }
    T &operator[](int i)
    {
        if (i < 0 || len <= i)
            throw Bad_Index(i);
        return arr[i];
    }
    const T &operator[](int i) const
    {
        if (i < 0 || len <= i)
            throw Bad_Index(i);
        return arr[i];
    }
    array &operator=(const array<T> &other)
    {
        if (this != &other)
        {
            arraybase::operator=(other);
            copyArr(other.arr, len);
        }
        return *this;
    }
    friend ostream &operator<<(ostream &out, const array<T> ob)
    {
        if (ob.len > 0)
        {
            for (int i = 0; i < ob.len; i++)
            {
                out << ob.arr[i] << ", ";
            }
            out << endl;
        }
        return out;
    }

protected:
    T *arr;

    void copyArr(T *parr, int n)
    {
        delete[] arr;
        arr = new T[n];
        for (int i = 0; i < len; i++)
        {
            arr[i] = parr[i];
        }
    }
};

template <class T, int N>
class arraySize : public array<T>
{
public:
    arraySize() : array<T>(N) { }
    arraySize(T *parr, int n) : array<T>(parr, n) {}
    arraySize(const arraySize<T, N> &other) : array<T>(other) {}
};