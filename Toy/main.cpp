#include <iostream>

using namespace std;

class Toy{
    int toy[2][4];
public:
 //   friend class Toy;
    bool operator==(const Toy &t2)const;
    void SetToy(int r, int n){(r>4? toy[0][r%4]:toy[1][3-r%4])=n;}
    void TransformA();
    void TransformB();
    void TransformC();
};

bool Toy::operator==(const Toy &t2)const{
    for(int i=0;i<8;i++){
        if(toy[i]!=t2.toy[i]){
            return false;
        }
    }
    return true;
}

void Toy::TransformA(){
    int temp[4];
    for(int i=0;i<4;i++){
        temp[i]=toy[0][i];
        toy[0][i]=toy[1][i];
        toy[1][i]=temp[i];
    }
}

void Toy::TransformB(){
    int temp0=toy[0][3];
    int temp1=toy[1][3];
    for(int i=3;i>0;i--){
        toy[0][i+1]=toy[0][i];
        toy[1][i+1]=toy[0][i];
    }
    toy[0][0]=temp0;
    toy[1][0]=temp0;
}

void Toy::TransformC(){
    int temp=toy[0][1];
    toy[0][1]=toy[1][1];
    toy[1][1]=toy[1][2];
    toy[1][2]=toy[0][2];
    toy[0][2]=temp;
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
