#include <iostream>
using namespace std;

void mergeAndCount(int nums[], int result[], int left, int right) {
    if (left >= right) return;
    
    int mid = left + (right - left) / 2;
    
    mergeAndCount(nums, result, left, mid);   // Sort and count smaller elements in left half
    mergeAndCount(nums, result, mid + 1, right);  // Sort and count smaller elements in right half
    
    int temp[right - left + 1];
    int i = left, j = mid + 1, k = 0;
    
    while (i <= mid && j <= right) {
        if (nums[i] <= nums[j]) {
            temp[k++] = nums[i++];
        } else {
            result[i] += (mid - i + 1);  // Count how many elements in left half are greater than nums[j]
            temp[k++] = nums[j++];
        }
    }
    
    // Copy remaining elements of left half, if any
    while (i <= mid) {
        temp[k++] = nums[i++];
    }
    
    // Copy remaining elements of right half, if any
    while (j <= right) {
        temp[k++] = nums[j++];
    }
    
    // Copy sorted elements back to the original array
    for (int i = 0; i < k; i++) {
        nums[left + i] = temp[i];
    }
}

void countSmaller(int nums[], int result[], int n) {
    mergeAndCount(nums, result, 0, n - 1);
}

int main() {
    int nums[] = {5, 2, 6, 1};
    int n = sizeof(nums) / sizeof(nums[0]);
    int result[n] = {0};
    
    countSmaller(nums, result, n);
    
    // Output the result
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    
    return 0;
}

