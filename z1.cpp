#include <iostream>
using namespace std;

int main()
{
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int first=(a<<3)+(a<<2);
    int second=(d<<3)+(d<<2)+(d<<1)+d;
    int third=(b<<3)+(b<<2);
    int fourth=(c<<3)+(c<<2);
    int fifth=(d<<4)-d;
    double result=first+((second+third)>>10)-fourth+fifth;
    cout<<result;
    return 0;
}