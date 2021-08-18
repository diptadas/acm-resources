// Author: Dipta Das

#include <bits/stdc++.h>

char dir[51];
bool arr[51];
int x[51], y[51];

int main()
{
    freopen("input.in", "r", stdin);
    // freopen("output.out", "w", stdout);

    int t = 1, tc, i, ii, j, k;

    scanf("%d", &tc);

    while (tc--)
    {
        memset(arr, 0, sizeof(arr));

        scanf("%d %s", &k, dir);
        for (i = 0; i < k; i++)
            scanf("%d", &x[i]);
        for (i = 0; i < k; i++)
            scanf("%d", &y[i]);

        for (i = 0; i < k; i++)
        {
            x[i] *= 2;
            y[i] *= 2;
        }

        int ret = k;

        for (ii = 0; ii < 500; ii++)
        {
            for (i = 0; i < k; i++)
            {
                if (dir[i] == 'N')
                    y[i]++;
                else if (dir[i] == 'S')
                    y[i]--;
                else if (dir[i] == 'E')
                    x[i]++;
                else if (dir[i] == 'W')
                    x[i]--;
            }

            for (i = 0; i < k; i++)
            {
                bool ci = false;
                for (j = i + 1; j < k; j++)
                {
                    if (!arr[i] && !arr[j] && x[i] == x[j] && y[i] == y[j])
                    {
                        ret--;
                        arr[j] = 1;
                        ci = true;
                    }
                }
                if (ci)
                {
                    ret--;
                    arr[i] = 1;
                }
            }
        }

        printf("Case %d: %d", t++, ret);
        for (i = 0; i < k; i++)
        {
            if (!arr[i])
                printf(" %d", i + 1);
        }
        puts("");
    }

    return 0;
}
