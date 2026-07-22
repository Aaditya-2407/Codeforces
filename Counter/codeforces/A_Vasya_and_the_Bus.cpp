#include <iostream>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    long long n , m;
    cin >> n>> m;

   if(n == 0 && m!=0)
   {
    cout<<"Impossible"<<endl;
    return 0;
   }
   else if(n ==1 && m!=0)
   {
    cout<<m<<" "<<m<<endl;
    return 0;
   }
   else if(n==1 && m==0)
   {
    cout<<n<<" "<<n<<endl;
   }
   else if(m==0){
    cout<<n<<" "<<n<<endl;
    return 0;
   }
   else if(m==1)
   {
    cout<<n<<" "<<n<<endl;
    return 0;
   }
   else if(n == 0 && m==0){
    cout<<0<<" "<<0<<endl;
    return 0;
   }
   else if(n > m)
   {
    cout<<n<<" "<<m+(n-1)<<endl;
    return 0;
   }
   else if(n == m){
    cout<<n<<" "<<n+m-1<<endl;
    return 0;
   }
   else{
    cout<<n+(m-n)<<" "<<m+(n-1)<<endl;
    return 0;
   }

    
    

   
   
}