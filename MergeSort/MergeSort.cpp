#include <iostream>

#define MAX_SIZE 8	

using namespace std;

int sorted[MAX_SIZE];

// 병합과정
void merge(int list[], int left, int mid, int right)
{
	int i, j, k, l;

	i = left;
	j = mid + 1;
	k = left;

	while (i <= mid && j <= right)
	{
		if (list[i] <= list[j])
		{
			sorted[k++] = list[i++];
		}
		else
		{
			sorted[k++] = list[j++];
		}
	}

	// 우측 분할 한 리스트에 아직 남아있는 것이 있는지,
	if (i > mid)
	{
		for (l = j; l <= right; l++)
		{
			sorted[k++] = list[l];
		}
	}
	else // 좌측 분할 한 리스트에 아직 남아있는 것이 있는지,
	{
		for (l = i; l <= mid; l++)
		{
			sorted[k++] = list[l];
		}
	}

	// 복사하는 과정
	for (l = left; l <= right; l++)
	{
		list[l] = sorted[l];
	}
}
void mergesort(int list[], int left, int right)
{
	int mid;


	if (left < right)
	{
		mid = (left + right) / 2;
		mergesort(list, left, mid);
		mergesort(list, mid + 1, right);

		merge(list, left, mid, right);
	}
}

int main(void)
{
	int n = MAX_SIZE;
	int nList[MAX_SIZE] = { 21, 10, 12, 20, 25, 13, 15, 22 };

	mergesort(nList, 0, n - 1);

	for (int i = 0; i < n; i++)
	{
		cout << nList[i] << " ";
	}
	return 0;
}