#include<bits/stdc++.h>
using namespace std;
//iterative solution
 bool sort(int a[],int size){
    bool flag=false;
    for(int i=0;i<size;i++){
        if(a[i+1]=a[i]-1){
            flag=true;
            swap(a[i],a[i+1]);
        }
        else{
            flag=false;
        }
    }
    return flag;
 }
int main()
{
   int a[]={1,0,3,2};
   int size=sizeof(a)/sizeof(a[0]);
   cout<<size<<endl;
   cout<<sort(a,size);
   return 0;
}
