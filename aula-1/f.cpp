#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
const int N = 112345;

int n, k, d;
char s[N], t[N];

char dist(char c) {
    if(c-'a' > 'z'-c) return 'a';
    return 'z';
}

char fix(char c) {
    if(c-'a'+k < 26) return c+k;
    else return c-k;
}

int main(){
    scanf("%d %d",&n,&k);
    scanf(" %s", s);
    for(int i = 0; s[i]; i++) {
        char m = dist(s[i]);
        int q = abs(m-s[i]);
        if(q > k) { t[i] = fix(s[i]); k = 0; }
        else { t[i] = m, k -= q; }
    }
    if(k) {
        puts("-1");
        return 0;
    }
    t[strlen(s)] = 0;
    puts(t);
}
