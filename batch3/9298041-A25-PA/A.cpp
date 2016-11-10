#include <bits/stdc++.h>
#define pb push_back
using namespace std;

typedef long long ll;
char s[999];
int n, t;
int v[999];

bool match(char a, char b) {
    if(a == '(' || a == '[') return true;
    if(b == '(') return a == ')';
    return a == ']';
}

int main() {
    scanf("%d",&t);
    getchar();
    while(t--) {
        if(!scanf("%[^\n]",s)) s[0] = 0;
        int p, c, k = 0;
        char l;
        p = c = l = 0;
        bool f = true;
        for(int i = 0; s[i] && f; i++) {
            if(s[i] == '(') p++, v[k++] = i;
            else if(s[i] == ')'){
                if(k && !match(s[i], s[v[k-1]])) f = false; 
                p--, k--;
            }
            else if(s[i] == '[') c++, v[k++] = i;
            else {
                if(k && !match(s[i], s[v[k-1]])) f = false; 
                c--, k--;
            }
            if(c < 0 || p < 0) f = false;
        }
        if(f && !c && !p) puts("Yes");
        else puts("No");
        getchar();
    }
}

