// https://practice.geeksforgeeks.org/problems/maximum-index-1587115620/1/?company[]=Amazon&company[]=Amazon&page=13&query=company[]Amazonpage13company[]Amazon
/*
	 Given an array A[] of N positive integers. The task is to find the maximum of j - i subjected to the constraint of A[i] < A[j] and i < j.
 */


#include <bits/stdc++.h>
using namespace std;

/* For a given array arr[],
returns the maximum j – i such that
arr[j] > arr[i] */
int maxIndexDiff(int arr[], int n)
{
	int maxDiff;
	int i, j;

	int* LMin = new int[(sizeof(int) * n)];
	int* RMax = new int[(sizeof(int) * n)];

	/* Construct LMin[] such that
	LMin[i] stores the minimum value
	from (arr[0], arr[1], ... arr[i]) */
	LMin[0] = arr[0];
	for (i = 1; i < n; ++i)
		LMin[i] = min(arr[i], LMin[i - 1]);

	/* Construct RMax[] such that
	RMax[j] stores the maximum value from
	(arr[j], arr[j+1], ..arr[n-1]) */
	RMax[n - 1] = arr[n - 1];
	for (j = n - 2; j >= 0; --j)
		RMax[j] = max(arr[j], RMax[j + 1]);

	/* Traverse both arrays from left to right
	to find optimum j - i. This process is similar to
	merge() of MergeSort */
	i = 0, j = 0, maxDiff = -1;
	while (j < n && i < n) {
		if (LMin[i] <= RMax[j]) {
			maxDiff = max(maxDiff, j - i);
			j = j + 1;
		}
		else
			i = i + 1;
	}

	return maxDiff;
}

// Driver Code
int main()
{
	int arr[] = { 9, 2, 3, 4, 5,
				6, 7, 8, 18, 0 };
	int n = sizeof(arr) / sizeof(arr[0]);
	int maxDiff = maxIndexDiff(arr, n);
	cout << maxDiff;
	return 0;
}

// This code is contributed by rathbhupendra


