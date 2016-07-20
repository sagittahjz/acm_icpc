# 2016 Multi-University Training Contest 1

## [1001](http://acm.hdu.edu.cn/showproblem.php?pid=5723)

###题意

给出$n$个点$m$条边 求一个颗最小生成树以及树上任意不同的两点间距离期望

###题解

第一问

最小生成树 可用 $kruskal$ 复杂度 $O(nlogm)$

第二问 

树形$DP$ 求出在所有情况下每条边经过总次数(算每条边的贡献)

然后再除以方案数得到期望 复杂度 $O(n)$
