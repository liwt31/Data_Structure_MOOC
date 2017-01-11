#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

template<typename T>
class Hash{
    T *bucket;
    bool *occupation;

protected:
    int sz;
    virtual int HashFunc(const T t)=0;
public:
    Hash(int s);    //s should be primal, determined by the user
    T* FindPtr(T t)const;
    bool Insert(T t);
};

//template<typename T>
//int Hash<T>::HashFunc(const T t){
//    srand(t);
//    return rand()%sz;
//}

template<typename T>
Hash<T>::Hash(int s):sz(s){
    bucket=new T[s];
    occupation=new bool[s];
    for(int i=0;i<s;i++){
        occupation[i]=false;
    }
}

template<typename T>
T* Hash<T>::FindPtr(T t){
    int rank=HashFunc(t);
    while(occupation[rank]){
        if(bucket[rank]==t){
            return bucket+rank;
        }
        rank++;
    }
    return NULL;
}

template<typename T>
bool Hash<T>::Insert(T t){
    T *t_ptr=FindPtr(t);
    if(t_ptr){
        t_ptr=t;
        return true;
    }else{
        return false;
    }
}


template<typename T>
class Hash4String:public Hash<T>{
    int HashFunc(const T s);
public:
    Hash4String(int s):Hash<T>(s){};
};

template<typename T>
int Hash4String<T>::HashFunc(const T s){
    int result=0;
    for(unsigned int i=0;i<strlen(s);i++){
        result*=26;
        result+=s[i]-'a';
    }
    srand(result);
    return rand()%Hash<T>::sz;
}

int main()
{
    const int sz=1594123
    Hash4String<char*> Dic(sz);
    Hash4STring<char*> Redund(sz);
    int n;
    scanf("%d\n",&n);
    for(int i=0;i<n;i++){
        char word[45];
        gets(word);
        if(!Dic.Insert(word)){
            puts(word);
        }
    }
    return 0;
}
