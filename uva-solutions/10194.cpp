#include <iostream>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
using namespace std;

struct team
{
    char t_name[31];
    int played,point,win,tie,loss,gs,ga,gd;
} temp;

int lex(char s1[], char s2[])
{
    int i=0;
    while (toupper(s1[i]) && toupper(s2[i]))
    {
        if (toupper(s1[i]) == toupper(s2[i])) i++;
        else return (toupper(s1[i]) < toupper(s2[i]));
    }
    return (toupper(s1[i]) < toupper(s2[i]));
}

int cmp(struct team tm1,struct team tm2)
{
    if(tm1.point!=tm2.point)
        return(tm1.point>tm2.point);
    if(tm1.win!=tm2.win)
        return(tm1.win>tm2.win);
    if(tm1.gd!=tm2.gd)
        return(tm1.gd>tm2.gd);
    if(tm1.gs!=tm2.gs)
        return(tm1.gs>tm2.gs);
    if(tm1.played!=tm2.played)
        return(tm1.played<tm2.played);
    return(lex(tm1.t_name,tm2.t_name));
}

void sort(struct team tm[],int tn)
{
    int i,j;
    for(i=0; i<tn; i++)
    {
        for(j=0; j<tn-i-1; j++)
        {
            if(cmp(tm[j+1],tm[j]))
            {
                temp= tm[j];
                tm[j]= tm[j+1];
                tm[j+1]=temp;
            }
        }
    }
}

int main()
{
    int t,i,j,tn,gn,g1,g2,t1,t2;
    char name[101],team_1[31],team_2[31],ch;
    scanf("%d",&t);

    for(; t; t--)
    {
        getchar();
        gets(name);
        scanf("%d",&tn);
        getchar();
        struct team tm[tn];

        for(i=0; i<tn; i++)
        {
            gets(tm[i].t_name);
            tm[i].played=0,tm[i].point=0,tm[i].win=0,tm[i].tie=0,tm[i].loss=0,tm[i].gs=0,tm[i].ga=0,tm[i].gd=0;
        }

        scanf("%d",&gn);

        for(i=0; i<gn; i++)
        {
            getchar();
            scanf("%[^#] %c %d %c %d %c %[^\n]",team_1,&ch,&g1,&ch,&g2,&ch,team_2);

            for(j=0; j<tn; j++)
            {
                if(strcmp(team_1,tm[j].t_name)==0) t1=j;
                else if(strcmp(team_2,tm[j].t_name)==0) t2=j;
            }

            tm[t1].played++;
            tm[t2].played++;
            tm[t1].gs+=g1;
            tm[t1].ga+=g2;
            tm[t1].gd+=g1-g2;
            tm[t2].gs+=g2;
            tm[t2].ga+=g1;
            tm[t2].gd+=g2-g1;

            if(g1>g2)
            {
                tm[t1].win++;
                tm[t2].loss++;
                tm[t1].point+=3;
            }
            else if(g1<g2)
            {
                tm[t2].win++;
                tm[t1].loss++;
                tm[t2].point+=3;
            }
            else
            {
                tm[t1].tie++;
                tm[t2].tie++;
                tm[t1].point++;
                tm[t2].point++;
            }
        }

        sort(tm,tn);
        puts(name);
        for(i=0; i<tn; i++)
        {
            printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n",
                   i+1,tm[i].t_name,tm[i].point,tm[i].played,tm[i].win,tm[i].tie,tm[i].loss,tm[i].gd,tm[i].gs,tm[i].ga);
        }
        if(t-1) printf("\n");
    }
    return 0;
}
