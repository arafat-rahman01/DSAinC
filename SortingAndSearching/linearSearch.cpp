#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int item=10;
    bool flag=false;
    for(int i=0;i<n;i++){
        if(flag) break;
        if(arr[i]==item && flag==false){
            flag=true;
            cout<<"Find the value : "<<arr[i] << " index : "<< i<<endl;
        }
    }
}