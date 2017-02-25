#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

struct Point{
    int x,y;
    bool operator<(Point& p2){return x<p2.x;}
    bool operator<=(Point& p2){return x<=p2.x;}
    Point& operator=(Point& p2){x=p2.x;y=p2.y;return *this;}
};

void InsertSort(Point* points,int lo,int hi){
    for(int i=lo+1;i<hi;i++){
        Point point2insert=points[i];
        int j=i;
        while(lo<j&&point2insert<points[j-1]){
            points[j]=points[j-1];
            j--;
        }
        points[j]=point2insert;
    }
}

void QuickSort(Point* points,int lo,int hi){
    if(hi-lo<4){
        InsertSort(points,lo,hi);
        return;
    }
    Point pivot=points[lo];
    int i=lo,j=hi-1;
    while(i!=j){
        while(i!=j&&pivot<=points[j]){
            j--;
        }
        points[i]=points[j];
        while(i!=j&&points[i]<=pivot){
            i++;
        }
        points[j]=points[i];
    }
    points[i]=pivot;
    QuickSort(points,lo,i);
    QuickSort(points,i+1,hi);
}

void PrintPoints(Point* points,int n){
    for(int i=0;i<n;i++){
        printf("%d-%d\n",points[i].x,points[i].y);
    }
}

long long GetSeqNum(Point* points,int lo,int hi){
    if(hi-lo==1) return 0;
    if(hi-lo==2){
        if(points[lo].y<=points[lo+1].y){
            return 1;
        }else{
            Point temp=points[lo];
            points[lo]=points[lo+1];
            points[lo+1]=temp;
            return 0;
        }
    }
    int mi=(lo+hi)/2;
    long long result=GetSeqNum(points,lo,mi)+GetSeqNum(points,mi,hi);
    Point *left_points=new Point[mi-lo];
    for(int i=0;i<mi-lo;i++){
        left_points[i]=points[lo+i];
    }
    Point *right_points=points+mi;
    for(int i=0,j=0;i<mi-lo||j<hi-mi;){
        if(j==hi-mi||(i!=mi-lo&&left_points[i].y<right_points[j].y)){
            points[lo+i+j]=left_points[i];
            i++;
        }else{
            points[lo+i+j]=right_points[j];
            j++;
            result+=i;
        }
    }
    delete left_points;
    return result;
}

int main()
{
    int n;scanf("%d",&n);
    Point *points=new Point[n];
    for(int i=0;i<n;i++){
        int xx,yy;
        scanf("%d %d",&xx,&yy);
        points[i].x=xx;
        points[i].y=yy;
    }
    QuickSort(points,0,n);
    cout<<GetSeqNum(points,0,n)<<endl;
    return 0;
}
