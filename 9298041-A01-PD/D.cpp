#include <cstdio>
#include <iostream>
#include <set>
#include <climits>
using namespace std;
typedef long long ll;

int n, k;
set<int> s;

int main() {
    scanf("%d",&n);
    ll cont = 0;
    ll z = 0;
    while(cont <= INT_MAX) {
        s.insert(cont+1);
        cont += z++;
    }
    while(n--) {
        scanf("%d",&k);
        cout << s.count(k) << " ";
    }
    putchar('\n');
}
