#include <iostream>
#include <cstdio>
#include "temperature.h"

using namespace std;

//distribution of child
//1|3
//---
//0|2

template<typename Ta,typename Td>
struct Quad_node{
    Ta x,y;
    Td data;

    Ta x_min,x_max,y_min,y_max;

    int num_node;
    Td average;
    Td mod;

    Quad_node<Ta,Td> *child[4];
    Quad_node(const Ta &xx=0,const Ta &yy=0,const Td &d=0);
    void Print()const;
    void UpdateBound(const Ta &xx,const Ta &yy);
    void UpdateAverage(const int &d);
};

template<typename Ta,typename Td>
Quad_node<Ta,Td>::Quad_node(const Ta &xx,const Ta &yy,const Td &d)
    :x(xx),y(yy),data(d),x_min(xx),x_max(xx),y_min(yy),y_max(yy),
     num_node(1),average(d),mod(0){
    for(int i=0;i<4;i++){
        child[i]=NULL;
    }
}

template<typename Ta,typename Td>
void Quad_node<Ta,Td>::Print()const{
    cout<<"("<<x<<","<<y<<")->"<<data<<endl
    <<"bound: "<<x_min<<" "<<x_max<<" "<<y_min<<" "<<y_max<<endl
    <<"average:  "<<num_node<<" "<<average<<" "<<mod<<endl;
}

template<typename Ta,typename Td>
void Quad_node<Ta,Td>::UpdateBound(const Ta &xx,const Ta &yy){
    if(xx<x_min){
        x_min=xx;
    }else if(x_max<xx){
        x_max=xx;
    }
    if(yy<y_min){
        y_min=yy;
    }else if(y_max<yy){
        y_max=yy;
    }
}

template<>
void Quad_node<int,int>::UpdateAverage(const int &d){
    long long sum=average*num_node+mod+d;
    num_node++;
    mod=sum%num_node;
    average=sum/num_node;
}

template<typename Ta,typename Td>
class Quad_tree{
    Quad_node<Ta,Td> *root;
    mutable Quad_node<Ta,Td> *parent;
protected:
    const Quad_node<Ta,Td> *Find4iFromNode(const Ta &xx,const Ta &yy,const Td &d,Quad_node<Ta,Td> *node_ptr);
    const Quad_node<Ta,Td> *Find4i(const Ta &xx,const Ta &yy,const Td &d);
    void PrintFromNode(const Quad_node<Ta,Td>* node_ptr)const;
public:
    Quad_tree();
    int Query(const Ta x1,const Ta y1,const Ta x2,const Ta y2)const;
    void Print()const;
    void Insert(const Ta &xx,const Ta &yy,const Td &d);
};

template<typename Ta,typename Td>
Quad_tree<Ta,Td>::Quad_tree():root(NULL),parent(NULL){};

template<typename Ta,typename Td>
const Quad_node<Ta,Td> *Quad_tree<Ta,Td>::Find4iFromNode(const Ta &xx,const Ta &yy,const Td &d,Quad_node<Ta,Td> *node_ptr){
    if(node_ptr==NULL){
        return NULL;
    }
    if(node_ptr->x==xx&&node_ptr->y==yy){
        return node_ptr;
    }
    node_ptr->UpdateBound(xx,yy);
    node_ptr->UpdateAverage(d);
    int child_rank=2*((node_ptr->x)<xx)+((node_ptr->y)<yy);
    parent=node_ptr;
    return Find4iFromNode(xx,yy,d,node_ptr->child[child_rank]);
}

template<typename Ta,typename Td>
const Quad_node<Ta,Td> *Quad_tree<Ta,Td>::Find4i(const Ta &xx,const Ta &yy,const Td &d){
    parent=root;
    return Find4iFromNode(xx,yy,d,root);
}

template<typename Ta,typename Td>
void Quad_tree<Ta,Td>::PrintFromNode(const Quad_node<Ta,Td>* node_ptr)const{
    if(node_ptr==NULL){
        return;
    }
    for(int i=0;i<4;i++){
        if(node_ptr->child[i]){
            PrintFromNode(node_ptr->child[i]);
        }
    }
    node_ptr->Print();
}

template<typename Ta,typename Td>
void Quad_tree<Ta,Td>::Print()const{
    PrintFromNode(root);
}

template<typename Ta,typename Td>
void Quad_tree<Ta,Td>::Insert(const Ta &xx,const Ta &yy,const Td &d){
    if(!root){
        root=new Quad_node<Ta,Td>(xx,yy,d);
        return;
    }
    if(Find4i(xx,yy,d)){
        return;
    }
    int child_rank=2*((parent->x)<xx)+((parent->y)<yy);
    parent->child[child_rank]=new Quad_node<Ta,Td>(xx,yy,d);
}

template<>
int Quad_tree<int,int>::Query(const int x1,const int y1,const int x2,const int y2)const{
    struct QueryAtNode{
        const Quad_tree<int,int> *tree_ptr;
        const int x1;
        const int y1;
        const int x2;
        const int y2;
        mutable long long accumulation;
        mutable int num_node;

        QueryAtNode(const Quad_tree<int,int> *ptr,int xx1,int yy1,int xx2,int yy2):
            tree_ptr(ptr),x1(xx1),y1(yy1),x2(xx2),y2(yy2),accumulation(0),num_node(0){};
        inline bool AllInRange(const Quad_node<int,int> *node_ptr)const{
            return x1<=node_ptr->x_min&&node_ptr->x_max<=x2&&y1<=node_ptr->y_min&&node_ptr->y_max<=y2;
        }
        inline bool InRange(const Quad_node<int,int> *node_ptr)const{
            return x1<=node_ptr->x&&node_ptr->x<=x2&&y1<=node_ptr->y&&node_ptr->y<=y2;
        }
        inline bool InChild(const Quad_node<int,int> *node_ptr,int n)const{
            switch(n){
            case(0):return x1<=node_ptr->x&&y1<=node_ptr->y;
            case(1):return x1<=node_ptr->x&&node_ptr->y<=y2;
            case(2):return node_ptr->x<=x2&&y1<=node_ptr->y;
            case(3):return node_ptr->x<=x2&&node_ptr->y<=y2;
            default:return false;
            }
        }

        void operator()(const Quad_node<int,int> *node_ptr)const{
            if(node_ptr==NULL){
                return;
            }
            if(AllInRange(node_ptr)){
 //               cout<<node_ptr->average<<" "<<node_ptr->num_node<<" "<<node_ptr->mod<<endl;
                accumulation+=node_ptr->average*node_ptr->num_node+node_ptr->mod;
                num_node+=node_ptr->num_node;
                return;
            }
            if(InRange(node_ptr)){
                accumulation+=node_ptr->data;
                num_node++;
            }
            for(int i=0;i<4;i++){
                if(InChild(node_ptr,i)){
                    (*this)(node_ptr->child[i]);
                }
            }

        }
    }query(this,x1,y1,x2,y2);

    query(root);

    if(query.num_node==0){
        return 0;
    }
    return query.accumulation/query.num_node;
}

int main()
{
    int n=GetNumOfStation();
    Quad_tree<int,int> stat_temp;
    for(int i=0;i<n;i++){
        int x,y,temp;
        GetStationInfo(i,&x,&y,&temp);
 //       cout<<"input: "<<x<<" "<<y<<" "<<temp<<endl;
        stat_temp.Insert(x,y,temp);
    }
    int x1,y1,x2,y2;
 //   stat_temp.Print();
    while(GetQuery(&x1,&y1,&x2,&y2)){
        Response(stat_temp.Query(x1,y1,x2,y2));
    }
    return 0;
}
