//a表示短串，b表示长串
//返回a在b中第一次出现的下标
char a[10005],b[1000005];
int fail[10005];
void getFail(char *str)
{
    fail[0]=fail[1]=0;
    for(int i=1; str[i]; ++i)
    {
        int j=fail[i];
        while(j&&str[i]!=str[j]) j=fail[j];
        fail[i+1]=(str[i]==str[j])?j+1:0;
    }
}
int Kmp(char *a,char *b)
{
    getFail(a);
    for(int i=0,j=0;b[i];++i)
    {
        while(j!=0&&b[i]!=a[j]) j=fail[j];
        if(b[i]==a[j]) ++j;
        if(a[j]==0) return i-j+1;
    }
    return -1;
}
