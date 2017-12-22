###### 广度优先搜索(BFS)
```python
def BFS(G, s):
	for vertex v in G.V-{s}
		v.stat = "found"
		v.distance = ∞
		v.parent = None
	s.stat = "visited"
	s.distance = 0
	s.parent = None
	Q = Queue()
	Q.push(s)
	while !Q.empty():
		v = Q.front()
		Q.pop()
		for u in G.adj(v)
			if u.stat = "init":
				u.stat = "found"
				u.distance = v.distance + 1
				u.parent = v
				q.push(u)
		u.stat = "visited"
```
广度优先搜索能找到最优路径，但是却很耗时。
广度优先搜索之所以能找到最优的路径，原因就是每一次扩展的点，都是距离出发点最近、步骤最少的。如此这样递推，当扩展到目标点的时候，也是距离出发点最近的。
这样的路径自然形成了最短的路线。正是由于广度优先搜索一层层的扩展，虽然让他找到了最优的路线，但是，他却很傻的走完了绝大多数格子，才找到我们的目标点。
也就是，他只关注了当前扩展点和出发点的关系，而忽略了当前点和目标点的距离。

##### A*算法

集合Seen：记录已经探测（已知G值和H值）的节点
集合Pass：记录已访问的节点
Map< Pos, From>：记录在“最小路”上的边

###### 1 初始化
将开始节点begin放入Seen，begin的G值和H值都视为0。
###### 2 寻路
1. 在Seen中寻找F值最小的节点position，访问pos。
2. 从Seen中删除position，并将怕position添加到Pass。
3. 探测position的邻接节点v，
若v是终点，循环结束，进入步骤3“回溯”。
若v在Pass中，继续访问下一个v。
若v不在Seen中，计算v的G值和H值，将v的前置节点记为position(Map[v]=position)。
若v在Seen中，计算G'和H'，若G'+H'小于G+H，更新G值和H值，修改Map(Map[v]=position)。
##### 3 回溯
根据Map从终点回溯到起点
