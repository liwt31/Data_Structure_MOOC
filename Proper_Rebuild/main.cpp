#include <iostream>
#include <cstdio>

using namespace std;

typedef int Rank;

Rank Search(const int *int_array,Rank begin,Rank end,int target){//backward search
    Rank i;
    for(i=end-1;i!=begin-1;i--){
        if(int_array[i]==target){
            return i;
        }
    }
    return i;
}

void Rebuild(int *pre,Rank pre_begin,Rank pre_end,int *post,Rank post_begin,Rank post_end,int *in,Rank in_begin, Rank in_end, Rank* pre_index){
    if(pre_end-pre_begin==1&&in_end-in_begin==1){
        in[in_begin]=pre[pre_begin];
        return;
    }
    if(pre[pre_begin]!=post[post_end-1]){
        cout<<"division error"<<endl;
    }
    int p=pre[pre_begin];
    int rc=post[post_end-2];
    Rank pre_rc_rank=pre_index[rc];
    Rank lc_len=pre_rc_rank-(pre_begin+1);
    in[in_begin+lc_len]=p;
    Rebuild(pre,pre_begin+1,pre_rc_rank,post,post_begin,post_begin+lc_len,in,in_begin,in_begin+lc_len,pre_index);
    Rebuild(pre,pre_rc_rank,pre_end,post,post_begin+lc_len,post_end-1,in,in_begin+lc_len+1,in_end,pre_index);
}

int main()
{
    setvbuf(stdin, new char[1<<20],_IOFBF,1<<20);
    setvbuf(stdout, new char[1<<20],_IOFBF,1<<20);
    int n;cin>>n;
    int *pre=new int[n];
    for(int i=0;i<n;i++){
        scanf("%d",pre+i);
    }
    Rank *pre_index=new Rank[n+1];
    for(int i=0;i<n;i++){
        pre_index[pre[i]]=i;
    }
    int *post=new int[n];
    for(int i=0;i<n;i++){
        scanf("%d",post+i);
    }
    int *in=new int[n];
    Rank pre_begin,post_begin,in_begin;
    Rank pre_end,post_end,in_end;
    pre_begin=post_begin=in_begin=0;
    pre_end=post_end=in_end=n;
    Rebuild(pre,pre_begin,pre_end,post,post_begin,post_end,in,in_begin,in_end,pre_index);
    for(int i=0;i<n;i++){
        printf("%d ",in[i]);
    }
    printf("\n");
    return 0;
}
