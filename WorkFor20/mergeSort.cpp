#include<bits/stdc++.h>

using namespace std;

int arr[] = {1,2,333,22,8938};

void merge(int* arr, int left, int mid, int right){
    int* temp = new int[right-left+1];
    int i = left, j=mid+1, k=0;
    while (i<=mid && j <=right) {
        if (arr[i] <= arr[j]) temp[k++] = arr[i++];
        else temp[k++] = arr[j++];
    }
    while(i<=mid) temp[k++] = arr[i++];
    while(j<=right) temp[k++] = arr[j++];
    for (int p=0; p<k ;p++) {
        arr[left+p] = temp[p];
    }
    delete[] temp;
}

void mergeSort (int* arr,int l, int r) {
    if (l < r) {
        int mid = l + ((r-l) >> 1);
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, r);
        merge(arr, l, mid, r);
    }
}

int main(){
    mergeSort(arr,0,4);
    for (int i=0; i<5 ;i++) cout << " " << arr[i];
}