#include <iostream>
#include <cmath>
#include <ctime>
#include <windows.h>


using namespace std;

int isMatch(int num, int n){
    int k,c1,c2;
    k=num;
    c1=k%2; k/=2;
    for(int i=1;i<n;++i){
        c2=k%2;
        if(c1==1&&c2==1){
            return -1;
        }
        c1=c2;
        c2=k%2;
        k/=2;
    }
    if(c2)  return 1;
    else return -1;
}
void numToArray(unsigned long long  a[],int num, int n){
    int k=num;
    for(int i=0;i<n;i++){
        a[n-i-1]=k%2;
        k/=2;
    }
}

void A(double& k,double& l){
    double x = k;
    k = x/(2*x+2);
    l = (x+l+1)/(2*x+2);
}
void B(double& k,double& l){
    double x = k;
    k = l-0.5;
    l = x+0.5;
}
double T(double k,double l){
    return (l+1)/(1.5-k);
}
int fib2(int n){
    double s1,s2,x,z;
    z = sqrt(5);
    s1 = pow((1+z)/2,n);
    x = s1/z;
    if(x-int(x)>0.5) x = int(x)+1;
    else x = int(x);
    return x;
}





int main(){

mark:
/// Program start time

    unsigned long long  n,id=0,minNum=1;
    cout<<"\n\nEnter N: ";
    cin>>n;
    cout<<"\n";

    unsigned int start_t = clock();

    unsigned long long  **a =new unsigned long long *[fib2(n)];
    for(int i=int(pow(2,n)/2);i<int(pow(2,n));++i){
        if(isMatch(i,n)>0){
            a[id] = new unsigned long long [n];
            numToArray(a[id],i,n);
            id++;
        }
    }

/// exp pair
double k=0,l=1,teta=T(k,l);

for(int i=0;i<int(fib2(n));++i){
    for(int j=0;j<n;++j){
        if(a[i][j]==1){
            B(k,l);
        }else{
            A(k,l);
        }
        if(T(k,l)<teta){
            teta = T(k,l);
            minNum=i;
            cout.precision(60);
            cout<<"teta = "<<teta<<endl;
        }
    }
}

cout.precision(60);
cout<<"\n\nNo of min combination : "<<minNum<<", all comb. quantity = "<<fib2(n)<<"\n\nTETA = "<<teta<<"\n\n";

/// OUTPUT
    for(int i=0;i<n;++i) if(a[minNum][i]) cout<<'B'<<' '; else  cout<<'A'<<' ';

/// Program end time
    unsigned int end_time = clock();
    cout.precision(3);
    cout<<"\n\nTime: "<<(end_time-start_t)/1000.0<<" seconds\n\n\n";
    cout<<"Would you like enter another number? <YES - 1, NO - 0> \n";
    cin>>n; if(n) goto mark;
    cout<<"\n\n";
    system("pause");
}
