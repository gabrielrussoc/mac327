#include <cstdio>
#include <cstring>
#include <vector>
#define pb push_back
using namespace std;

const int N = 11234;
int n;
int v[N], acc[N], f[N];

int main(){
    scanf("%d",&n);
    for(int i = 0; i < n; i++) scanf("%d",v+i);
    acc[0] = 0;
    for(int i = 1; i <= n; i++) {
        acc[i] = (acc[i-1] + v[i-1])%n;
        if(!f[acc[i]]) f[acc[i]] = i;
        if(acc[i] == 0) {
            printf("%d\n",i);
            for(int j = 0; j < i; j++) printf("%d\n",v[j]);
            return 0;
        }
    }
    for(int i = n; i > 0; i--) {
        if(f[acc[i]] != i) {
            printf("%d\n",i-f[acc[i]]);
            for(int j = f[acc[i]]; j < i; j++) printf("%d\n",v[j]);
            return 0;
        }
    }


}
