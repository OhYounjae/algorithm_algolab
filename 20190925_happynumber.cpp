#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<int> num; //벡터 생성

void getSum(int number){

    int temp = number;
    int sum = 0;

    if(temp == 1){ //값이 1이면 자동으로 happy 출력
        cout << "HAPPY" << endl;
        return;
    }

    for(int i = 0; i < num.size(); i++){ //vector에 저장되어 있는 값들과 비교
        if(num[i] == temp){
            cout << "UNHAPPY" << endl;
            return;
        }
    }
    
    while(temp != 0){ // 각 자리수 제곱한 값 구하기
        sum += (temp % 10) * (temp % 10);
        temp /= 10;
    }

    num.push_back(number); //vector에 없는 값이면 vector에 추가

    getSum(sum);//재귀함수 호출
    
}
    

int main(){
    ifstream in;
    in.open("input.txt");

    int t;
    in >> t;

    int number;
    while(t--){
        in >> number;
        getSum(number);
        num.clear(); //벡터 초기화 꼭 해줄 것!!!!!
    }

     in.close();
}