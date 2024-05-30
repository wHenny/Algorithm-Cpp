// @brief FIND_MAXIMUM_SUBARRAY 寻找最大子数组
// @language：C++
// @data structure：数组

/*
伪代码
FIND_MAX_CORSSING_SUBARRAY(A, low, mid, high)
left_sum = -0x3f3f3f3f
sum = 0
for i = mid down to low
    sum = sum + A[i]
    if sum > left_sum
        left_sum = sum
        max_left = i
right_sum = -0x3f3f3f3f
sum = 0
for j = mid + 1 to high
    sum = sum + A[j]
    if sum > right_sum
        rigth_sum = sum
        max_right = j
return (max_left, max_right, left_sum + right_sum)

FIND_MAXIMUM_SUBARRAY(A,low,high)
if high  == low
    return (low, high, A[low])
else mid = [(low + high)/2]
    (left_low, left_high, left_sum) = FIND_MAXIMUM_SUBARRAY(A, low, mid)
    (right_low, right_high, right_sum) = FIND_MAXIMUM_SUBARRAY(A, mid + 1, high)
    (cross_low, cross_high, cross_sum) = FIND_MAX_CORSSING_SUBARRAY(A, low, mid, high)

if left_sum >= right_sum and left_sum >= cross_sum
    return (left_low, left_high, left_sum)
else if  right_sum >= left_sum and right_sum >= cross_sum
    return (right_low, right_high, right_sum)
else
    return (cross_low, cross_high, cross_sum)

*/

#include <iostream>

using namespace std;

int *FIND_MAX_CORSSING_SUBARRAY(int A[], int low, int mid, int high);
int *FIND_MAXIMUM_SUBARRAY(int A[], int low, int high);

// @brief 求跨越中点的最大子数组
// @param：A 数组
// @param：low 数组的起始位置
// @param：high 数组末尾位置

int *FIND_MAX_CORSSING_SUBARRAY(int A[], int low, int mid, int high)
{
    int *cross_subarray = new int[3];

    // 求解左侧数组最大和
    int sum;
    sum = 0;
    int left_sum = -0x3f3f3f3f;
    int max_left = mid;
    for (int i = mid; i >= low; i--)
    {
        sum = sum + A[i];
        if (sum > left_sum)
        {
            left_sum = sum;
            max_left = i;
        }
    }

    // 求解右侧数组最大和
    sum = 0;
    int right_sum = -0x3f3f3f3f;
    int max_right = mid + 1;

    for (int j = mid + 1; j <= high; j++)
    {
        sum = sum + A[j];
        if (sum > right_sum)
        {
            right_sum = sum;
            max_right = j;
        }
    }
    cross_subarray[0] = max_left;
    cross_subarray[1] = max_right;
    cross_subarray[2] = left_sum + right_sum;
    return cross_subarray;
}

// @brief 寻找最大子数组
// @param：A 数组
// @param：low 数组的起始位置
// @param：mid 数组的中间位置
// @param：high 数组末尾位置

int *FIND_MAXIMUM_SUBARRAY(int A[], int low, int high)
{
    // 只有一个元素时返回本身
    if (high == low)
    {
        int *maximum_subarray = new int[3];
        maximum_subarray[0] = low;
        maximum_subarray[1] = high;
        maximum_subarray[2] = A[low];
        return maximum_subarray;
    }
    else
    {
        // 当元素大于一个时，递归求解左侧最大数组，右侧最大数组和跨越中点的最大数组
        int *lefy_subarray = new int[3];
        int *right_subarray = new int[3];
        int *cross_subarray = new int[3];
        int mid = (low + high) / 2;
        lefy_subarray = FIND_MAXIMUM_SUBARRAY(A, low, mid);
        right_subarray = FIND_MAXIMUM_SUBARRAY(A, mid + 1, high);
        cross_subarray = FIND_MAX_CORSSING_SUBARRAY(A, low, mid, high);
        if (lefy_subarray[2] >= right_subarray[2] and lefy_subarray[2] >= cross_subarray[2])
        {
            return lefy_subarray;
        }
        else if (right_subarray[2] >= lefy_subarray[2] and right_subarray[2] >= cross_subarray[2])
        {
            return right_subarray;
        }
        else
        {
            return cross_subarray;
        }
    }
}

int main()
{
    int A[] = {2, 4, 3, -1, 6, -4};
    int len = sizeof(A) / sizeof(A[0]);
    int *result = FIND_MAXIMUM_SUBARRAY(A, 0, len - 1);
    cout << result[0] << endl;
    cout << result[1] << endl;
    cout << result[2] << endl;
    return 0;
}
