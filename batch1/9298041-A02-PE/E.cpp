#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

char s[123];
int n;

void suc(int x){ 
    printf("YES\n%d\n",x); 
    exit(0); 
}

int appears(int x) {
    if(x == 0) {
        for(int i = 0; s[i]; i++) if(s[i] == '0') return 1;
        return 0;
    }
    for(int i = n-1; i >= 0; i--) {
        if(s[i]-'0' == x%10) x /= 10;
        if(x == 0) return 1;
    }
    return 0;
}

int main(){
    scanf(" %s",s);
    n = strlen(s);
    for(int i = 0; i < 1000; i++)
        if(i%8 == 0 && appears(i))
            suc(i);
    puts("NO");
}
