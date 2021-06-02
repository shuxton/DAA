#include <cstdio>
#include <chrono>
#include <stdlib.h>

using namespace std::chrono;

class quick {
	int temp, high, low;

	public:

	int partition(int *, int, int);
	void qsort(int *, int, int);
};

int quick::partition(int a[], int low, int high) {
	int i, j, key;
	i = low+1;
	j = high;
	key = a[low];

	while (1) {
		while (i < high && a[i] <= key)
			i++;

		while (j >= low && a[j] > key)
			j--;

		if (i < j) {
			temp = a[i];
			a[i] = a[j];
			a[j] = temp;
		}
		else {
			temp = a[low];
			a[low] = a[j];
			a[j] = temp;
			return j;
		}
	}
}

void quick::qsort(int a[], int low, int high) {
	if (low < high) {
		int j = partition(a, low, high);
		qsort(a, low, j-1);
		qsort(a, j+1, high);
	}
}

int main() {
	int *a, n, i;
	quick q;

	printf("Enter the number of elements: ");
	scanf("%d", &n);

	a = new int[n];

	printf("Generating %d random elements\n", n);
	for (i = 0; i < n; i++)
		a[i] = (rand()%(2*n))+1;

	auto start = high_resolution_clock::now();

	q.qsort(a, 0, n-1);

	auto stop = high_resolution_clock::now();

	auto duration = duration_cast<microseconds> (stop-start);

	printf("Sorted elements: ");
	for (i = 0; i < n; i++)
		printf("%d ", a[i]);

	printf("\n\n");

	printf("Time taken = %lld microseconds\n", duration.count());

	printf("Space consumed: %d bytes\n", sizeof(n)+(n*sizeof(a))+sizeof(i)+sizeof(q));

	return 0;
}
