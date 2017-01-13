#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

template<typename T>
class Vector{
protected:
    int sz;
    int capacity;
    T *data;
    void Expand();
public:
    Vector(int n);
    Vector(Vector &v2);
    ~Vector();
    Vector& operator=(Vector &v2);
    bool Empty()const{return sz==0;}
    T& operator[](int rank)const{return data[rank];}
    int GetSz()const{return sz;}
    void Print()const;
    void Reserve(int n);
    T PushBack(T t);
    void Swap(int rank0,int rank1);
};

template<typename T>
Vector<T>::Vector(int n){
    sz=n;
    capacity=n<3? 5:2*n;
    data = new T[capacity];
}

template<typename T>
Vector<T>::Vector(Vector &v2){
    (*this)=v2;
}

template<typename T>
Vector<T>::~Vector(){
    delete [] data;
}

template<typename T>
Vector<T>& Vector<T>::operator=(Vector &v2){
    sz=v2.sz;
    capacity=v2.capacity;
    delete [] data;
    data=new T[capacity];
    for(int i=0;i<sz;i++){
        data[i]=v2.data[i];
    }
    return *this;
}

template<typename T>
void Vector<T>::Print()const{
    for(int i=0;i<sz;i++){
        cout<<data[i]<<" ";
        if((1+sz)%10==0){
            cout<<endl;
        }
    }
    cout<<endl;
}

template<typename T>
void Vector<T>::Expand(){
    if(sz<capacity){
        return;
    }
    capacity*=2;
    T * old_data=data;
    data=new T[capacity];
    for(int i=0;i<sz;i++){
        data[i]=old_data[i];
    }
    delete [] old_data;
}

template<typename T>
void Vector<T>::Reserve(int n){
    capacity=n;
    T *old_data=data;
    data=new T[capacity];
    for(int i=0;i<n;i++){
        data[i]=old_data[i];
    }
    delete [] old_data;
}

template<typename T>
T Vector<T>::PushBack(T t){
    Expand();
    data[sz++]=t;
    return t;
}

template<typename T>
void Vector<T>::Swap(int rank0,int rank1){
    T temp=data[rank0];
    data[rank0]=data[rank1];
    data[rank1]=temp;
}

template<typename T>
class PrioriyQueue:public Vector<T>{    //minheap
    using Vector<T>::sz;
    using Vector<T>::capacity;
    using Vector<T>::data;
    using Vector<T>::Reserve;
protected:

    inline int LChild(int rank)const{return 2*rank+1;}
    inline int RChild(int rank)const{return 2*(rank+1);}
    inline int Parent(int rank)const{return (rank-1)/2;}
    void PercolateUp(int rank);
    void PercolateDown(int rank);
public:
    using Vector<T>::PushBack;
    using Vector<T>::Swap;
    PrioriyQueue(int n=5):Vector<T>(0){Reserve(n);}
    void Heapify();
    T Push(T t);
    T Pop();
};

template<typename T>
void PrioriyQueue<T>::Heapify(){
    for(int i=sz-1;i>=0;i--){
        PercolateDown(i);
    }
}

template<typename T>
void PrioriyQueue<T>::PercolateUp(int rank){
    while(0<rank&&data[rank]<data[Parent(rank)]){
        Swap(rank,Parent(rank));
        rank=Parent(rank);
    }
}

template<typename T>
void PrioriyQueue<T>::PercolateDown(int rank){
    while(1){
    //    cout<<sz<<" "<<rank<<endl;
        T p_data =data[rank];
        if(LChild(rank)<sz&&RChild(rank)<sz){
            T l_data =data[LChild(rank)];
            T r_data =data[RChild(rank)];
            if(l_data<p_data&&l_data<=r_data){
                Swap(rank,LChild(rank));
                rank=LChild(rank);
            }else if(r_data<p_data&&r_data<l_data){
                Swap(rank,RChild(rank));
                rank=RChild(rank);
            }else{
                break;
            }
        }else if(LChild(rank)<sz){
            T l_data =data[LChild(rank)];
            if(l_data<p_data){
                Swap(rank,LChild(rank));
                rank=LChild(rank);
            }else{
                break;
            }
        }else if(RChild(rank)<sz){
            T r_data =data[RChild(rank)];
            if(r_data<p_data){
                Swap(rank,RChild(rank));
                rank=RChild(rank);
            }else{
                break;
            }
        }else{
            break;
        }
    }
}

template<typename T>
T PrioriyQueue<T>::Push(T t){
    PushBack(t);
    PercolateUp(sz-1);
    return t;
}

template<typename T>
T PrioriyQueue<T>::Pop(){
    T max_prio=data[0];
 //   cout<<"----------------------"<<endl;
 //   cout<<"before swap :"<<endl;
 //   Vector<T>::Print();
    Swap(0,--sz);
 //   cout<<"after swap :"<<endl;
 //   Vector<T>::Print();
    PercolateDown(0);;
 //   cout<<"after percolation "<<endl;
 //   Vector<T>::Print();
 //   cout<<"----------------------"<<endl;
    return max_prio;
}

struct Task{
    unsigned int priority;
    char name[9];

    Task(){};
    Task(int p,char *s);
    bool operator==(Task &t2)const;
    bool operator<(Task &t2)const;
    bool operator<=(Task &t2)const{return (*this)<t2||(*this)==t2;}
    void Print();
};

Task::Task(int p,char *s):priority(p){
    unsigned int i;
    for(i=0;i<strlen(s);i++){
        name[i]=s[i];
    }
    name[i]=0;
}

bool Task::operator==(Task &t2)const{
    if(priority!=t2.priority){
        return false;
    }else{
        if(strcmp(name,t2.name)==0){
            return true;
        }else{
            return false;
        }
    }
}

bool Task::operator<(Task &t2)const{
    if(priority!=t2.priority){
        return priority<t2.priority;
    }else{
        if(strcmp(name,t2.name)<0){
            return true;
        }else{
            return false;
        }
    }
}

void Task::Print(){
//    printf("%u ",priority);
    printf("%s\n",name);
}



int main()
{
    int n;int m;
    cin>>n>>m;
    PrioriyQueue<Task> pq_task(n);
    for(int i=0;i<n;i++){
        int priority;
        char name[9];
        scanf("%d ",&priority);
        gets(name);
        pq_task.PushBack(Task(priority,name));
    }
    pq_task.Heapify();
    for(int i=0;i<m;i++){
        if(pq_task.Empty()){
            break;
        }
        Task t=pq_task.Pop();
        t.Print();
        if(t.priority<0x80000000){
            t.priority*=2;
            pq_task.Push(t);
        }
    }

    return 0;
}