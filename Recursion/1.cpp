#include <bits/stdc++.h>
using namespace std;

void PrintCount(int i,int N){
    if(i > N){
        return;
    }
    PrintCount(i+1,N);
    cout<<i<<endl;
}
void PrintReverseCount(int i,int N){
    if(i > N){
        return;
    }
    PrintReverseCount(i+1,N);
    cout<<i<<endl;
}
int PrintFactorial(int N){
    if(N == 0){
        return 1;
    }
    return N * PrintFactorial(N-1);
}
int main()
{
    int N=5;
    int i=1;
    // PrintReverseCount(i,N);
    cout<<PrintFactorial(N);

   
  return 0;
}