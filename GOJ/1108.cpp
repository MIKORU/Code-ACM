#include<stdio.h>
char chMap[150][150] ;
const int nDir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}} ;
int m = 0 ;
int n = 0 ;
int bX = 0 ;
int bY = 0 ;
int DFS(int x,int y)
{
	int i = 0 ;
	int j = 0 ;
	if(x < 0 || y < 0 || x >= n || y >= m)
        return 0 ;
	for(i = 0 ; i < 4 ; ++i)
	{
		if('P' == chMap[x+nDir[i][0]][y+nDir[i][1]])
            return 1 ;
		else if('.' == chMap[x+nDir[i][0]][y+nDir[i][1]])
		{
			chMap[x+nDir[i][0]][y+nDir[i][1]] = '#' ;
			if(DFS(x+nDir[i][0],y+nDir[i][1])== 1 )
                return 1 ;
			chMap[x+nDir[i][0]][y+nDir[i][1]] = '.' ;
		}
	}
	return 0 ;
}
int main()
{
	int i = 0 ;
	int j = 0 ;
	while(scanf("%d",&n)!=EOF)
    {
        m=n;
        getchar();
        for(i = 0 ; i < n ; ++i)
        {
            for(j = 0 ; j < m ; ++j)
            {
                scanf("%c",&chMap[i][j]) ;
                if(chMap[i][j]=='B'  )
                {
                    bX = i ;
                    bY = j ;
                }
            }
            getchar();
        }

        if(DFS(bX,bY)== 1)
            printf("Yes\n");
        else
            printf("No\n");
    }
	return 0 ;
}

