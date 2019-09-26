#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void changeNum(int num){ //진법 변환
    string str;
    //if(num %)

    isPalindrome(str);
}

void isPalindrome(string str){ // 팰린드롬인지 확인
    for(int i = 0; i < str.length(); i++){
        if(str[i] != str[str.length()-i]){
            cout << 0 << endl;
            return;
        }
    }
    cout << 1 << endl;
}

int main(){
    ifstream in;
    in.open("input.txt");

    int t;
    in >> t;
    
    while(t--){
        int num;
        in >> num;
        string str = to_string(num);

        //10진수 먼저 판별
        for(int i = 0; i < str.length(); i++){
            if(str[i] != str[str.length()-1-i]){
                changeNum(num);
                break;
            }
        }
        
    }

    in.close();
}