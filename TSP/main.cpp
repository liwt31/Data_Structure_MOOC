#include <iostream>
#include <cstdio>

using namespace std;

struct Edge;

enum Vstatus{UNDISCOVERED,VISITED};

struct Vertex{
    Edge* edge;
    int in_degree;
    int d_from_beg;
    Vstatus v_s;

    Vertex():edge(NULL),in_degree(0),d_from_beg(0),v_s(UNDISCOVERED){};
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
    v_dst->in_degree++;
}

Edge* Edge::InsertEdgeBefore(Vertex* v_dst){
    Edge* new_edge=new Edge;
    new_edge->dst=v_dst;
    new_edge->next_edge=this;
    return new_edge;
}

class Graph{
    Vertex* vec_vertex;
    int TSP(Vertex* v_beg);
    int TSP_rec(Vertex *parent);
    int sz;
public:
    Graph(int n);
//    ~Graph();
    Vertex* GetVertex(int r)const{return vec_vertex+r;}
    int Tsp();
};

Graph::Graph(int n){
    vec_vertex=new Vertex[n];
    sz=n;
}

//Graph::~Graph(){
//    delete vec_vertex;
//}

int Graph::TSP_rec(Vertex *parent){
    parent->v_s=VISITED;
    int dst=parent->d_from_beg;
//    cout<<dst<<endl;
    for(Edge* edge=parent->edge;edge!=NULL;edge=edge->next_edge){
//        cout<<"enter edge cycle"<<endl;
        Vertex* child=edge->dst;
        child->in_degree--;
//        cout<<"child: "<<child->d_from_beg<<"  parent: "<<parent->d_from_beg<<endl;
        if(child->d_from_beg<parent->d_from_beg+1){
//            cout<<"enter increase d_from_beg branch"<<endl;
            child->d_from_beg=parent->d_from_beg+1;
        }
        if(child->v_s==UNDISCOVERED&&child->in_degree==0){  //若可以当做下一个点进行伸展
            int new_dst=TSP_rec(child);
            dst=new_dst>dst? new_dst:dst;
        }
    }
    return dst;
}

int Graph::TSP(Vertex* v_beg){  //只需要考虑一颗生成树

    return TSP_rec(v_beg)+1;//num of villages is 1 greater than total distance
}

int Graph::Tsp(){
    int max=0;
    for(int i=0;i<sz;i++){
        bool flag=1;
        for(int j=0;j<sz;j++){
            if((vec_vertex+j)->v_s==UNDISCOVERED&&(vec_vertex+j)->in_degree==0){
                flag=0;
                int dst=TSP(vec_vertex+j);
//                cout<<"enter outer cycle, dst got: "<<dst<<endl;
                max=max>dst? max:dst;
            }
        }
        if(flag) break;
    }
    return max;
}

int main()
{
    int n,m;cin>>n>>m;
    Graph g(n);
    for(int i=0;i<m;i++){
        int r_src,r_dst;
        scanf("%d %d",&r_src,&r_dst);
        Vertex* v_src=g.GetVertex(r_src-1);
        Vertex* v_dst=g.GetVertex(r_dst-1);
        v_src->AddEdge(v_dst);
    }
    cout<<g.Tsp()<<endl;
    return 0;
}
