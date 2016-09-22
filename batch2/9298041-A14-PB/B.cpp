#include <bits/stdc++.h>
#define pb push_back
using namespace std;

typedef long long ll;

ll p[12][4];

ll sq(ll x){
    return x*x;
}

struct point {
    ll x,y,z;
    point () {}
    point (ll x, ll y, ll z) : x(x), y(y), z(z) {}
} pt[9];

ll dist (point a, point b) {
    return sq(a.x - b.x) + sq(a.y - b.y) + sq(a.z - b.z);  
}
int check() {
    map<ll, int> m;
    for(int i = 0; i < 8; i++)
        for(int j = i+1; j < 8; j++) {
            ll a = dist(pt[i], pt[j]);
            m[a]++;
            if(m.size() > 3) return 0;
        }
    if(m.size() != 3) return 0;
    ll s[4]; int i = 0;
    for(auto a : m) s[i++] = a.first;
    if(s[0]*2ll != s[1] && s[0]*3ll != s[2]) return 0;
    return m[s[0]] == 12 && m[s[1]] == 12 && m[s[2]] == 4;
}

void suc() {
    puts("YES");
    for(int i = 0; i < 8; i++) {
        point a = pt[i];
        printf("%lld %lld %lld\n",a.x,a.y,a.z);
    }
    exit(0);
}

int main() {
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 3; j++) {
            scanf("%lld", &p[i][j]);
        }
    }
    for(int i = 0; i < 8; i++) {
        ll x, y, z;
        x = p[i][0], y = p[i][1], z = p[i][2];
        pt[i] = point(x,y,z);
    }
    sort(p[0], p[0]+3);
    do {
        sort(p[1], p[1]+3);
        do {
            sort(p[2], p[2]+3);
            do {
                sort(p[3], p[3]+3);
                do {
                    sort(p[4], p[4]+3);
                    do {
                        sort(p[5], p[5]+3);
                        do {
                            sort(p[6], p[6]+3);
                            do {
                                sort(p[7], p[7]+3);
                                do {
                                    for(int i = 0; i < 8; i++) {
                                        ll x, y, z;
                                        x = p[i][0], y = p[i][1], z = p[i][2];
                                        pt[i] = point(x,y,z);
                                    }
                                    if(check()) suc();
                                } while (next_permutation(p[7], p[7]+3));
                            } while (next_permutation(p[6], p[6]+3));
                        } while (next_permutation(p[5], p[5]+3));
                    } while (next_permutation(p[4], p[4]+3));
                } while (next_permutation(p[3], p[3]+3));
            } while (next_permutation(p[2], p[2]+3));
        } while (next_permutation(p[1], p[1]+3));
    } while (next_permutation(p[0], p[0]+3));
    puts("NO");
}

