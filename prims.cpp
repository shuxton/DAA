#include <cstdio>

class prims {
	int n, a[10][10];

	public:

	void read_data();
	void mini();
};

void prims::read_data() {
	int i, j;

	printf("Enter the number of nodes: ");
	scanf("%d", &n);

	printf("Enter the adjacency matrix:\n0-self loop\n999-no loop\n");
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			scanf("%d", &a[i][j]);
}

void prims::mini() {
	int i, j, k, u, v, mini, sum, source, t[10][2], p[10], d[10], s[10];

	mini = 999;
	source = 0;

	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			if (a[i][j] != 0 && a[i][j] <= mini) {
				mini = a[i][j];
				source = i;
			}

	for (i = 0; i < n; i++) {
		d[i] = a[source][i];
		s[i] = 0;
		p[i] = source;
	}

	s[source] = 1;
	sum = k = 0;

	for (i = 1; i < n; i++) {
		mini = 999;
		u = -1;

		for (j = 0; j < n; j++)
			if (s[j] == 0 && d[j] <= mini) {
				mini = d[j];
				u = j;
			}

		t[k][0] = u;
		t[k][1] = p[u];

		k++;

		sum += a[u][p[u]];
		s[u] = 1;

		for (v = 0; v < n; v++)
			if (s[v] == 0 && a[u][v] < d[v]) {
				d[v] = a[u][v];
				p[v] = u;
			}
	}

	if (sum >= 999)
		printf("Spanning tree does not exist\n");
	else {
		printf("Spanning tree exists and minimum spanning tree is\n");
		for (i = 0; i < (n-1); i++)
			printf("%d %d\n", t[i][0], t[i][1]);
		printf("The cost of the spanning tree = %d\n", sum);
	}
}

int main() {
	prims p;
	p.read_data();
	p.mini();
}
