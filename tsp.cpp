#include <cstdio>

using namespace std;

class tsp {
	int n, a[10][10], v[10];

	public:

	int cost;
	void read_matrix();
	int least(int);
	void mincost(int);

	tsp() {
		cost = 0;
	}
};

void tsp::read_matrix() {
	int i, j;
	printf("Enter the number of cities: ");
	scanf("%d", &n);

	printf("Enter the cost matrix:\n");
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			scanf("%d", &a[i][j]);

		v[i] = 0;
	}
}

int tsp::least(int c) {
	int i, nc = 999, min = 999;

	for (i = 0; i < n; i++) {
		if (a[c][i] != 0 && v[i] == 0)
			if (a[c][i] <= min) {
				min = a[c][i];
				nc = i;
			}
	}

	if (min != 999)
		cost += min;
	return nc;
}

void tsp::mincost(int city) {
	int i, ncity;
	v[city] = 1;

	printf("%d ", city);
	ncity = least(city);

	if (ncity == 999) {
		ncity = 0;
		printf("%d ", ncity);
		cost += a[city][ncity];
		return ;
	}

	mincost(ncity);
}

int main() {
	int i, j, source;
	tsp t;

	t.read_matrix();
	printf("Enter the source city: ");
	scanf("%d", &source);

	printf("Sequences of city visited: ");
	t.mincost(source);

	printf("\nThe maximum cost is %d\n", t.cost);

	return 0;
}
