#include <bits/stdc++.h>
#define pb push_back
using namespace std;

typedef long long ll;

string a[44];
char b[44];
char ss[4];
set<string> s;
int n, q, ans;

void go(int k, string t) {
    if(k == n) s.insert(t);
    else {
        for(int i = 0; i < q; i++) {
            if(b[i] == t[0]){
                string loc = t;
                loc[0] = a[i][1];
                go(k+1, a[i][0] + loc); 
            }
        }
    }
}

int main() {
    scanf("%d %d",&n,&q);
    for(int i = 0; i < q; i++) {
        scanf(" %s %c",ss,b+i);
        a[i] = ss;
    }
    go(1, "a");
    printf("%d\n",s.size());
}

