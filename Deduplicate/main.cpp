#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

struct Word{
    char word[45];
    int sz;

    Word(){};
    Word(char *s);
    bool operator==(const Word &w2)const;
    Word& operator=(const Word &w2);
};

Word::Word(char *s){
    sz=strlen(s);
    for(int i=0;i<sz;i++){
        word[i]=s[i];
    }
    word[sz]=0;
//    cout<<"size of "<<s<<" is "<<sz<<endl;
}

bool Word::operator==(const Word &w2)const{
    if(sz!=w2.sz){
        return false;
    }
    for(int i=0;i<sz;i++){
        if(word[i]!=w2.word[i]){
            return false;
        }
    }
    return true;
}

Word& Word::operator=(const Word &w2){
    sz=w2.sz;
    for(int i=0;i<=sz;i++){
        word[i]=w2.word[i];
    }
    return *this;
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
//    T* FindPtr(const T &t)const;
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
int Hash<Word>::HashFunc(const Word &w)const{
    int result=0;
    for(int i=0;i<w.sz;i++){
        result*=26;
        result+=w.word[i]-'a';
    }
    srand(result);
    return rand()%sz;
}

int main()
{
    const int sz=1594123;
    Hash<Word> Dic(sz);
    Hash<Word> Redund(sz);
    int n;
    scanf("%d\n",&n);
    for(int i=0;i<n;i++){
        char s_word[45];
        gets(s_word);
        Word word(s_word);
        if(!Dic.Insert(word)){
            if(Redund.Insert(word)){
                puts(word.word);
            }
        }
    }
    return 0;
}
