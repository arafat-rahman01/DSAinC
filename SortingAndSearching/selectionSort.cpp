#include<iostream>
using namespace std;
int main(){
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n-1;i++){
        int sidx=i;
        for(int j=i+1;j<n;j++){
            //small val idx find and store idx
            if(arr[j]<arr[sidx]){
                sidx=j;
            }
        }
        int temp=arr[i];
        arr[i]=arr[sidx];
        arr[sidx]=temp;
    }

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}