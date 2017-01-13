#include <iostream>
#include <cstring>

using namespace std;

struct Task{
    unsigned int priority;
    char name[9];

    Task(int p,char *s);
};

Task::Task(int p,char *s):priority(p){
    int i;
    for(i=0;i<strlen(s);i++){
        name[i]=s[i];
    }
}

int main()
{
    cout<<sizeof(int)<<endl;
    cout<<sizeof(Task)<<endl;
    cout << "Hello world!" << endl;
    return 0;
}
