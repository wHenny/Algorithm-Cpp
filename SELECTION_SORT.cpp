// @brief SELECTION-SORT

/*
伪代码
for j = 1 to A.length - 1
    smallest = j
    for i = j + 1 to A.length
        if A[i] < A[smallest]
            smallest = i
    exchange A[j] with A[smallest]
*/

#include <iostream>

using namespace std;

void SELECTION_SORT(int A[], int len);
void exchange(int &x, int &y);

// @Language：C++
// @data structure：数组
// @brief c选择排序
// @param：A 排序数组
// @param：len 数组长度

void SELECTION_SORT(int A[], int len)
{
    for (int j = 0; j < len - 1; j++)
    {
        int min = j;
        for (int i = j + 1; i < len; i++)
        {
            if (A[i] < A[min])
            {
                min = i;
            }
        }
        exchange(A[j], A[min]);
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
    SELECTION_SORT(A, 6);
    for (int i = 0; i < 6; i++)
    {
        cout << A[i] << " ";
    }
    return 0;
}
