#include <iostream>

struct X
{
    X() {}
};
struct Y
{
    Y() {}    
};

template <typename T>
struct B
{
    void f(X){}
    void operator[](X){}
};

template <typename T>
struct C
{
    void f(Y){}
    void operator[](Y){}
};

template <typename T>
struct D : B<T>, C<T>
{
};

int main()
{
    D<float> d;
    d[Y()];
    return 0;
}
