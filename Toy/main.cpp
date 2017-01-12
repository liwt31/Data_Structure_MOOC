#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

template<typename T>
struct Qnode{
    T data;
    Qnode* next;

    Qnode<T>(T d):data(d),next(NULL){};
};

template<typename T>
class Queue{
    Qnode<T>* front_ptr;
    Qnode<T>* end_ptr;
public:
    Queue<T>();
    bool IsEmpty()const{return front_ptr==NULL;}
    void Push(T &data);
    T Pop();
};

template<typename T>
Queue<T>::Queue(){
    front_ptr=end_ptr=NULL;
}

template<typename T>
void Queue<T>::Push(T &data){
    Qnode<T> *new_node=new Qnode<T>(data);
    if(!IsEmpty()){
        end_ptr->next=new_node;
    }else{
        front_ptr=new_node;
    }
    end_ptr=new_node;
}

template<typename T>
T Queue<T>::Pop(){
    if(front_ptr==end_ptr){
        end_ptr=NULL;
    }
    Qnode<T> *old_front=front_ptr;
    front_ptr=front_ptr->next;
    T bak=old_front->data;
    delete old_front;
    return bak;
}


class Toy{
    int toy[2][4];
protected:
    void TransformA(Toy &new_toy)const;
    void TransformB(Toy &new_toy)const;
    void TransformC(Toy &new_toy)const;
public:
    int step;

    template<typename T> friend class Hash;

    Toy():step(-1){};
    Toy(const Toy &t2){*this=t2;}
    bool operator==(const Toy &t2)const;
    void print()const;
    Toy& operator=(const Toy &t2);
    void SetToy(int r, int n){(r<4? toy[0][r%4]:toy[1][3-r%4])=n;}
    Toy Transform(int type)const;

};

bool Toy::operator==(const Toy &t2)const{
    for(int i=0;i<2;i++){
        for(int j=0;j<4;j++){
            if(toy[i][j]!=t2.toy[i][j]){
                return false;
            }
        }
    }
    return true;
}

void Toy::print()const{
    for(int r=0;r<8;r++){
        cout<<(r<4? toy[0][r%4]:toy[1][3-r%4])<<" ";
    }
    cout<<endl;
}

Toy& Toy::operator=(const Toy &t2){
    if(this!=&t2){
        for(int i=0;i<2;i++){
            for(int j=0;j<4;j++){
                toy[i][j]=t2.toy[i][j];
            }
        }
        step=t2.step;
    }
    return *this;
}

Toy Toy::Transform(int type)const{
    Toy new_toy=*this;
    switch(type){
    case(0):
    TransformA(new_toy);
    break;
    case(1):
    TransformB(new_toy);
    break;
    case(2):
    TransformC(new_toy);
    break;
    default:
    break;
    }
    new_toy.step=step+1;
    return new_toy;
}

void Toy::TransformA(Toy &new_toy)const{
    for(int i=0;i<4;i++){
        int temp=new_toy.toy[0][i];
        new_toy.toy[0][i]=new_toy.toy[1][i];
        new_toy.toy[1][i]=temp;
    }
}

void Toy::TransformB(Toy &new_toy)const{
    int temp0=new_toy.toy[0][0];
    int temp1=new_toy.toy[1][0];
    for(int i=0;i<3;i++){
        new_toy.toy[0][i]=new_toy.toy[0][i+1];
        new_toy.toy[1][i]=new_toy.toy[1][i+1];
    }
    new_toy.toy[0][3]=temp0;
    new_toy.toy[1][3]=temp1;
}

void Toy::TransformC(Toy &new_toy)const{
    int temp=new_toy.toy[0][1];
    new_toy.toy[0][1]=new_toy.toy[0][2];
    new_toy.toy[0][2]=new_toy.toy[1][2];
    new_toy.toy[1][2]=new_toy.toy[1][1];
    new_toy.toy[1][1]=temp;
}


template<typename T>
class Hash{
    T *bucket;
    bool *occupation;

protected:
    int sz;
    int HashFunc(const T &t)const;
public:
    Hash(int s);    //s should be primal, determined by the user
    T& Find(const T &t)const;
    bool Insert(const T &t);
};

template<typename T>
Hash<T>::Hash(int s):sz(s){
    bucket=new T[s];
    occupation=new bool[s];
    for(int i=0;i<s;i++){
        occupation[i]=false;
    }
}

template<typename T>
T& Hash<T>::Find(const T &t)const{
    int rank=HashFunc(t);
    while(occupation[rank]){
        if(bucket[rank]==t){
            return bucket[rank];
        }
        rank++;
    }
    return bucket[rank];
}

template<typename T>
bool Hash<T>::Insert(const T &t){
    int rank=HashFunc(t);
    while(occupation[rank]){
        if(bucket[rank]==t){
            return false;
        }
        rank++;
    }
    bucket[rank]=t;
    return occupation[rank]=true;
}

template<>
int Hash<Toy>::HashFunc(const Toy &t)const{
    int result=0;
    for(int i=0;i<2;i++){
        for(int j=0;j<4;j++){
            result*=9;
            result+=t.toy[i][j];
        }
    }
    srand(result);
    return rand()%sz;
}

int main()
{
    Hash<Toy> database(130003);
    Toy playing;
    for(int i=0;i<8;i++){
//        int temp;scanf("%d",&temp);playing.SetToy(i,temp);
        playing.SetToy(i,i+1);
    }
    playing.step=0;
    database.Insert(playing);
    Queue<Toy> q_toy;
    q_toy.Push(playing);
    while(!q_toy.IsEmpty()){
        Toy parent=q_toy.Pop();
        for(int i=0;i<3;i++){
            Toy child=parent.Transform(i);
            if(database.Insert(child)){
//                child.print();
                q_toy.Push(child);
            }
        }
    }
    int N;scanf("%d",&N);
    for(int i=0;i<N;i++){
        Toy target;
        for(int j=0;j<8;j++){
            int temp;
            scanf("%d",&temp);
            target.SetToy(j,temp);
        }
//        database.Find(target).print();
        printf("%d\n",database.Find(target).step);
    }
    return 0;
}
