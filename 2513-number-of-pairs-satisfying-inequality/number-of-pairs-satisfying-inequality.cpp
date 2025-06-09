class Solution {
    long long mergeSort(vector<int>& arr, int left, int right, int diff) {
    if (left >= right) return 0;
    
    int mid = (left + right) / 2;
    long long count = mergeSort(arr, left, mid, diff) + mergeSort(arr, mid + 1, right, diff);

    int j = mid + 1;
    for (int i = left; i <= mid; ++i) {
        while (j <= right && arr[i] > arr[j] + diff) j++;
        count += (right - j + 1);
    }

    // Merge the two halves
    vector<int> sorted;
    int i = left; j = mid + 1;
    while (i <= mid && j <= right) {
        if (arr[i] < arr[j]) sorted.push_back(arr[i++]);
        else sorted.push_back(arr[j++]);
    }
    while (i <= mid) sorted.push_back(arr[i++]);
    while (j <= right) sorted.push_back(arr[j++]);

    for (int k = left; k <= right; ++k) {
        arr[k] = sorted[k - left];
    }

    return count;
}
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
          int n = nums1.size();
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        arr[i] = nums1[i] - nums2[i];
    }

    return mergeSort(arr, 0, n - 1, diff);
    }
};