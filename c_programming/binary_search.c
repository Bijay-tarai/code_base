// C program to implement iterative Binary Search
#include <stdio.h>
 
// An iterative binary search function.
int binarySearch(int arr[], int l, int r, int x)
{
    while (l <= r) {
        int m = l + (r - l) / 2;
        // Check if x is present at mid
        if (arr[m] == x)
            return m;
 
        // If x greater, ignore left half
        if (arr[m] < x)
            l = m + 1;
 
        // If x is smaller, ignore right half
        else
            r = m - 1;
    }
 
    // If we reach here, then element was not present
    return -1;
}
 
// Driver code
int main(void)
{
    int arr[] = {2, 5, 8, 12, 23, 16, 38, 56, 72, 91};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("n=%d\n",n);
    int x = 23;
    int result = binarySearch(arr, 0, n - 1, x);
    (result == -1) ? printf("Element is not present in array\n"): printf("Element is present at index %d\n",result);
    return 0;
}