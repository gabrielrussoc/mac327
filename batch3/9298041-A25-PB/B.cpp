#include <bits/stdc++.h>
#define pb push_back
using namespace std;

typedef long long ll;

const int N = 1123456;
char s[N];
int p[N], k, j;

int main() {
    scanf(" %s",s);
    int ans = 0;
    for(int i = 0; s[i]; i++) if(s[i] == ')') p[k++] = i;
    for(int i = 0; s[i]; i++){
        while(p[j] < i) j++;
        if(s[i] == '(') {
            if(j < k) {
                int w = p[j];
                if(w > i) {
                    ans += 2;
                    j++;
                } 
            }
        }
    }
    printf("%d\n",ans);
}

