#include <stdio.h>

int removeElement(int* nums, int numsSize, int val) {
  if(numsSize == 0 ) return 0;
  int i, k = 0;
  for(i = 0; i < numsSize ; i++){
    if(nums[i] != val) {
        nums[k] = nums[i];
        k++;
    }
  }
  return k;    
}

int main(){
    int arr1[6] = {1,2,2,2,3,5};

    int val = 1; 
    int k = removeElement(arr1, 6, val);

    for(int i = 0; i < k; i++)  printf("%d ", arr1[i]);


}
