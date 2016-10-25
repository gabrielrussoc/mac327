#include <bits/stdc++.h>
#define pb push_back
using namespace std;

typedef long long ll;
const int N = 2123;

int memo[N][N], visi[N][N], n, turn;
char s[N];
int inf = N;

int dp(int i, int o){
    if(o < 0) return inf;
    if(i == n) return !o ? 0 : inf;
    int &me = memo[i][o];
    if(visi[i][o] == turn) return me;
    visi[i][o] = turn;
    int c = (s[i] == '}');
    return me = min(c+dp(i+1,o+1), !c + dp(i+1,o-1));
}

int main() {
    int tc = 1;
    while(scanf(" %s", s) && s[0] != '-') {
        turn++;
        n = strlen(s);
        printf("%d. %d\n",tc++, dp(0,0));
    }
}

