#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

int RandInt(){
    int result=rand()*rand()*rand();
    if(rand()%2){
        result*=-1;
    }
    return result;
}

int main()
{
    ofstream fout("temperature.in");
    srand(clock());
    const int N=20000;
    const int M=N*10;
    fout<<N<<" "<<M<<endl;
    for(int i=0;i<N;i++){
        fout<<RandInt()<<" "<<RandInt()<<" "<<RandInt()<<endl;
    }
    for(int i=0;i<M;i++){
        int x1=RandInt();
        int x2;
        do{
            x2=RandInt();
        }while(x2<x1);
        int y1=RandInt();
        int y2;
        do{
            y2=RandInt();
        }while(y2<y1);
        fout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
    }
    cout << "Hello world!" << endl;
    return 0;
}
