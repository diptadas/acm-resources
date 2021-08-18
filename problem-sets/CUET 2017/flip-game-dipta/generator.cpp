#include <bits/stdc++.h>

int moves[101];

void print(int n, int m)
{
    printf("%d %d\n",n,m);
    for(int i=0; i<m; i++)
    {
        if(i==m-1) printf("%d\n",moves[i]);
        else printf("%d ",moves[i]);
    }
}

int randInt(int mn, int mx)
{
    if(mn==mx) return mn;
    return (rand()%(mx-mn))+mn;
}

int main()
{
    // freopen("input.in", "w", stdout);

    int t,i,j,k,n,m,mn,mx;

    printf("%d\n",100);

    // sample-1
    n=4,m=3;
    moves[0]=10,moves[1]=13,moves[2]=8;
    print(n,m);    

    // sample-2
    n=3,m=4;
    moves[0]=6,moves[1]=1,moves[2]=7,moves[3]=4;
    print(n,m);

    // sample-3
    n=4,m=6;
    moves[0]=11,moves[1]=9,moves[2]=5,moves[3]=12,moves[4]=8,moves[5]=6;
    print(n,m);
    
    // special-1
    n=1,m=1;
    for(i=0;i<m;i++) moves[i]=1;
    print(n,m);

    // special-2
    n=1,m=100;
    for(i=0;i<m;i++) moves[i]=1;
    print(n,m);

    // special-3
    n=2,m=1;
    for(i=0;i<m;i++) moves[i]=1;
    print(n,m);

    // special-4
    n=2,m=4;
    for(i=0;i<m;i++) moves[i]=(i%(n*n))+1;
    print(n,m);

    // special-5
    n=10,m=1;
    for(i=0;i<m;i++) moves[i]=1;
    print(n,m);

    // special-6
    n=10,m=1;
    for(i=0;i<m;i++) moves[i]=100;
    print(n,m);

    // special-7
    n=10,m=100;
    for(i=0;i<m;i++) moves[i]=100;
    print(n,m);

    // special-8
    n=10,m=100;
    for(i=0;i<m;i++) moves[i]=1;
    print(n,m);

    // special-9
    n=10,m=100;
    for(i=0;i<m;i++) moves[i]=(i%(n*n))+1;
    print(n,m);

    // special-10
    n=10,m=55;
    for(i=0;i<m;i++) moves[i]=(i%(n*n))+1;
    print(n,m);

    // special-11
    n=9,m=1;
    for(i=0;i<m;i++) moves[i]=81;
    print(n,m);

    // special-12
    n=9,m=1;
    for(i=0;i<m;i++) moves[i]=1;
    print(n,m);

    // special-13
    n=9,m=100;
    for(i=0;i<m;i++) moves[i]=81;
    print(n,m);

    // special-14
    n=9,m=100;
    for(i=0;i<m;i++) moves[i]=1;
    print(n,m);

    // special-15
    n=8,m=55;
    for(i=0;i<m;i++) moves[i]=(i%(n*n))+1;
    print(n,m);

    t=100-3-15;
    while(t--)
    {
        n=randInt(1,10);
        m=randInt(1,100);
        for(i=0; i<m; i++)  moves[i]=randInt(1, n*n);
        print(n, m);
    }

    return 0;
}
