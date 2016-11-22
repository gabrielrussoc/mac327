#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

int main() {
    int n, x;
    scanf ("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d",&x);
        if(x == 1) {
            puts("-1");
            return 0;
        }
    }
    puts("1");
}

