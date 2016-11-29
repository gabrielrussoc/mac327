#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;

const int N = 123;
int a[N], n;

int get() {
    int maxi = -1, bi;
    for(int i = 0; i < n; i++) {
        if(a[i] >= maxi) {
            maxi = a[i];
            bi = i;
        }
    }
    return bi;
}

int main() {
    scanf("%d",&n);
    for(int i = 0; i < n; i++) scanf("%d",a+i);
    int ans = 0;
    while (true) {
        int j = get();
        if(j == 0) break;
        a[j]--;
        a[0]++;
        ans++; 
    }
    printf("%d\n",ans);
}

