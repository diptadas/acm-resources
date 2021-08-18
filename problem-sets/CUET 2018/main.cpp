#include <bits/stdc++.h>
using namespace std;

#define LL long long

LL x[50], y[50];

LL count(LL dx, LL dy)
{
    LL ds = dx + dy;
    if (dx == 0 || dy == 0)
        return ds;

    LL gc = __gcd(dx, dy);
    dx /= gc;
    dy /= gc;

    if (dx % 2 != 0 && dy % 2 != 0)
        ds -= gc;

    return ds;
}

int main()
{
    LL tc, n, i, j, dx, dy, sum;
    scanf("%lld", &tc);
    while (tc--)
    {
        scanf("%lld", &n);
        for (i = 0; i < n; i++)
            scanf("%lld %lld", &x[i], &y[i]);
        for (sum = 0, i = 1; i < n; i++)
        {
            dx = abs(x[i] - x[i - 1]);
            dy = abs(y[i] - y[i - 1]);
            sum += count(dx, dy);
            if (sum > 2000000000)
            {
                sum = -1;
                break;
            }
        }
        if (sum == -1)
            printf("SORRY\n");
        else
            printf("%lld\n", sum);
    }

    return 0;
}

/*
$ g++ main.cpp
$ ./a.out < sample.in > out-test.out
$ diff -s out-test.out sample.out
*/