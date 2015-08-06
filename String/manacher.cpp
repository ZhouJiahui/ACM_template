const int maxn=1000005;
char str[maxn];
char new_str[maxn*2];
int p[maxn*2];
int len;
void init()
{
        len=0;
        for(int i=0;str[i];++i)
        {
                new_str[len++]='#';
                new_str[len++]=str[i];
        }
        new_str[len++]='#';
        new_str[len]=0;
}
int manacher()
{
        int maxId=0,maxRight=0;
        for(int i=1;i<len;++i)
        {
                if(i<maxRight)
                        p[i]=min(maxRight-i,p[maxId*2-i]);
                else
                        p[i]=1;
                while(i-p[i]>=0&&i+p[i]<len&&new_str[i-p[i]]==new_str[i+p[i]])
                        ++p[i];
                if(i+p[i]>maxRight)
                {
                        maxRight=i+p[i];
                        maxId=i;
                }
        }
        int best=0;
        for(int i=0;i<len;++i)
                if(p[i]>p[best])
                        best=i;
        return p[best]-1;
}
