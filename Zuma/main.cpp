#include <cstdio>

using namespace std;

struct Node{
    char c;
    Node *pred,*succ;
    Node(char cc, Node* p=NULL, Node* s=NULL):c(cc),pred(p),succ(s){};
    Node* InsertBefore(char cc){
        Node *new_node=new Node(cc,pred,this);
        pred->succ=new_node;
        pred=new_node;
        return new_node;
    }
    char RemoveBefore(){
        Node* node2delete=pred;
        node2delete->pred->succ=this;
        pred=node2delete->pred;
        char cc=node2delete->c;
        delete node2delete;
        return cc;
    }
};

struct List{
    Node *head,*tail;
    int sz;
    List(){
        head=new Node(0);
        tail=new Node(0);
        head->succ=tail;
        tail->pred=head;
        sz=0;
    }
    Node* Get(int n)const{
        Node* result=head->succ;
        while(n--){
            result=result->succ;
        }
        return result;
    }
    Node* InsertAtLast(char cc){
        sz++;
        return tail->InsertBefore(cc);
    }
    Node* InsertBefore(Node *cur,char cc){
        sz++;
        return cur->InsertBefore(cc);
    }
    char RemoveBefore(Node* cur){
        sz--;
        return cur->RemoveBefore();
    }
    void PrintList()const{
        if(sz==0){
            printf("-\n");
            return;
        }
        for(Node* posi=head->succ;posi!=tail;posi=posi->succ){
            printf("%c",posi->c);
        }
        printf("\n");
    }
    Node* Check(Node* new_node){
        if(sz<3||new_node==tail) return NULL;
        char cc=new_node->c;
        int same_sz=1;
        Node* prev_node=new_node->pred;
        while(prev_node->c==cc){
            same_sz++;
            prev_node=prev_node->pred;
        }
        Node* subs_node=new_node->succ;
        while(subs_node->c==cc){
            same_sz++;
            subs_node=subs_node->succ;
        }
        if(same_sz<3) return NULL;
        for(int i=0;i<same_sz;i++){
            RemoveBefore(subs_node);
        }
        return subs_node;
    }
};

int main()
{
    setvbuf(stdin, new char[1<<20],_IOFBF,1<<20);
    setvbuf(stdout, new char[1<<20],_IOFBF,1<<20);
    char ini_seq[10001];
    gets(ini_seq);
    List seq;
    int i=0;
    while(ini_seq[i]){
        seq.InsertAtLast(ini_seq[i]);
        i++;
    }
    int n;scanf("%d",&n);
    for(int i=0;i<n;i++){
        int r;char cc;
        scanf("%d %c",&r,&cc);
        Node* new_node=seq.InsertBefore(seq.Get(r),cc);
        while(new_node){
            new_node=seq.Check(new_node);
        }
        seq.PrintList();
    }
    return 0;
}
