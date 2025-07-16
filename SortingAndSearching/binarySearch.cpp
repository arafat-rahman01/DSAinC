#include<bits/stdc++.h>
using namespace std;

int binarySearch(int  arr[],int low,int high,int value){
    
    while(low<=high){
        int mid=low+(high-low)/2;
        if(arr[mid]==value) return mid;
        else if(arr[mid]>value){
            high=mid-1;
        }else if(arr[mid]<value){
            low=mid+1;
        }
    }
    return -1;
}

int main(){
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int res=binarySearch(arr,0,n-1,10);
    if(res!=-1) cout<<"Found"<<endl;
    else cout<<"Not"<<endl;
}