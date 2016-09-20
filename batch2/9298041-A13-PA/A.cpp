#include <bits/stdc++.h>
#define pb push_back
using namespace std;

typedef long long ll;
int n;
char s[205];

bool solve(int l, int r) {
    int i = 0, j = 0;
    for(int k = l; k <= r; k++) {
        if(s[k] == 'U') i++;
        else if(s[k] == 'D') i--;
        else if(s[k] == 'L') j++;
        else j--;
    }
    return i == 0 && j == 0;
}

int main() {
    scanf("%d",&n);
    scanf(" %s", s);
    int ans = 0;
    for(int i = 0; i < n; i++)
        for(int j = i; j < n; j++)
            if(solve(i,j)) ans++;
    printf("%d\n",ans);
}

