#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main(){
    ifstream in;
    in.open("input.txt");

    int t;
    in >> t;
    
    while(t--){
        int num;
        in >> num;
        int temp = num;
        bool check = false;
        
        for(int i = 2; i <= 64; i++){
            string str = "";
            
            while(temp > 0){
                int t = temp % i;
                if (t < 10){ // 숫자처리
                    char a = t + 48;
                    str = a + str;
                }else{ // 문자처리
                    char a = 65 - 10 + t;
                    str = a + str;
                } 
                temp /= i;
            }
            // cout << str << endl;
            string rever = "";
            //cout << str << ' ';
            for(int j = str.length() - 1;j >= 0;j--){
                rever += str[j];
            }
            // reverse(rever.begin(), rever.end());
            if(str == rever){
                check = true;
                
            }

            if(check) break;
            temp = num;
        }
        if(check){
            cout << 1 << endl;
        }else cout << 0 << endl;
    }

    in.close();
}