// @brief INSERTION_SORT 插入排序
// @language：C++
// @data structure：数组

/*
伪代码
for j = 2 to A.length
	key = A[j]
	i = j - 1
	// Insert A[j] into the sorted sequence A[1..j-1]
	while i > 0 and A[i] > key
		A[i + 1]= A[i]
		i = i - 1
	A[i + 1] = key
*/

#include <iostream>

using namespace std;

void INSERTION_SORT(int A[], int len);

// @brief 插入排序
// @param：A 排序数组
// @param：len 数组长度

void INSERTION_SORT(int A[], int len)
{
	for (int j = 1; j < len; j++)
	{
		int key = A[j];
		int i = j - 1;
		while (i >= 0 && A[i] > key)
		{
			A[i + 1] = A[i];
			i--;
		}
		A[i + 1] = key;
	}
}

int main()
{
	int A[] = {2, 4, 3, 1, 6, 5};
	int len = sizeof(A) / sizeof(A[0]);
	INSERTION_SORT(A, len);
	for (int i = 0; i < len; i++)
	{
		cout << A[i] << " ";
	}
	return 0;
}
