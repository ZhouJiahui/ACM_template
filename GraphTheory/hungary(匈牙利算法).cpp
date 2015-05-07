//用于求二分图最大匹配
//时间复杂度约为O(n^3)
//注意区分n和m
#include <cstring>
const int maxn=500;
const int maxm=500;
bool g[maxn][maxm];
int link[maxn];
bool vis[maxm];
int n,m;
bool match(int x)
{
    for(int i=0; i<m; ++i)if(g[x][i])
        {
            if(!vis[i])
            {
                vis[i]=true;
                if(link[i]==-1||match(link[i]))
                {
                    link[i]=x;
                    return true;
                }
            }
        }
    return false;
}
int solve()
{
    memset(link,-1,sizeof(link));
    int ans=0;
    for(int i=0; i<n; ++i)
    {
        memset(vis,0,sizeof(vis));
        if(match(i))
            ++ans;
    }
    return ans;
}
