#include <stdio.h>
#include <iostream>
using namespace std;
typedef long long ll;
const int repeat = 50;

ll mul(ll a, ll b, ll m)
//求a*b%m
{
    ll ans = 0;
    a %= m;
    while (b)
    {
        if (b & 1) 
            ans = (ans + a) % m;
        b /= 2;
        a = (a + a) % m;
    }
    return ans;
}

ll pow(ll a, ll b, ll m)
//a^b % m
{
    ll ans = 1;
    a %= m;
    while (b)
    {
        if (b & 1)
            ans = mul(a, ans, m);
        b /= 2;
        a = mul(a, a, m);
    }
    ans %= m;
    return ans;
}

bool MillerRabin(ll n)//n是测试的大数，repeat是测试重复次数
{
    if (n == 2 || n == 3)return true;
	if (!(n & 1))return false;
    ll d = n - 1;//将n-1分解成2^s*d
    int s = 0;
    while (!(d & 1)) ++s, d >>= 1;
    for (int i = 0; i < repeat; i++)//重复repeat次
    {
        ll a = rand() % (n - 3) + 2;//取一个随机数,[2,n-1)
        ll x = pow(a, d, n),y = 0;
        for (int j = 0; j < s; j++)
        {
            y = mul(x, x, n);
            if (y == 1 && x != 1 && x != (n - 1))return false;
            x = y;
        }
		if (y != 1)return false;//费马小定理
    }
    return true;
}

int main()
{
    ll n;
    cin >> n;
    if (MillerRabin(n))
        cout << "Prime" << endl;
    else
        cout << "Composite" << endl;
}
