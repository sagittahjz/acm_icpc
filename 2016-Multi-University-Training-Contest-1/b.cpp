#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
const int N = 1 << 20;
const int M = 20;
int sg[N], mex[M];
int t, n, m;
void getsg()
{
	memset(sg, -1, sizeof(sg));
	sg[0] = 0;
	for(int i = 1; i <= 20; ++i)
		sg[(1 << i) - 1] = 0;
	for(int i = 2; i < N; ++i)
		if(sg[i] == -1)
		{
			for(int j = 1; j < 20; ++j)
				if((i & (1 << j)) == (1 << j))
					for(int k = j - 1; k >= 0; --k)
						if((i & (1 << k)) == 0)
						{
							int i2 = i ^ (1 << j) ^ (1 << k);
							mex[sg[i2]] = i;
							break;
						}
			for(int j = 0; j < M; ++j)
				if(mex[j] != i)
				{
					sg[i] = j;
					break;
				}
		}
}
int main()
{
	getsg();
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		int ans = 0;
		while(n--)
		{
			scanf("%d", &m);
			int sum = 0, x;
			while(m--)
			{
				scanf("%d", &x);
				x = 20 - x;
				sum += (1 << x);
			}
			ans ^= sg[sum];
		}
		if(ans)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
