#include <iostream>
#include <cstdio>

using namespace std;

struct Edge;

struct Vertex{
    Edge* edge;

    Vertex(){edge=NULL;}
    ~Vertex();
    void AddEdge(Vertex* v_dst);
};

struct Edge{
    Vertex * dst;
    Edge* next_edge;

    Edge* InsertEdgeBefore(Vertex* v_dst);
};

Vertex::~Vertex(){
    while(edge){
        Edge* old_edge=edge;
        edge=edge->next_edge;
        delete old_edge;
    }
}

void Vertex::AddEdge(Vertex* v_dst){
    if(edge){
        edge->InsertEdgeBefore(v_dst);
    }else{
        edge=new Edge;
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
public:
    Vertex* GetVertex(int r)const{return vec_vertex+r;}
    Graph(int n);
    ~Graph();
};

Graph::Graph(int n){
    vec_vertex=new Vertex[n];
}

Graph::~Graph(){
    delete[] vec_vertex;
}

int main()
{
    int n,m;cin>>n>>m;
    Graph g(n);
    for(int i=0;i<m;i++){
        int r_src,r_dst;
        scanf("%d %d",&r_src,&r_dst);
        Vertex* v_src=g.GetVertex(r_src);
        Vertex* v_dst=g.GetVertex(r_dst);
        v_src->AddEdge(v_dst);
    }
    cout << "Hello world!" << endl;
    return 0;
}
