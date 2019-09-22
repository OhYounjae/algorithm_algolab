#include <iostream>
#include <fstream>

using namespace std;

int gcd(int a, int b)
{
   return a % b ? gcd(b, a % b) : b;
}

int main(){
    ifstream in;
    in.open("input.txt");

    int t;
    in >> t;

    int a, b;
    while(t--){
        in >> a >> b;
        int temp;
        while(a != 1){ //마지막 함수 구하는 횟수(분자가 1이 될때까지)
        if(a % b == 0){temp = b / a;}
        if(a % b != 0){temp = b / a + 1;}

        a = a * temp - b;
        b = b * temp;
        // cout << a << ' ' << b << endl;

        int num = gcd(a,b);//최대공약수 구해서 나눠주기
        a /= num;
        b /= num;

        }
        
        cout << b << endl;
        
    }

     in.close();
}