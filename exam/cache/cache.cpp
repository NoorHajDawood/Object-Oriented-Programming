/* file: cache.cpp */

#include "cache.h"
#include "element.h"
#include <string.h>



template <class T>
ostream &operator<<(ostream &out, const Cache<T> &cache)
{
    for (int i = 0; i < cache.MaxSize; i++)
        out << cache.storage[i];
    return out;
}

template <class T>
Cache<T>::Cache(int size) : MaxSize(size)
{
    storage = new T[size];
    if (storage == NULL)
        exit(1);
}

template <class T>
Cache<T>::~Cache()
{
    delete[] storage;
}

template <class T>
int Cache<T>::Find(const T &d) const
{
    return storage[hash(d)] == d;
}

template <class T>
void Cache<T>::Insert(const T &d)
{
    storage[hash(d)] = d;
}

template <class T>
int Cache<T>::hash(const T &d) const
{
    return d.Key() % MaxSize;
}

int main(int argc, char const *argv[])
{
    Cache<Element> c(20);
    cout << "----------" << endl;
    c.Insert("12");
    cout << c.Find("21") << endl;
    c.Insert("17");
    c.Insert("71");
    cout << c;
    return 0;
}
