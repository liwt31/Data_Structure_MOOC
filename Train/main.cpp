#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

class Stack{
    int *_elem;
    int _sz;
public:
    Stack(){
        _elem=new int[1600010];
        _sz=0;
    }

    int sz()const{return _sz;}
    bool empty()const{return _sz==0;}
    int top()const{return _elem[_sz-1];}
    int peek(int r)const{return _elem[r];}

    void push(int e){_elem[_sz++]=e;}
    int pop(){return _elem[--_sz];}

    void print(){
        for(int i=0;i<_sz;i++){
            printf("%d ",_elem[i]);
        }
        printf("\n");
    }
};

int main()
{
    int n,m;
    scanf("%d %d\n",&n,&m);
    Stack A,B;
    for(int i=n;0<i;i--){
        A.push(i);
        int temp;
        scanf("%d",&temp);
        B.push(temp);
    }
    int B_pointer=0;
    string answer;
    Stack S;
    while(1){
        if(S.empty()){
            if(A.empty()){
                break;
            }
            S.push(A.pop());
            answer.append("push\n");
            continue;
        }
        if(S.sz()>m){
            answer="No\n";
            break;
        }
        if(S.top()==B.peek(B_pointer)){
            S.pop();
            answer.append("pop\n");
            B_pointer++;
            continue;
        }else{
            if(A.empty()){
                answer="No\n";
                break;
            }
            S.push(A.pop());
            answer.append("push\n");
        }
    }
    cout<<answer;
    return 0;
}
