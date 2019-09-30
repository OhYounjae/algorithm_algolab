#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

vector<int> num;

int main(){
    int t;
    ifstream in;
    in.open("input.txt");
    in >> t;
    while(t--){
        int time, target;
        in >> time >> target;
        int chk = 987654321; // 두 수의 합과 target과의 차이 
        int count = 0;
        for(int i = 0; i < time; i++){ //입력값들 벡터에 넣기
            int temp;
            in >> temp;
            num.push_back(temp);
        }
        sort(num.begin(), num.end()); //sorted vector

        int x = 0;
        int y = time - 1;
        while(x < y){
            // 따로 카운팅
            if(abs(target - (num[x]+num[y])) < chk){
                chk = abs(target - (num[x]+num[y]));
                count = 1;
            }else if(abs(target - (num[x] + num[y])) == chk){
                chk = abs(target - (num[x] + num[y]));
                count += 1;
            }

            // left & right 값 변화
            if(num[x] + num[y] <= target){
                x += 1;
            }else if(num[x] + num[y] > target){
                y -= 1;
            }
        }
        cout << count << endl;
        num.clear(); //벡터 초기화
    }

    in.close();
}