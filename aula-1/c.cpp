#include <cstdio>
#include <cctype>

char s[150];
int f[33];

int main() {
    int foo;
    scanf("%d",&foo);
    scanf(" %s",s);
    int cont = 0;
    for(int i = 0; s[i]; i++) {
        char c = tolower(s[i]);
        if(!f[c-'a']++) cont++;
    }
    if(cont == 26) puts("YES");
    else puts("NO");
}
