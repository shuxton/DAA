#include <cstdio>
#include <chrono>

using namespace std::chrono;

class linear {
	int loc;

	public:

	void ls(int *, int, int);
};

class binary {
	int loc, low, mid, high;

	public:

	void bs(int *, int, int);
};

void linear::ls(int a[], int n, int key) {
	loc = -1;

	for (int i = 0; i < n; i++)
		if (a[i] == key) {
			loc = i;
			break;
		}

	if (loc >= 0)
		printf("Element found at position: %d\n", loc+1);
	else
		printf("Element not found\n");
}

void binary::bs(int a[], int n, int key) {
	low = 0;
	high = n-1;

	loc = -1;

	while (low <= high) {
		mid = (low+high)/2;

		if (a[mid] == key) {
			loc = mid;
			break;
		}
		if (a[mid] > key)
			high = mid-1;
		else
			low = mid+1;
	}

	if (loc >= 0)
		printf("Element found at position: %d\n", loc+1);
	else
		printf("Element not found\n");
}

int main() {
	int n, i, j, k;
	clock_t start, stop;

	linear l;
	binary b;

	printf("Enter the number of elements in the array: ");
	scanf("%d", &n);

	int a[n];

	printf("Enter the element of the array: ");
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);

	while (1) {
		printf("\nSearch Operations\n");
		printf("1. Linear Search\n");
		printf("2. Binary Search\n");
		printf("3. Exit\n");
		printf("Enter option: ");
		scanf("%d", &j);

		printf("Enter the element to be searched for: ");
		scanf("%d", &k);

		if (j == 1) {
			auto start = high_resolution_clock::now();
			l.ls(a, n, k);
			auto stop = high_resolution_clock::now();

			auto duration = duration_cast<microseconds> (stop-start);

			printf("Time taken = %lld microseconds\n", duration.count());
			printf("Space consumed = %d bytes\n", sizeof(n)+(n*sizeof(a))+sizeof(i)+sizeof(k)+sizeof(l));
		}
		else if (j == 2) {
			auto start = high_resolution_clock::now();
			b.bs(a, n, k);
			auto stop = high_resolution_clock::now();

			auto duration = duration_cast<microseconds> (stop-start);

			printf("Time taken = %lld microseconds\n", duration.count());
			printf("Space consumed = %d bytes\n", sizeof(n)+(n*sizeof(a))+sizeof(i)+sizeof(k)+sizeof(b));
		}
		else if (j == 3)
			break;
		else
			printf("Wrong option\n");
	}

	return 0;
}
