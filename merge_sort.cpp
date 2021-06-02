#include <cstdio>
#include <chrono>
#include <stdlib.h>

using namespace std::chrono;

int c[10000000];

class merge {
	int low, high;

	public:

	void m_sort(int *, int, int);
	void s_merge(int *, int, int, int);
};

void merge::m_sort(int a[], int low, int high) {
	if (low < high) {
		int mid = (low+high)/2;
		m_sort(a, low, mid);
		m_sort(a, mid+1, high);
		s_merge(a, low, mid, high);
	}
}

void merge::s_merge(int a[], int low, int mid, int high) {
	int i = low;
	int j = mid+1;
	int k = low;

	while (i <= mid && j <= high) {
		if (a[i] < a[j]) {
			c[k] = a[i];
			i++;
			k++;
		}
		else {
			c[k] = a[j];
			j++;
			k++;
		}
	}

	while (i <= mid)
		c[k++] = a[i++];
	while (j <= high)
		c[k++] = a[j++];
	for (i = low; i <= high; i++)
		a[i] = c[i];
}

int main() {
	int *a, n, i;
	merge m;

	printf("Enter the number of elements: ");
	scanf("%d", &n);

	a = new int[n];

	printf("Generating %d random elements\n", n);
	for (i = 0; i < n; i++)
		a[i] = (rand()%(2*n))+1;

	auto start = high_resolution_clock::now();

	m.m_sort(a, 0, n-1);

	auto stop = high_resolution_clock::now();

	auto duration = duration_cast<microseconds> (stop-start);

	printf("Sorted elements are: ");

	for (i = 0; i < n; i++)
		printf("%d ", a[i]);

	printf("\n\n");

	printf("Time taken = %lld microseconds\n", duration.count());

	printf("Space consumed: %d bytes\n", sizeof(n)+(n*sizeof(a))+sizeof(i)+sizeof(m));

	return 0;
}
