//maxn表示单词个数×单词长度
//wsize表示字典大小

#include <cstring>
const int maxn=1000005;
const int wsize=30;
struct Trie
{
    int sz;
    int node[maxn][wsize];
    int val[maxn];
    void init()
    {
        sz=0;
        memset(node[0],-1,sizeof(node[0]));
        val[0]=0;
    }
    int getId(char c)
    {
        return c-'a';
    }
    int getNewNode()
    {
        ++sz;
        memset(node[sz],-1,sizeof(node[sz]));
        val[sz]=0;
        return sz;
    }
    void insert(char *word)
    {
        int p=0;
        for(int i=0; word[i]; ++i)
        {
            int x=getId(word[i]);
            if(node[p][x]==-1)
                node[p][x]=getNewNode();
            p=node[p][x];
            ++val[p];
        }
    }
};
Trie tree;
