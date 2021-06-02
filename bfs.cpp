#include <cstdio>

using namespace std;

class BFS {
	int n, adj[10][10], s[10], source;
	public:
		void bfs();
		void read_matrix();
		void print_data();
};

void BFS::read_matrix() {
	int i, j;
	printf("Enter the number of nodes: ");
	scanf("%d", &n);

	printf("Enter the adjacency matrix:\n");
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			scanf("%d", &adj[i][j]);

	printf("Enter source: ");
	scanf("%d", &source);
}

void BFS::print_data() {
	for (int i = 0; i < n; i++) {
		if (s[i] == 0)
			printf("Vertex %d is not reachable\n", i);
		else
			printf("Vertex %d is reachable\n", i);
	}
}

void BFS::bfs() {
	int i, u, v, f, r, q[10];
	for (i = 0; i < n; i++)
		s[i] = 0;

	f = r = 0;

	q[r] = source;

	s[source] = 1;

	while (f <= r) {
		u = q[f++];

		for (v = 0; v < n; v++)
			if (adj[u][v] == 1 && s[v] == 0) {
				s[v] = 1;
				q[++r] = v;
			}
	}
}

int main() {
	BFS b;

	b.read_matrix();
	b.bfs();
	b.print_data();

	return 0;
}
