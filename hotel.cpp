#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ifstream in;
    in.open("input.txt");

    int t;
    in >> t;
    while(t--){
        int h, w, n;
        in >> h >> w >> n;
        int temp = 1;
        while(n - h > 0){
            temp++;
            n -= h;
        }
        cout << n * 100 + temp << endl;
    }

    in.close();
}

