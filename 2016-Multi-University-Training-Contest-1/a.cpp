#pragma comment(linker, "/STACK:102400000,102400000")
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int N = 100010, M = 1000010;
struct edge
{
	int x, y, z;
}a[M];
int firste[N], nexte[N << 1], v[N << 1], w[N << 1];
int sz[N], fa[N];
int t, n, m, e;
long long ans1;
bool cmp(const edge &aa, const edge &bb)
{
	return aa. z < bb.z;
}
int findf(int x)
{
	if(fa[x] != x)
		fa[x] = findf(fa[x]);
	return fa[x];
}
void build(int x, int y, int z)
{
	nexte[++e] = firste[x];
	firste[x] = e;
	v[e] = y;
	w[e] = z;
}
void dfs(int u)
{
	sz[u] = 1;
	for(int p = firste[u]; p; p = nexte[p])
		if(v[p] != fa[u])
		{
			fa[v[p]] = u;
			dfs(v[p]);
			sz[u] += sz[v[p]];
		}
}
int main()
{
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d%d", &n, &m);
		for(int i = 1; i <= m; ++i)
			scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].z);
		sort(a + 1, a + 1 + m, cmp);
		ans1 = 0;
		for(int i = 1; i <= n; ++i)
			fa[i] = i;
		e = 1;
		memset(firste, 0, sizeof firste);
		for(int i = 1; i <= m; ++i)
			if(findf(a[i].x) != findf(a[i].y))
			{
				ans1 += a[i].z;
				build(a[i].x, a[i].y, a[i].z);
				build(a[i].y, a[i].x, a[i].z);
				fa[findf(a[i].x)] = findf(a[i].y);
			}
		printf("%lld ", ans1);
		memset(fa, 0, sizeof fa);
		fa[1] = 1;
		dfs(1);
		double ans2 = 0;
		for(int p = 2; p < e; p += 2)
		{
			int u1 = v[p], u2 = v[p ^ 1];
			if(sz[u1] > sz[u2])
				swap(u1, u2);
			ans2 += (double)w[p] * sz[u1] * (n - sz[u1]);
		}
		ans2 /= (long long)n * (n - 1) / 2;
		printf("%.2f\n", ans2);
	}
	return 0;
}
