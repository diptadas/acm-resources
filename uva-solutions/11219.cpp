#include <stdio.h>
int main()
{
    int t,i,a,b,c,d,e,f;
    char ch;
    scanf("%d",&t);
    for(i=0; i<t; i++)
    {
        scanf("%d%c%d%c%d",&a,&ch,&b,&ch,&c);
        scanf("%d%c%d%c%d",&d,&ch,&e,&ch,&f);
        if(a<d) b--;
        if(b<e) c--;
        if(c<f) printf("Case #%d: Invalid birth date\n",i+1);
        else if(c-f>130) printf("Case #%d: Check birth date\n",i+1);
        else printf("Case #%d: %d\n",i+1,c-f);
    }
    return 0;
}
