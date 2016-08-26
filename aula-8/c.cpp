#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

int v[20];
int ans[55], zero, n;

char f(int k) {
    if(k == 0) return 'U';
    if(k == 1) return 'R';
    if(k == 2) return 'D';
    return 'L';
}

bool done() {
    if(v[15]) return false;
    for(int i = 0; i < 15; i++) if(v[i] != i+1) return false;
    return true;
}

int dist(int f, int t) {
    return abs(f/4 - t/4) + abs(f%4 - t%4);
}

int taxi() {
    int ret = 0;
    for(int i = 0; i < 16; i++) ret += dist(i,(v[i]+15)%16);
    return ret;
}

// 0  1  2  3
// 4  5  6  7
// 8  9 10 11
//12 13 14 15
bool can(int k, int last){
    if(k == (last+2)%4) return false;
    if(k == 0) return zero > 3;
    if(k == 1) return zero%4 != 3;
    if(k == 2) return zero < 12;
    return zero%4 != 0;
}

void upd(int k, int s) {
    if(k == 0) { swap(v[zero], v[zero-4*s]); zero -= 4*s; }
    else if(k == 1) { swap(v[zero], v[zero+s]); zero += s; }
    else if(k == 2) { swap(v[zero], v[zero+4*s]); zero += 4*s; }
    else { swap(v[zero],v[zero-s]); zero -= s; }
}

bool bt (int q, int last) {
    if(taxi() + q > 50) return false;
    if(done()) {
        for(int i = 0; i < q; i++) printf("%c",f(ans[i]));
        putchar('\n');
        return true;
    }
    for(int i = 0; i < 4; i++) {
        if(can(i, last)) {
            upd(i,1);
            ans[q] = i;
            if(bt(q+1, i)) return true;
            upd(i,-1);
        }
    }
    return false;
}

bool solvable() {
    int inv = 0;
    for(int i = 0; i < 16; i++)
        for(int j = i+1; j < 16; j++)
            if(v[i] && v[j] && v[i] > v[j]) inv++;
    int p = (zero/4)&1;
    if(p) return !(inv&1);
    else return inv&1;
}

int main() {
    scanf("%d",&n);
    while(n--) {
        for(int i = 0; i < 16; i++) { scanf("%d",v+i); if(v[i] == 0) zero = i; }
        if(!solvable() || !bt(0,-3)) puts ("This puzzle is not solvable.");
    }

}

