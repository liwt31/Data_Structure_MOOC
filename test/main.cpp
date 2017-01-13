#include <iostream>

using namespace std;

template<typename T>
class base{
    int priv;
protected:
    int prot;
public:
    int publ;
};

template<typename T>
class deriv:public base<T>{
    int test();
};

template<typename T>
int deriv<T>::test(){
    return prot;
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
