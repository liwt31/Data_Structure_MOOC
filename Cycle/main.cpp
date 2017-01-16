#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>

using namespace std;

long long HashInt(int a,int b){
    long long result=b+1;
    for(int i=0;i<b;i++){
        result*=a+13;
    }
    return result+a;
}

long long Hash(char * str){
    long long hash=0;
    long long sum=0;
    int sz=strlen(str);
    for(int i=0;i<sz-1;i++){
        hash^=HashInt(str[i]-'A',str[i+1]-'A');
        sum+=str[i];
    }
    hash^=HashInt(str[sz-1]-'A',str[0]-'A');
    sum+=str[sz-1];
    return hash+sum;
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
