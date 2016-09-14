#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;

typedef long long ll;
const int N = 33;
const double EPS = 1e-9;

map<string, int> m;
int n;
double d[N][N];

int main() {
    int tc = 1;
    while(scanf("%d",&n) && n) {
        memset(d,0,sizeof d);
        m.clear();
        string s;
        for(int i = 0; i < n; i++) {
            cin >> s;
            m[s] = i;
        }
        int k;
        scanf("%d",&k);
        while(k--) {
            string s, t;
            double w;
            cin >> s >> w >> t;
            int u = m[s], v = m[t];
            d[u][v] = w;
        }
        for(int k = 0; k < n; k++)
            for(int i = 0; i < n; i++)
                for(int j = 0; j < n; j++)
                    d[i][j] = max(d[i][j], d[i][k] * d[k][j]);
        
        double maxi = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                maxi = max(maxi, d[i][j] * d[j][i]);

        if(maxi > 1 - EPS) printf("Case %d: Yes\n",tc++);
        else printf("Case %d: No\n",tc++);
    }
}

