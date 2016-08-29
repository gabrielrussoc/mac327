#include <cstdio>
#include <climits>
#include <algorithm>
using namespace std;

int a[1234];
int n, l;

int main(){
    scanf("%d %d",&n,&l);
    for(int i = 0; i < n; i++) scanf("%d",a+i);
    sort(a,a+n);
    double ans = 0;
    for(int i = 0; i < n; i++) ans = max(ans, .5*(double(a[i+1])-double(a[i])));
    ans = max(ans,double(l-a[n-1]));
    ans = max(ans,double(a[0]));
    printf("%.20lf\n",ans);
}
