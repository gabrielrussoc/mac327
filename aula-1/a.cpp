#include <cstdio>
using namespace std;

int main(){
    int t, s, x;
    scanf("%d %d %d",&t, &s, &x);
    int k = (x-t)%s;
    if(x < t) puts("NO");
    else if(!k) puts("YES");
    else if(x >= t+s){
        k = (x-t-1)%s;
        if(!k) puts("YES");
        else puts("NO");
    } else puts("NO");
}

