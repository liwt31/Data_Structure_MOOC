#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

long long Pow(int x,int n){
    long long result=1;
    for(int i=0;i<n;i++){
        result*=x;
    }
    return result;
}

long long Hash(char * str){
    long long hash=0;
    int sz=strlen(str);
    for(int i=0;i<sz-1;i++){
        hash^=Pow(str[i+1]-str[i],str[i]-'A');
    }
    hash^=Pow(str[0]-str[sz-1],str[sz-1]-'A');
    return hash;
}

int main()
{
    setvbuf(stdin, new char[1<<20],_IOFBF,1<<20);
    setvbuf(stdout, new char[1<<20],_IOFBF,1<<20);
    char * str1=new char[100001];
    char * str2=new char[100001];
    while(scanf("%s %s",str1,str2)!=EOF){
        if(strlen(str1)!=strlen(str2)){
            printf("NO\n");
            continue;
        }
        if(Hash(str1)==Hash(str2)){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }

    return 0;
}
