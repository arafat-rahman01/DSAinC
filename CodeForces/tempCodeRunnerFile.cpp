#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int diff=INT16_MAX;
        int a=0,c=0;
        for(int i=0;i<n-1;i++){
            if(arr[i]>arr[i+1]){
                a=0;
                break;
            }
            a++;
            c=arr[i+1]-arr[i];
            diff=min(diff,c);
        }
        if(a==0) cout<<0<<endl;
        else{
            cout<<(diff/2)+1<<endl;
        }
    } 
}