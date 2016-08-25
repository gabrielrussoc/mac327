#include <bits/stdc++.h>
#define pb push_back
using namespace std;

typedef long long ll;

char d[1007][22], s[99], enc[256], use[256];
int k, start[22], n, len[105], g[1005];

bool comp(int i, int j) {
    return strcmp(d[i],d[j]) < 0;
}

bool bt(int j) {
    if(j == k) {
        for(int i = 0; s[i]; i++) printf("%c",s[i] == ' ' ? ' ' : enc[s[i]]);
        return true;
    }
    if(s[j] == ' ') return bt(j+1);
    for(int i = start[len[j]]; i < n && strlen(d[g[i]]) == len[j]; i++) {
        bool go = true;
        for(int p = 0; p < len[j] && go; p++) {
            if(enc[s[j+p]] && enc[s[j+p]] != d[g[i]][p]) go = false;
            if(!enc[s[j+p]] && use[d[g[i]][p]]) go = false;
        }
        if(go) {
            int v[22];
            int cont = 0;
            for(int p = 0; p < len[j]; p++){
                if(!enc[s[j+p]]) v[cont++] = p;
                enc[s[j+p]] = d[g[i]][p];
                use[d[g[i]][p]] = s[j+p];
            }
            if(bt(j+len[j])) return true;
            for(int p = 0; p < cont; p++) { enc[s[j+v[p]]] = 0; use[d[g[i]][v[p]]] = 0; }
        }
    }
    return false;
}

int main() {
    scanf("%d",&n);
    for(int i = 0; i < n; i++) { scanf(" %s",d[i]); g[i] = i; }
    sort(g,g+n, comp);
    for(int i = n-1; i >= 0; i--) start[strlen(d[g[i]])] = i;

    while (scanf(" %[^\n]",s) != EOF) {
        k = strlen(s);
        memset(use, 0, sizeof use);
        memset(enc, 0, sizeof enc);
        int j = 0;
        for(int i = 0; i < k; i++) {
            if(s[i] == ' ') { len[i-j] = j; j = 0; }
            else j++;
        }
        len[k-j] = j;
        if(!bt(0)) for(int i = 0; s[i]; i++) printf("%c",s[i] == ' ' ? ' ' : '*');
        putchar('\n');
    }
}

