#include <bits/stdc++.h>
#define left first
#define right second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<double, double> pdd;

const int N = 11234;

const int EPS = 1e-9;
double a, b, lin, rin;
pdd in[N]; 
int sz, n, p[N], v[N];

bool comp(int i, int j){
    return in[i] < in[j];
}

int main() {
    scanf("%lf %lf",&a,&b);
    scanf("%d",&n);
    for(int i = 0; i < n; i++) {
        scanf("%lf %lf",&lin,&rin);
        in[i] = pdd(lin, rin);
        p[i] = i;
    }
    sort(p, p+n, comp);
    double last = a;
    int i = 0;
    while(last + EPS < b) {
        int j = i;
        while(i < n && in[p[i]].left < last + EPS){
            if(in[p[j]].right < in[p[i]].right + EPS) j = i;
            i++;
        }
        v[sz++] = j;
        last = in[p[j]].right;
    }
    double r = 0;
    for (int i = 0; i < sz; i += 2) r += in[p[v[i]]].right - in[p[v[i]]].left;
    if (3. * r >= 2. * (b-a) - EPS) {
        printf("%d\n", (sz+1)/2);
        for(int i = 0; i < sz; i += 2)
            printf("%d\n",p[v[i]]+1);
        return 0;
    }  
    r = 0;
    for (int i = 1; i < sz; i += 2) r += in[p[v[i]]].right - in[p[v[i]]].left;
    if (3. * r >= 2. * (b-a) - EPS) {
        printf("%d\n", sz/2);
        for(int i = 1; i < sz; i += 2)
            printf("%d\n",p[v[i]]+1);
        return 0;
    }
    printf("%d\n",sz);
    for(int i = 0; i < sz; i++) printf("%d\n",p[v[i]]+1);
}

