#include <iostream>
#include <cstdio>

using namespace std;

enum Direction{FORWARD,BACKWARD};
typedef int Rank;

Rank Search(int *int_array,Rank begin,Rank end,int target,Direction d){
    Rank i;
    if(d==FORWARD){
        for(i=begin;i!=end;i++){
            if(int_array[i]==target){
                return i;
            }
        }
    }else{  //BACKWARD
        for(i=end-1;i!=begin-1;i--){
            if(int_array[i]==target){
                return i;
            }
        }
    }
    return i;
}

void Rebuild(int *pre,Rank pre_begin,Rank pre_end,int *post,Rank post_begin,Rank post_end,int *in,Rank in_begin, Rank in_end){
    if(pre_end-pre_begin==1&&in_end-in_begin){
        in[in_begin]=pre[pre_begin];
        return;
    }
    if(pre[pre_begin]!=post[post_end-1]){
        cout<<"division error"<<endl;
    }
    int p=pre[pre_begin];
//  int lc=pre[pre_begin+1];
    int rc=post[post_end-2];
    Rank pre_rc_rank=Search(pre,pre_begin+2,pre_end,rc,BACKWARD);
    Rank lc_len=pre_rc_rank-(pre_begin+1);
    in[lc_len]=p;
    Rebuild(pre,pre_begin+1,pre_rc_rank,post,post_begin,post_begin+lc_len,in,in_begin,in_begin+lc_len);
    Rebuild(pre,pre_rc_rank,pre_end,post,post_begin+lc_len,post_end-1,in,in_begin+lc_len+1,in_end);
}

int main()
{
    int n;cin>>n;
    int *pre=new int[n];
    for(int i=0;i<n;i++){
        scanf("%d",pre+i);
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
    Rebuild(pre,pre_begin,pre_end,post,post_begin,post_end,in,in_begin,in_end);
    for(int i=0;i<n;i++){
        printf("%d ",in[i]);
    }
    printf("\n");
    return 0;
}
