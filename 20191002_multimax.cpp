#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ifstream in;
    in.open("input.txt");
    int t;
    in >> t;
    vector<int> temp;
    vector<int> number;
    while(t--){
        int time;
        in >> time;
        for(int i = 0; i < time; i++){
            int a;
            in >> a;
            temp.push_back(a);
        }
        sort(temp.begin(), temp.end());

        number.push_back(temp[0]*temp[1]);
        number.push_back(temp[0]*temp[1]*temp[time-1]);
        number.push_back(temp[time-1]*temp[time-2]);
        number.push_back(temp[time-1]*temp[time-2]*temp[time-3]);

        sort(number.begin(), number.end());
        int num = number[3];

        // if(temp[time-1]*temp[time-2] <= temp[time-1]*temp[time-2]*temp[time-3]){ //뒷자리 2개 곱한것과 3개 곱한것 비교
        //     num = temp[time-1]*temp[time-2]*temp[time-3];
        // }else{
        //     num = temp[time-1]*temp[time-2];
        // }

        // if(temp[0] < 0 & temp[1] < 0){ //vector앞 2개가 음수 일 경우
        //     if(temp[0]*temp[1]*temp[time-1] >= num){num = temp[0]*temp[1]*temp[time-1];}
        // }

        cout << num << endl;
        temp.clear();
        number.clear();
    }
}