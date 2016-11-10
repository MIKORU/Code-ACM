void dfs(int num)
{
    if(num == m+1)
    {
        for(int i = 1;i <= n;i++)
        if(on[i] != off[i])
        return ;
        ans++;return ;
    }
    int u = x[num] , v = y[num] ;
    if((on[u] < degree[u]/2) && (on[v] < degree[v]/2))
    {
        on[u]++;on[v]++;
        dfs(num+1);
        on[u]--;on[v]--;
    }
    if(off[v] < degree[v]/2 && off[u] < degree[u]/2)
    {
        off[u]++;off[v]++ ;
        dfs(num+1) ;
        off[u]--;off[v]-- ;
    }
}
