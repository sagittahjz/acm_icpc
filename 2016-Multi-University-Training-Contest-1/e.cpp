#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int N = 10;
int p[N], mp[N][N];
int firste[N], nexte[N * N], v[N * N];
bool used[N];
int ma[N];
int n, m, e, ans;
void build(int x, int y)
{
	nexte[++e] = firste[x];
	firste[x] = e;
	v[e] = y;
}
bool dfs(int u)
{
	for(int p = firste[u]; p; p = nexte[p])
		if(!used[v[p]])
		{
			used[v[p]] = 1;
			if(!ma[v[p]] || dfs(ma[v[p]]))
			{
				ma[v[p]] = u;
				return 1;
			}
		}
	return 0;
}
int hungary()
{
	int re = 0;
	memset(ma, 0, sizeof ma);
	for(int i = 1; i <= n; ++i)
	{
		memset(used, 0, sizeof used);
		if(dfs(i))
			++re;
	}
	return re;
}
int main()
{
	while(scanf("%d%d", &n, &m) != EOF)
	{
		if(!n)
		{
			puts("0");
			continue;
		}
		for(int i = 1; i <= n; ++i)
			p[i] = i;
		memset(mp, 0, sizeof mp);
		int x, y;
		for(int i = 1; i <= m; ++i)
		{
			scanf("%d%d", &x, &y);
			mp[x][y] = 1;
		}
		ans = n;
		do{
			e = 0;
			memset(firste, 0, sizeof firste);
			for(int i = 1; i <= n; ++i)
			{
				for(int j = 1; j <= n; ++j)
					if(!mp[i][p[j]] && !mp[i][p[j % n + 1]])
						build(i, j);
				ans = min(ans, n - hungary());
			}
			if(n == 1)
				break;
		}while(next_permutation(p + 1, p + n));
		printf("%d\n", ans);
	}
	return 0;
}
