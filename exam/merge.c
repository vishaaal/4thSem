#include <stdio.h>

void merge(int arr[], int p, int q, int r) {

  int n1 = q - p + 1;
  int n2 = r - q;

  int L[n1], M[n2];

  for (int i = 0; i < n1; i++)
    L[i] = arr[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = arr[q + 1 + j];

  int i, j, k;
  i = 0;
  j = 0;
  k = p;
  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = M[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = M[j];
    j++;
    k++;
  }
}

void mergeSort(int arr[], int l, int r) {
  if (l < r) {

    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    merge(arr, l, m, r);
  }
}

void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

int main() {
  int arr[] = {6, 5, 12, 10, 9, 1};
  int size = sizeof(arr) / sizeof(arr[0]);

  mergeSort(arr, 0, size - 1);

  printf("Sorted array: \n");
  printArray(arr, size);
}

// procedure merge(Arr[], lt, mid, rt):
//     int L1 = mid - lt + 1
//     int L2 = rt-mid
//     int left[L1], right[L2]
    
//     for i = 0 to L1:
//         left[i] = Arr[lt + i]
//     END for loop
    
//     for j = 0 to L2:
//         right[j] = Arr[mid+1+j]
//     END for loop
    
//     while(left and right hve elments):
//         if(left[i] < right[j])
//             Add left[i] to the end of Arr
//         else
//             Add right[i] to the end of Arr
//     END while loop
    
// END procedure    

// procedure Merge_sort(Arr[]):
//     l1 = Merge_sort(L1)
//     l2 = Merge_sort(L2)
//     return merge(l1, l2)
// END procedure