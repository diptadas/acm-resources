#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
    int m,n,i;
    while(scanf("%d",&n) && n!=0)
    {
        queue<int> cards;
        for(i=1; i<=n; i++) cards.push(i);

        printf("Discarded cards:");

        while(cards.size()>1)
        {
            if(cards.size()==2) printf(" %d",cards.front());
            else printf(" %d,",cards.front());
            cards.pop();
            m=cards.front();
            cards.pop();
            cards.push(m);
        }
        printf("\nRemaining card: %d\n",cards.front());
    }
    return 0;
}

