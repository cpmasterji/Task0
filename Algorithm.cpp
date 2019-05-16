#include<iostream>
using namespace std;

int main(){
    int a[50],n,m;
    cout<<"Enter number of elements: ";
    cin>>n;
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++)
    cin>>a[i];
    m=a[0];
    for(int i=0;i<n;i++)
        if(a[i]>m)
            m=a[i];
    cout<<"Maximum element is "<<m;
}