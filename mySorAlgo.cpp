#include <iostream>
using namespace std;
//swap
static void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
//bubbleSort
static void bubbleSort(int *arr, int len)
{
    if (arr == nullptr || len < 2)
        return;
    for (int i = len - 1; i > 0; i--)
    {
        bool flag = true;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr, j + 1, j);
                flag = false;
            }
        }
        if (flag)
            break;
    }
}
//insertSort
static void insertSort(int arr[], int len)
{
    if (arr == nullptr || len < 2)
        return;
    for (int i = 1; i < len; i++)
    {
        for (int j = i - 1; j >= 0; j--)
            if (arr[j] > arr[j + 1])
                swap(arr, j, j + 1);
    }
}
//selectSort
static void selectSort(int arr[], int len)
{
    if (arr == nullptr || len < 2)
        return;
    for (int i = 0; i < len; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < len; j++)
            minIndex = arr[j] < arr[i] ? j : minIndex;
        swap(arr, minIndex, i);
    }
}
//mergeSort
static void merge(int arr[], int l, int m, int r)
{
    int size = r - l + 1;
    int *pt = new int[size];
    int i = 0, p1 = l, p2 = m + 1;
    while (p1 <= m && p2 <= r)
        pt[i++] = arr[p1] <= arr[p2] ? arr[p1++] : arr[p2++];
    while (p1 <= m)
        pt[i++] = arr[p1++];
    while (p2 <= r)
        pt[i++] = arr[p2++];
    for (i = 0; i < size; i++)
        arr[l + i] = pt[i];
    delete[] pt;
}
static void sortProcess(int arr[], int l, int r)
{
    if (l >= r)
        return;
    int mid = l + (r - l) / 2;
    sortProcess(arr, l, mid);
    sortProcess(arr, mid + 1, r);
    merge(arr, l, mid, r);
}
static void mergeSort(int arr[], int len)
{
    if (len < 2)
        return;
    sortProcess(arr, 0, len - 1);
}

//quickSort
static int partition(int arr[], int l, int r)
{
    int i = l;
    int j = r;
    int pivot = arr[l];
    while (i < j)
    {
        while (i < j && arr[j] >= pivot)
            j--;
        while (i < j && arr[i] <= pivot)
            i++;
        if (i < j)
            swap(arr, i, j);
    }
    swap(arr, i, l);
    return i;
}
static int partition02(int arr[], int l, int r)
{
    int pivot = arr[r];
    int less = l;
    while (l < r)
    {
        if (arr[l] <= pivot)
        {
            swap(arr, less, l);
            less++;
        }
        l++;
    }
    swap(arr, less, r);
    return less;
}
static void quickSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int p = partition02(arr, l, r);
        quickSort(arr, l, p - 1);
        quickSort(arr, p + 1, r);
    }
}

//heapSort

static void print(int arr[], int len)
{
    for (int i = 0; i < len; i++)
        cout << arr[i] << ' ';
}

int main()
{

    int arr[10] = {5, 9, 10, 23, 0, 2, 4, 6, 7, 100};
    int len = sizeof(arr) / sizeof(int);
    quickSort(arr, 0, 9);
    print(arr, len);
    return 0;
}