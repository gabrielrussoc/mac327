#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 112345;
const int K = 2123;
const int MOD = 1e9+7;

int n, m, t, reg, def;
int memo[K][K][3], visi[K][K][3];
char s[N];

int dp(int i, int o, bool f){
    if(o < 0 || o >= K) return 0;
    if(i == t){
       if(f) return !o; 
       return !(o-def) && !reg;
    }
    int &me = memo[i][o][f];
    if(visi[i][o][f]) return me;
    visi[i][o][f] = 1;
    if(!f && o-def >= 0) me = (me + dp(i,o-def+reg,true))%MOD;
    me = (me + dp(i+1, o+1, f))%MOD;
    me = (me + dp(i+1, o-1, f))%MOD;
    return me;
}

int main() {
    scanf("%d %d",&n,&m);
    scanf(" %s",s);
    t = n-m;
    for(int i = 0; s[i]; i++) {
        if(s[i] == '(') reg++;
        else {
            if(!reg) def++;
            else reg--;
        }
    }
    int ans;
    if(t == 0) ans = (!def && !reg);
    else ans = dp(0,0,false);
    printf("%d\n",ans);
}

