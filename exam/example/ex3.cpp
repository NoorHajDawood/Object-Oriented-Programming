class Fraction
{
    int num;
    unsigned denom;

public:
    explicit Fraction(int n = 0, unsigned d = 1)
    {
        num = n;
        denom = d;
    }
    bool operator==(const Fraction &other);
    friend ostream &operator<<(ostream &s, const Fraction &temp)
    {
        s << temp.num << " / " << temp.denom;
        return s;
    }
};

class Base
{
public:
    int getSize() const;
    bool isEmpty() const;
    bool isFull() const;

protected:
    int size;
    int current;
};

template <class T, int N>
class Array
{
public:
    T &operator[](int i)
    {
        if (i < 0 || curr < i)
            throw "out of range";
        return arr[i];
    }
    virtual Array<T, N> &operator+=(const T &t)
    {
        if (curr == N)
            thorw "Array is Full";
        arr[curr++] = t;
        return *this;
    }
    void operator+=(const Array<T, N> &other)
    {
        if ((curr + other.curr) > N)
            throw "Array is Full";
        for (int i = 0; i < other.curr; ++i)
            if ( !strcmp(typeid(*this).name(), "Array") || !find(other.arr[i]))
                arr[curr++] = other.arr[i];
    }
    int find(const T &t) const
    {
        for (int i = 0; i < curr; i++)
        {
            if (arr[i] == t)
                return true;
        }
        return false;
    }
    bool operator>(const Array<T, N> &other)
    {
        for (int i = 0, j; i < other.curr; i++)
        {
            if (find(other.arr[i]) == false)
                return false;
        }
        return true;
    }

protected:
    int curr = 0;
    T *arr;
};

template <class T, int N>
class Set : public Array
{
public:
    Set<T, N> &operator+=(const T &t)
    {
        if (curr == N)
            thorw "Set is Full";
        if (!find(t))
            static_cast<Array<T, N> *>(this)->operator+=(t);
        return *this;
    }
    // Set<T, N> &operator+=(const Array<T, N> &other)
    // {
    //     if ((curr + other.curr) > N)
    //         throw "Set is Full";
    //     for (int i = 0; i < other.curr; ++i)
    //         if (!find(other.arr[i]))
    //             arr[curr++] = other.arr[i];
    //     return *this;
    // }
    bool operator>(const Set<T, N> &other)
    {
        return static_cast<Array<T, N> *>(this)->operator>(other);
    }
};
