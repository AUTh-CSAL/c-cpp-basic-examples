#include <iostream>
#include <math.h>
#include <string>
using namespace std;

template <typename X, typename F> X *map(F func, X *a, int size) {
    X *b = new X[size];
    for (int i = 0; i < size; i++)
        b[i] = (*func)(a[i], i + 1);
    return b;
}

template <typename X, typename F> X reduce(F binop, X *a, X nullVal, int size) {
    X b = nullVal;
    for (int i = 0; i < size; i++)
        b = (*binop)(b, a[i]);
    return b;
}

template <typename T> T f(T k, int i) { return pow(k, i); }
template <typename T> T binop(T b, T a) { return b + a; }

int main(void) {

    int k[]    = {1, 2, 3, 4, 5};
    string l[] = {"hello", " ", "world"};

    int n = sizeof(k) / sizeof(k[0]);

    int *q       = map(&f<int>, k, n);
    int aq       = reduce(&binop<int>, q, 0, n);
    string l_str = reduce(&binop<string>, l, string(""), 3);

    for (int i = 0; i < n; i++)
        cout << q[i] << ' ';

    cout << endl << aq << endl << l_str;

    delete[] q;
    return 0;
}