class Solution {
public:
void countingSort(vector<int> &arr, int exp){
  int n = arr.size();
  vector<int> output(n);
  int count[10] = {0};
  for (int i = 0; i < n; i++) count[(arr[i] / exp) % 10]++;
  for (int i = 1; i < 10; i++) count[i] += count[i - 1];
  for (int i = n - 1; i >= 0; i--){
    output[count[(arr[i] / exp) % 10] - 1] = arr[i];
    count[(arr[i] / exp) % 10]--;
  }
  for (int i = 0; i < n; i++) arr[i] = output[i];
}
void radixSort(vector<int> &arr)
{
  if (arr.empty()) return;
  long long mx = *max_element(arr.begin(), arr.end());
  for (long long exp = 1; mx / exp > 0; exp *= 10) countingSort(arr, exp);
}
    int maximumGap(vector<int>& nums) {
        radixSort(nums);
        int n=nums.size();
        int res=0;
        for(int i=1;i<n;i++) res=max(res,nums[i]-nums[i-1]);
        return res;
    }
};