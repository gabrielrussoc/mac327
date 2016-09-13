#include <cstdio>
using namespace std;

const int N = 11234;
int p[N], primes[N], ps, n;
int ans[N];

int main(){
    for(int i = 2; i < N; i++) {
        if(p[i]) continue;
        primes[ps++] = i;
        for(int j = i; j < N; j += i)
            p[j] = i;
    }
    scanf("%d",&n);
    for(int i = 2; i <= n; i++) {
        int x = i;
        while(x > 1) {
            ans[p[x]]++;
            x /= p[x];
        }
    }
    int m;
    for(int i = 0; i < N; i++) if(ans[i]) m = i;
    for(int i = 2; i < N; i++) if(ans[i]) printf("%d^%d%s",i,ans[i],i==m ? "" : " * ");
    putchar('\n');
        

}
