#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 32000;
int primes[N], ps, prime[N];

void euclidao (int &x, int &y, int p, int q){
    if(q == 0){
        x = 1, y = 0 ;
        return;
    }
    euclidao(x, y, q, p%q);
    int t = y;
    y = x - (p/q)*y;
    x = t;
}

int main(){ 
    int n, t, p, q;
    scanf("%d",&t);
    for(int i = 2; i < N; i++) {
        if(prime[i]) continue;
        primes[ps++] = i;
        for(int j = i*i; j < N; j += i)
            prime[j] = i;
    }

    while(t--) {
        scanf("%d",&n);
        for(int i = 0; i < ps; i++){
            if(n%primes[i] == 0) {
                p = primes[i];
                q = n/primes[i];
                break;
            }
        }
        int x,y;
        euclidao(x,y,p,q);
        printf("0 1 ");
        if(x > 0) printf("%d %d\n",x*p, (y+p)*q);
        else printf("%d %d\n",y*q,(x+q)*p);
    }
}
