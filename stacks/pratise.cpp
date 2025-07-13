#include<bits/stdc++.h>
using namespace std;

void swap(int &a,int &b){
    int t=a;
    a=b;
    b=t;
}

int par(int arr[],int low,int high){
    int p=arr[high];
    int i=low-1;

    for(int j=low;j<high;j++){
        if(arr[j]<p){
            i++;
            swap(arr[i],arr[j]);
        }
    }

    swap(arr[i+1],arr[high]);
    return i+1;
}

void quicksort(int arr[],int low,int high){
    if(low<high){
        int pi=par(arr,low,high);

        quicksort(arr,low,pi-1);
        quicksort(arr,pi+1,high);
    }
}

int main(){
    int n ;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    quicksort(arr,0,n-1);

    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";

}