#include <iostream>
#include <cstdio>

using namespace std;

void Merge(int *data,int lo,int mid, int hi){
    int *left_side = new int[mid-lo];
    for(int i=0;i<mid-lo;i++){
        left_side[i]=data[lo+i];
    }
    int *right_side = data+mid;
    for(int l=0,r=0;l<mid-lo||r<hi-mid;){
        if(l!=mid-lo&&(r==hi-mid||left_side[l]<right_side[r])){
            data[lo+l+r]=left_side[l];
            l++;
        }
        if(r!=hi-mid&&(l==mid-lo||right_side[r]<left_side[l])){
            data[lo+l+r]=right_side[r];
            r++;
        }
    }
    delete left_side;
}

void SortArray(int *data,int lo,int hi){
    if(hi-lo<2) return;
    int mid=(lo+hi)/2;
    SortArray(data,lo,mid);
    SortArray(data,mid,hi);
    Merge(data,lo,mid,hi);
}

int Search(int *data,int lo, int hi, int target){
    while(lo<hi){
        int mid=(hi+lo)/2;
        if(data[mid]<=target){
            lo=mid+1;
        }else{
            hi=mid;
        }
    }
    return lo-1;
}

void PrintArray(int *data,int n){
    for(int i=0;i<n;i++){
        printf("%d ",*(data+i));
    }
    printf("\n");
}

int main()
{
    int n;int m;
    scanf("%d %d",&n,&m);
    int *data=new int[n];
    for(int i=0;i<n;i++){
        scanf("%d",data+i);
    }
    SortArray(data,0,n);
    for(int i=0;i<m;i++){
        int low_bound,high_bound;
        scanf("%d %d",&low_bound,&high_bound);
        int low_rank=Search(data,0,n,low_bound),high_rank=Search(data,0,n,high_bound);
        printf("%d\n",high_rank-low_rank+(data[low_rank]==low_bound));
    }
    return 0;
}
