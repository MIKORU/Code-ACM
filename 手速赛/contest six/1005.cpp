//Memory Time
//184K  422MS
#include <string.h>
#include <stdio.h>
#include<iostream>
using namespace std;

int map[10][10];

bool row[10][10];
bool col[10][10];
bool grid[10][10];



bool DFS(int x,int y)
{
    if(x==10)
        return true;

    bool flag=false;

    if(map[x][y])
    {
        if(y==9)
            flag=DFS(x+1,1);
        else
            flag=DFS(x,y+1);

        if(flag)
            return true;
        else
            return false;
    }
    else
    {

        int k=3*((x-1)/3)+(y-1)/3+1;

        for(int i=1;i<=9;i++)
            if(!row[x][i] && !col[y][i] && !grid[k][i])
            {
                map[x][y]=i;

                row[x][i]=true;
                col[y][i]=true;
                grid[k][i]=true;

                if(y==9)
                    flag=DFS(x+1,1);
                else
                    flag=DFS(x,y+1);

                if(!flag)
                {
                    map[x][y]=0;

                    row[x][i]=false;
                    col[y][i]=false;
                    grid[k][i]=false;
                }
                else
                    return true;
            }
    }
    return false;
}

int main(int i,int j)
{
    int test;
    cin>>test;
    while(test--)
    {
        memset(row,false,sizeof(row));
        memset(col,false,sizeof(col));
        memset(grid,false,sizeof(grid));
        char MAP[10][10];
        for(i=1;i<=9;i++)
            for(j=1;j<=9;j++)
            {
                cin>>MAP[i][j];
                map[i][j]=MAP[i][j]-'0';

                if(map[i][j])
                {
                    int k=3*((i-1)/3)+(j-1)/3+1;
                    row[i][ map[i][j] ]=true;
                    col[j][ map[i][j] ]=true;
                    grid[k][ map[i][j] ]=true;
                }
            }


        if(DFS(1,1)==1)
            printf("It's OK.\n");
        else printf("Damn it!\n");
    }
    return 0;
}
