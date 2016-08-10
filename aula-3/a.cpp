#include <bits/stdc++.h>
using namespace std;

int mdc (int a, int b) {
    return b ? mdc(b,a%b) : a;
}

int main() {
    int t;
    scanf("%d",&t);
    while(t--) {
        int x1,y1,x2,y2;
        scanf("%d %d",&x1,&y1);
        scanf("%d %d",&x2,&y2);
        int dx = abs(x2-x1);
        int dy = abs(y2-y1);
        if(min(dx,dy) == 0) printf("%d\n",1+max(dx,dy));
        else printf("%d\n",1 + mdc(dx,dy));
    }  
}
