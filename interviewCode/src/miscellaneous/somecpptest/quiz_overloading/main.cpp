#include "../quiz_overloading/matrix.h"

using namespace std;

bool isSquare(Matrix);
Matrix makeIdentity(int);

int main ()
{
    Matrix a(2,3), b(3,2), c(2,3), d, e, f;

    a.access(0,0) = 1;
    a.access(0,1) = 2;
    a.access(0,2) = 3;
    a.access(1,0) = 1.125;
    a.access(1,1) = 2.125;
    a.access(1,2) = 3.125;

    c.access(0,0) = 1;
    c.access(0,1) = 2;
    c.access(0,2) = 3;
    c.access(1,0) = 1.125;
    c.access(1,1) = 2.125;
    c.access(1,2) = 3.125;

    b.access(0,0) = 1;
    b.access(0,1) = 2;
    b.access(1,0) = 1.125;
    b.access(1,1) = 2.125;
    b.access(1,0) = 1.125;
    b.access(1,1) = 2.125;

    // scalar multiplication
    d = a * b;
    e = a + c;
    f = a - c;
    cout << a << b << c << d << e << f;
}

bool isSquare(Matrix m)
{
    return (m.getRowCount() == m.getColCount());
}

Matrix makeIdentity (int size)
{
    int i;
    Matrix retVal(size, size);

    for (i = 0; i < size; i++)
    retVal.access(i, i) = 1;

    return retVal;
}
