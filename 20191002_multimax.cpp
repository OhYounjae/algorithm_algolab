#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(){
    ifstream in;
    in.open("input.txt");
    int t;
    in >> t;
    vector<int> temp;
    while(t--){
        int time;
        in >> time;
        for(int i = 0; i < time; i++){
            int a;
            in >> a;
            temp.push_back(a);
        }
        sort(temp.begin(), temp.end());
        
        int num;
        if(temp[0] < 0 & temp[1] < 0){
            num == temp[0]*temp[1];
        }
    }
}