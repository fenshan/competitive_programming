#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

int main()
{
    int n;  
    scanf("%d", &n);

    while (n--) {

        bool zero = false, nine = false;

        float  grade;
        for (int i = 0; i < 5; ++i)
        {
            scanf("%f", &grade);
            if (grade == 0) zero = true;
            else if (grade >= 9) nine = true;
        }

        if (zero && !nine) printf("SUSPENSO DIRECTO\n");
        else printf("MEDIA\n");
    }

    return 0;
}

