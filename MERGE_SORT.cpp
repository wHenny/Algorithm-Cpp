// @brief MERGE_SORT 分治策略
// @language：C++
// @data structure：数组

/*
伪代码
MERGE_SORT(A, p, r)
if p < r
    q =[(p + r)/2]
    MERGE_SORT(A, p, q)
    MERGE_SORT(A，q + 1，r)
    MERGE(A, p, q, r)

MERGE(A, p, q, r)
n1 = q - p + 1
n2 = r - p
let L[1..n1+1] and R[1..n2+1] be new array
for i = 1 to n1
    L[i] = A[p + i -1]
for j = 1 to n2
    R[j] = A[q + j]
L[n1 + 1] = 0x3f3f3f3f
R[n2 + 1] = 0x3f3f3f3f
i = 1
j = 1
for k = p to r
    if L[i] <= R[j]
        A[k] = L[i]
        i = i + 1
    else
        A[k] = R[j]
        j = j + 1
*/

#include <iostream>

using namespace std;

void MERGE_SORT(int A[], int p, int r);
void MERGE(int A[], int p, int q, int r);

// @brief 归并排序
// @param：A 排序数组
// @param：p 头指针
// @param：r 尾指针

void MERGE_SORT(int A[], int p, int r)
{
    if (p < r)
    {
        int q = (p + r) / 2;
        MERGE_SORT(A, p, q);
        MERGE_SORT(A, q + 1, r);
        MERGE(A, p, q, r);
    }
}

// @brief 将数组A[p, q], A[q + 1, r]归并排序
// @param：A 排序数组
// @param：p 头指针
// @param：q 中间指针
// @param：r 尾指针

void MERGE(int A[], int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;
    int L[n1 + 1], R[n2 + 1];
    int i, j;
    for (i = 0; i < n1; i++)
        L[i] = A[p + i];
    for (j = 0; j < n2; j++)
        R[j] = A[q + j + 1];
    L[n1] = 0x3f3f3f3f;
    R[n2] = 0x3f3f3f3f;
    i = 0;
    j = 0;
    for (int k = p; k <= r; k++)
    {
        if (L[i] <= R[j])
        {
            A[k] = L[i];
            i = i + 1;
        }
        else
        {
            A[k] = R[j];
            j = j + 1;
        }
    }
}

int main()
{
    int A[] = {2, 4, 3, 1, 6, 5, 7};
    MERGE_SORT(A, 0, 6);
    for (int i = 0; i < 7; i++)
    {
        cout << A[i] << " ";
    }
    return 0;
}
