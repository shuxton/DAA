#include <cstdio>

class krus {
	int c[10][10];

	public:

	int n, m;
	void read_data();
	int find(int, int []);
	void union_ij(int, int, int []);
	void kruskal();
};

void krus::read_data() {
	int i, j, u, v;

	printf("Enter the number of nodes: ");
	scanf("%d", &n);

	printf("Enter the number of edges: ");
	scanf("%d", &m);

	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			c[i][j] = 999;

	for (i = 0; i < m; i++) {
		printf("Enter the edges and its cost: ");
		scanf("%d%d", &u, &v);
		scanf("%d", &c[u][v]);
		c[v][u] = c[u][v];
	}
}

int krus::find(int v, int p[]) {
	while (p[v] != v)
		v = p[v];

	return v;
}

void krus::union_ij(int i, int j, int p[]) {
		if (i < j)
			p[j] = i;
		else
			p[i] = j;
}

void krus::kruskal() {
	int count, i, p[10], mini, j, u, v, k, t[10][2], sum;
	count = 0;
	k = 0;
	sum = 0;
	for (i = 0; i < n; i++)
		p[i] = i;

	while (count < n) {
		mini = 999;
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				if (c[i][j] < mini) {
					mini = c[i][j];
					u = i;
					v = j;
				}

		if (mini == 999)
			break;

		i = find(u, p);
		j = find(v, p);

		if (i != j) {
			t[k][0] = u;
			t[k][1] = v;

			k++;

			count++;
			sum += mini;

			union_ij(i, j, p);
		}

		c[u][v] = c[v][u] = 999;
	}

	if (count == (n-1)) {
		printf("Cost of spanning tree = %d\n", sum);
		printf("Spanning tree is shown below\n");
		for (k = 0; k < n; k++)
			printf("%d %d\n", t[k][0], t[k][1]);
	}
	else
		printf("Spanning tree does not exist\n");
}

int main() {
	krus k;
	k.read_data();
	k.kruskal();
	return 0;
}
