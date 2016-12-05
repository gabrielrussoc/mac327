#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int, string> pis;

map<string, int> m;
set<pis> s;
string aux;
int n;

int main() {
    scanf("%d",&n);
    for(int i = 0; i < n; i++) {
        cin >> aux;
        m[aux] = i;
    }
    for(auto x : m) 
        s.insert(pis(-x.second, x.first)); 
    for(auto x : s)
        cout << x.second << endl;
}

