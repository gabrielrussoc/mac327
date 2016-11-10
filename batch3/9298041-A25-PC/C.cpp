#include <bits/stdc++.h>
#define pb push_back
using namespace std;

typedef long long ll;

const int N = 1123456;
char s[N];
int v[N];

void fail(){
    puts("Impossible");
    exit(0);
}

int get(int i) {
    char c = s[i];
    if(c == '(' || c == ')') return 0;
    if(c == '{' || c == '}') return 1;
    if(c == '<' || c == '>') return 2;
    return 3;
}

int main() {
    scanf(" %s",s);
    int o = 0;
    for(int i = 0; s[i]; i++){
        if(s[i] == '(' || s[i] == '[' || s[i] == '<' || s[i] == '{') o++;
        else o--;
        if(o < 0) fail();
    }
    if(o) fail();
    int ans = 0;
    int k = 0;
    for(int i = 0; s[i]; i++) {
        if(s[i] == '(' || s[i] == '[' || s[i] == '<' || s[i] == '{') v[k++] = i;
        else {
            if(get(i) != get(v[k-1])) ans++;
            k--;
        }
    }
    printf("%d\n",ans);

}

