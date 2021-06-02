#include <cstdio>

using namespace std;

class DFS {
	int n, adj[10][10];
	public:
		void read_matrix();
		void dfs(int, int *);
		void reach();
		int connectivity();

};

void DFS::read_matrix() {
	int i, j;
	printf("Enter the number of nodes: ");
	scanf("%d", &n);

	printf("Enter the adjacency matrix:\n");
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			scanf("%d", &adj[i][j]);
}

void DFS::dfs(int u, int s[]) {
	int v;

	s[u] = 1;

	for (v = 0; v < n; v++)
		if (adj[u][v] == 1 && s[v] == 0)
			dfs(v, s);
}

void DFS::reach() {
	int i, source, s[10];

	for (i = 0; i < n; i++)
		s[i] = 0;

	printf("Enter the source node: ");
	scanf("%d", &source);

	dfs(source, s);

	for (i = 0; i < n; i++) {
		if (s[i] == 0)
			printf("Node %d is not reachable\n", i);
		else
			printf("Node %d is reachable\n", i);
	}
}

int DFS::connectivity() {
	int i, j, flag, s[10];

	for (j = 0; j < n; j++) {
		for (i = 0; i < n; i++)
			s[i] = 0;

		dfs(j, s);

		flag = 0;

		for (i = 0; i < n; i++)
			if (s[i] == 0)
				flag = 1;

		if (flag == 0)
			return 1;
	}

	return 0;
}

int main() {
	DFS d;

	d.read_matrix();
	d.reach();
	int flag = d.connectivity();

	if (flag == 1)
		printf("The graph is connected\n");
	else
		printf("The graph is not connected\n");

	return 0;
}
