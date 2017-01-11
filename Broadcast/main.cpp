#include <iostream>
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
    void Push(T data);
    T Pop();
};

template<typename T>
Queue<T>::Queue(){
    front_ptr=end_ptr=NULL;
}

template<typename T>
void Queue<T>::Push(T data){
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

struct Edge;

enum Vstatus{UNDISCOVERED,BLACK,WHITE};

struct Vertex{
    Edge* edge;
    Vstatus v_s;

    Vertex():edge(NULL),v_s(UNDISCOVERED){};
//    ~Vertex();
    void AddEdge(Vertex* v_dst);
};

struct Edge{
    Vertex *src;
    Vertex *dst;
    Edge* next_edge;

    Edge* InsertEdgeBefore(Vertex* v_dst);
};

//Vertex::~Vertex(){
//    while(edge){
//        Edge* old_edge=edge;
//        edge=edge->next_edge;
//        delete old_edge;
//    }
//}

void Vertex::AddEdge(Vertex* v_dst){
    if(edge){
        edge=edge->InsertEdgeBefore(v_dst);
        edge->src=this;
    }else{
        edge=new Edge;
        edge->src=this;
        edge->dst=v_dst;
        edge->next_edge=NULL;
    }
}

Edge* Edge::InsertEdgeBefore(Vertex* v_dst){
    Edge* new_edge=new Edge;
    new_edge->dst=v_dst;
    new_edge->next_edge=this;
    return new_edge;
}

class Graph{
    Vertex* vec_vertex;
    int sz;
public:
    Graph(int n);
//    ~Graph();
    void AddUndiedge(int r_src, int r_dst);
    bool Coloring();
};

Graph::Graph(int n){
    vec_vertex=new Vertex[n];
    sz=n;
}

void Graph::AddUndiedge(int src, int dst){
    vec_vertex[src].AddEdge(vec_vertex+dst);
    vec_vertex[dst].AddEdge(vec_vertex+src);
}

bool Graph::Coloring(){
    Queue<Vertex*> q_vert;
    vec_vertex->v_s=BLACK;
    q_vert.Push(vec_vertex);
    while(!q_vert.IsEmpty()){
        Vertex* parent=q_vert.Pop();
        for(Edge* edge=parent->edge;edge!=NULL;edge=edge->next_edge){
            Vertex* child=edge->dst;
            if(child->v_s==UNDISCOVERED){
                switch(parent->v_s){
                case(BLACK):
                    child->v_s=WHITE;
                    break;
                case(WHITE):
                    child->v_s=BLACK;
                    break;
                default:
                    break;
                }
                q_vert.Push(child);
            }else{
                if(child->v_s==parent->v_s){
                    return false;
                }
            }
        }
    }
    return true;
}

int main()
{
    int n,m;cin>>n>>m;
    Graph g(n);
    for(int i=0;i<m;i++){
        int r_src,r_dst;
        scanf("%d %d",&r_src,&r_dst);
        g.AddUndiedge(r_src-1,r_dst-1);
    }
    cout<<(g.Coloring()? 1:-1)<<endl;
    return 0;
}
