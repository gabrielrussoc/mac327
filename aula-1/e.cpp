#include <cstdio>
using namespace std;

int fc, sc, tc, x, n;
int v[105];
int f[3][105];

int main() {
    scanf("%d",&n);
    int neg = 0, pos = 0;
    for(int i = 0; i < n; i++) { scanf("%d",v+i); if(v[i] < 0) neg++; else if (v[i] > 0) pos++; }
    int need;
    int z;
    need = z = 0;

    if(!pos) need = 2;
    if(neg % 2 == 0) z = 1;

    for(int i = 0; i < n; i++) {
        if(v[i] < 0) {
            if(need) { f[0][fc++] = v[i]; need--; }
            else if(z) { f[2][tc++] = v[i]; z--; }
            else f[1][sc++] = v[i];
        } else if (v[i] > 0) f[0][fc++] = v[i];
        else f[2][tc++] = v[i];
    }
    printf("%d ",sc);
    for(int i = 0; i < sc; i++) printf("%d%c",f[1][i],i == sc -1 ? '\n' : ' ');
    printf("%d ",fc);
    for(int i = 0; i < fc; i++) printf("%d%c",f[0][i],i == fc -1 ? '\n' : ' ');
    printf("%d ",tc);
    for(int i = 0; i < tc; i++) printf("%d%c",f[2][i],i == tc -1 ? '\n' : ' ');
    

}
