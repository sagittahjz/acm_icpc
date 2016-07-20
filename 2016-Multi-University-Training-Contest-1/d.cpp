#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <map>
using namespace std;
const int N = 1e5 + 10;
int a[17][N], p[N];
map<int, long long> ans2;
int t, n, q;
int rmq(int L, int R)
{
	int i = p[R - L + 1];
	return __gcd(a[i][L], a[i][R - (1 << i) + 1]);
}
int main()
{
	p[0] = -1;
	for(int i = 1; i <= 100000; ++i)
		p[i] = (i == (i & -i) ? p[i - 1] + 1 : p[i - 1]);
	scanf("%d", &t);
	for(int ca = 1; ca <= t; ++ca)
	{
		printf("Case #%d:\n", ca);
		scanf("%d", &n);
		int lim = p[n];
		for(int i = 1; i <= n; ++i)
			scanf("%d", &a[0][i]);
		for(int i = 1; i <= lim; ++i)
			for(int j = 1; j + (1 << i) - 1 <= n; ++j)
				a[i][j] = __gcd(a[i - 1][j], a[i - 1][j + (1 << (i - 1))]);
		ans2.clear();
		for(int i = 1; i <= n; ++i)
		{
			for(int j = i, L, R, mid; j <= n; j = L + 1)
			{
				int tans = rmq(i, j);
				L = j;
				R = n;
				while(L != R)
				{
					mid = (L + R + 1) >> 1;
					if(tans == rmq(i, mid))
						L = mid;
					else
						R = mid - 1;
				}
				ans2[tans] += L - j + 1;
			}	
		}
		scanf("%d", &q);
		int ll, rr, ans1;
		while(q--)
		{
			scanf("%d%d", &ll, &rr);
			ans1 = rmq(ll, rr);
			printf("%d %lld\n", ans1, ans2[ans1]);
		}
	}
	return 0;
}
