// @brief BUBBLE-SORT

/*
伪代码
for i = 1 to A.length - 1
    for j = A.length downto i + 1
        if A[j] < A[j - 1]
            exchange A[j] with A[j - 1]
*/

#include <iostream>

using namespace std;

void BUBBLE_SORT(int A[], int len);
void exchange(int &x, int &y);

// @language：C++
// @data structure：数组
// @brief 冒泡排序
// @param：A 排序数组
// @param：len 数组长度

void BUBBLE_SORT(int A[], int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = len; j > i; j--)
        {
            if (A[j] < A[j - 1])
            {
                exchange(A[j], A[j - 1]);
            }
        }
    }
}

// @brief 交换x, y的值
// @param：x, y

void exchange(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

int main()
{
    int A[] = {2, 4, 3, 1, 6, 5};
    BUBBLE_SORT(A, 6);
    for (int i = 0; i < 6; i++)
    {
        cout << A[i] << " ";
    }
    return 0;
}
