#include<iostream>
using namespace std;


void TOH(int n, char A , char B ,char C)
{
    
   if(n==1)
   {
     cout<<"Move the ring 1 from "<< A<<" to "<<B<<endl;
     return;
   }

   else
   TOH (n-1 , A,C,B);

   cout<<"Move the ring "<<n << " from " << A <<" to "<<B<<endl;
   TOH(n-1 ,C,B,A);

}
int main()
{
   int n;
   cout<<"Enter the number of rings"<<endl;
   cin>>n;
   TOH (n, 'A', 'B', 'C');
   return 0;
}