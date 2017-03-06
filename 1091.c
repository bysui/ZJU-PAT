#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef struct Point{
	int x, y, z;
	Point(int a, int b, int c){
		x = a;
		y = b;
		z = c;
	}
}Point;

int brain[1286][128][60];
int m, n, l, t, sum;
int direction[][3] = {
	0, 0, 1,
	0, 1, 0,
	1, 0, 0,
	0, 0, -1,
	0, -1, 0,
	-1, 0, 0
};

void bfs(Point p)
{
	int i, x, y, z, cnt;

	queue<Point> list;
	list.push(p);
	brain[p.x][p.y][p.z] = 0;
	cnt = 0;
	while (!list.empty()){
		Point tmp = list.front();
		list.pop();
		cnt++;
		for (i = 0; i < 6; i++){
			x = tmp.x + direction[i][0];
			y = tmp.y + direction[i][1];
			z = tmp.z + direction[i][2];
			if (x < 0 || y < 0 || z < 0 || x >= m || y >= n || z >= l)
				continue;
			if (brain[x][y][z]){
				brain[x][y][z] = 0;
				list.push(Point(x, y, z));
			}
		}
	}
	if (cnt >= t)
		sum += cnt;
}

int main()
{
	int i, j, k;

	scanf("%d %d %d %d", &m, &n, &l, &t);
	for (i = 0; i < l; i++)
		for (j = 0; j < m; j++)
			for (k = 0; k < n; k++)
				scanf("%d", &brain[j][k][i]);

	for (i = 0; i < l; i++)
		for (j = 0; j < m; j++)
			for (k = 0; k < n; k++)
				if (brain[j][k][i])
					bfs(Point(j, k, i));
	printf("%d\n", sum);
	return 0;
}