#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
//#include <cstdio>
using namespace std;

int mult(int number, int &zeroCount)
{
    if (number < 10) return number;

    int newNumber = 1;
    while (number) 
    {
        int units = number % 10;
        number /= 10;
        if (units) newNumber *= units;
        else ++zeroCount;
    }

    return mult(newNumber, zeroCount);
}

int main()
{
    int n;
    while (true){
        scanf("%d", &n);
        if (!n) break;

        int zeroCount = 0;
        printf("%d", mult(n, zeroCount));
        printf("%d\n", zeroCount);
    }

    return 0;
}
