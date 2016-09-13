#include <cmath>
#include <cstdio>
#define MAX 100000

long long v[MAX];
long long c,t,x,y,i,p,r;

int buscab(int ini, int fim, long long d){
    if(ini == fim) return ini;
    int mid = (ini + fim)/2;

    if(d <= v[mid]*v[mid]) return buscab(ini,mid,d);
    return buscab(mid+1, fim, d);
}

int main(){
    scanf("%lld %lld",&c,&t);

    for(i = 0; i < c; i++)
        scanf("%lld",&v[i]);

    for(i = 0; i < t; i++){
        scanf("%lld %lld",&x,&y);
        r = (x*x + y*y);
        if(r <= v[c-1]*v[c-1])
            p += c - buscab(0,c-1,r);
    }

    printf("%lld\n",p);
}

