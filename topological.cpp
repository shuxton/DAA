#include <cstdio>

using namespace std;

class topo {
	int n, a[10][10], indegree[10];
	public:
		void read_data();
		void find_indegree();
		void topological_sort();
};

void topo::read_data() {
	int i, j;
	printf("Enter the number of nodes: ");
	scanf("%d", &n);

	printf("Enter the adjacency matrix:\n");
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			scanf("%d", &a[i][j]);
}

void topo::find_indegree() {
	for (int j = 0; j < n; j++) {
		int sum = 0;
		for (int i = 0; i < n; i++)
			sum += a[i][j];

		indegree[j] = sum;
	}
}

void topo::topological_sort() {
	int u, v, t[10], s[10];
	find_indegree();

	int top = -1;
	int k = 0;

	for (int i = 0; i < n; i++)
		if (indegree[i] == 0)
			s[++top] = i;

	while (top != -1) {
		u = s[top--];
		t[k++] = u;

		for (v = 0; v < n; v++)
			if (a[u][v] == 1) {
				indegree[v]--;

				if (indegree[v] == 0)
					s[++top] = v;
			}
	}

	printf("The topological ordering sequence is: ");

	for (int i = 0; i < n; i++)
		printf("%d ", t[i]);

	printf("\n");
}

int main() {
	topo t;

	t.read_data();
	t.topological_sort();

	return 0;
}
