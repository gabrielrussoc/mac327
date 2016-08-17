#include <bits/stdc++.h>
using namespace std;

const int N = 2003;

char s[N];
char t[] = "yzx";
int p, q, n;

int main() {
    scanf("%d",&n);
    for(int i = 1; i <= n; i++){
        printf("%d : ",i);
        p = q = 0;
        if(i > 2) {
            for(int j = 0; j < min(i-2, n); j++)
                s[p++] = 'x';
            for(int j = i-2; j < n; j++) {
                s[p++] = t[q];
                q++;
                q %= 3;
            }
            s[p] = 0;
            puts(s);
        } else if (n == i) {
            for(int j = 0; j < n; j++) s[p++] = 'x';
            s[p] = 0;
            puts(s);
        } else puts("NO");
    }
}
