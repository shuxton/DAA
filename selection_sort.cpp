#include <cstdio>
#include <chrono>
#include <stdlib.h>

using namespace std::chrono;

class selection {
	int pos, temp;

	public:

	void sel(int , int *);
};

void selection::sel(int n, int a[]) {
	int i, j;
	for (i = 0; i < n; i++) {
		pos = i;
		for (j = i+1; j < n; j++)
			if (a[j] < a[pos])
				pos = j;

		temp = a[i];
		a[i] = a[pos];
		a[pos] = temp;
	}
}

int main() {
	int *a, i, n;
	selection s;

	printf("Enter the number of elements: ");
	scanf("%d", &n);

	a = new int[n];

	printf("Generating %d random elements\n", n);
	for (i = 0; i < n; i++)
		a[i] = (rand()%(2*n))+1;

	auto start = high_resolution_clock::now();
	s.sel(n, a);
	auto stop = high_resolution_clock::now();

	auto duration = duration_cast<microseconds> (stop-start);

	printf("Sorted elements: ");

	for (i = 0; i < n; i++)
		printf("%d ", a[i]);

	printf("\n\n");

	printf("Time taken = %lld microseconds\n", duration.count());
	printf("Memory consumed = %d bytes\n", sizeof(n)+(n*sizeof(a))+sizeof(i)+sizeof(s));

	return 0;
}
