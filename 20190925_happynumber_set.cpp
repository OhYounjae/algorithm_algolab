#include <iostream>
#include <fstream>
#include <set>

using namespace std;

set<int> num;

void happyNumber(int number){
    //입력된 값이 해피인지 판별
    if(number == 1){ 
        cout << "HAPPY" << endl;
        return;
    }
    pair<set<int>::iterator, bool> p = num.insert(number);
    if (!p.second){
        cout << "UNHAPPY" << endl;
        return;
    }
    // set<int>::iterator it;
    // //집합에 저장되어있는 값들과 비교해서 언해피 판별
    // for(it = num.begin(); it != num.end(); it++){
    //     if(*it == number){
    //         cout << "UNHAPPY" << endl;
    //         return;
    //     }
    // }


    int temp = number;
    int sum = 0;

    while(temp != 0){
        sum += (temp%10) * (temp%10);
        temp /= 10;
    }

    // num.insert(number);

    happyNumber(sum);
}


int main(){
    ifstream in;
    in.open("input.txt");

    int t;
    in >> t;
    int number;
    
    while(t--){
        in >> number;
        happyNumber(number);
        num.clear(); //집합 초기화 해줌
    }
    in.close();
}