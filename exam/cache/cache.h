/* file: cache.h */
#ifndef __CACHE_H
#define __CACHE_H

#include <iostream>
using namespace std;

template <class T>
class Cache
{
public:
    Cache(int);
    ~Cache();
    int Find(const T &) const;
    void Insert(const T &);
    template <class T2>
    friend ostream &operator<<(ostream &out, const Cache<T2> &cache);

private:
    T *storage;
    const int MaxSize;
    int hash(const T &) const;
};

#endif

