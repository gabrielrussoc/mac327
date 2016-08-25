#include <bits/stdc++.h>
#define pb push_back
using namespace std;

typedef long long ll;

int n;
int m[12][12], empty[12][12];

void next (int i, int j, int &ni, int &nj) {
    if(j == n*n-1) {
        ni = i+1;
        nj = 0;    
    } else { ni = i; nj = j+1; }
}

bool can(int i, int j, int x) {
    for(int k = 0; k < n*n; k++) if(m[i][k] == x || m[k][j] == x) return false;
    int p = i/n; p *= n;
    int q = j/n; q *= n;
    for(int r = 0; r < n; r++)
        for(int c = 0; c < n; c++)
            if(m[p+r][q+c] == x) return false;
    return true;
}

void show() {
    for(int i = 0; i < n*n; i++)
        for(int j = 0; j < n*n; j++)
            printf("%d%c",m[i][j]," \n"[j==n*n-1]);
}

bool bt(int i, int j) {
    if(i == n*n) return true;
    int ni, nj;
    next(i,j,ni,nj);
    if(!empty[i][j]) return bt(ni,nj);
    for(int x = 1; x < 10; x++) {
        if(can(i,j,x)) {
            m[i][j] = x;
            if(bt(ni,nj)) return true;
            m[i][j] = 0;
        }
    }
    return false;
}

int main() {
    bool blank = false;
    while(scanf("%d",&n) != EOF) {
        if(blank) putchar('\n');
        blank = true;
        for(int i = 0; i < n*n; i++)
            for(int j = 0; j < n*n; j++) {
                scanf(" %d",&m[i][j]);
                empty[i][j] = !m[i][j];
            }
        if(bt(0,0)) show();
        else puts("NO SOLUTION");
    }

}

