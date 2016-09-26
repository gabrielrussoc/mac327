#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
typedef complex<double> num;

char ans[][33] = {"x^y^z", "x^z^y", "(x^y)^z", "(x^z)^y", "y^x^z", "y^z^x",
   "(y^x)^z", "(y^z)^x", "z^x^y", "z^y^x", "(z^x)^y", "(z^y)^x"};  
int i;
double xin, yin, zin;
num x,y,z,res;
const double eps = 1e-9;

num eval(num a, num b, num c, int t) {
    //a^b^c
    if(t == 0) return c * log(b) + log(log(a));
    //(a^b)^c
    return log(b) + log(c) + log(log(a));
}

bool operator > (const num &x, const num &y) {
    if (imag(x) == 0 && imag(y) == 0) 
        return real(x) > real(y);
    else if (imag(x) != 0 && imag(y) == 0) 
        return 0;
    else if (imag(x) == 0 && imag(y) != 0) 
        return 1;
    return real(x) < real(y);
}

int main() {
    scanf("%lf %lf %lf",&xin,&yin,&zin);
    x = num(xin,0);
    y = num(yin,0);
    z = num(zin,0);
    num tmp;
    res = eval(x,y,z,0);
    i = 0;
    if((tmp = eval(x,z,y,0)) > res) { res = tmp; i = 1; }
    if((tmp = eval(x,y,z,1)) > res) { res = tmp; i = 2; }
    if((tmp = eval(x,z,y,1)) > res) { res = tmp; i = 3; }
    if((tmp = eval(y,x,z,0)) > res) { res = tmp; i = 4; }
    if((tmp = eval(y,z,x,0)) > res) { res = tmp; i = 5; }
    if((tmp = eval(y,x,z,1)) > res) { res = tmp; i = 6; }
    if((tmp = eval(y,z,x,1)) > res) { res = tmp; i = 7; }
    if((tmp = eval(z,x,y,0)) > res) { res = tmp; i = 8; }
    if((tmp = eval(z,y,x,0)) > res) { res = tmp; i = 9; }
    if((tmp = eval(z,x,y,1)) > res) { res = tmp; i = 10; }
    if((tmp = eval(z,y,x,1)) > res) { res = tmp; i = 11; }
    printf("%s\n",ans[i]);
}

