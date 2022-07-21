#include<stdio.h>

int binarysearch(int arr[], int data, int n){
    int l=0, r=n-1;
    int mid;
    while(r>l){
        mid=(l+r)/2;
        if(data==arr[mid]){
            return mid;
        }
        else if(data>arr[mid]){
            l=mid+1;
        }
        else r=mid-1;
    }
    return -1;

}

int main(){
    int arr[]={1,3,5,7,9,11};
    int n = sizeof(arr)/sizeof(arr[0]);
    int data = 2;
    int x = binarysearch(arr, data,  n);
    if(x==-1){
        printf("data not found");
    }
    else 
         printf("Element found at pos %d", &x);

}