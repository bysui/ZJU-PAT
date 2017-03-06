#include <stdio.h>

int main()
{
    int a, b, sum;
    int p1, p2, p3;

    scanf("%d%d", &a, &b);
    sum = a + b;
    if (sum < 0){
        printf("-");
        sum = -sum;
    }
    p1 = sum / 1000000;
    p2 = sum / 1000 % 1000;
    p3 = sum % 1000;

    if (p1)
        printf("%d,%03d,%03d\n", p1, p2, p3);
    else{
        if (p2)
            printf("%d,%03d\n", p2, p3);
        else
            printf("%d\n", p3);
    }

    return 0;
}
