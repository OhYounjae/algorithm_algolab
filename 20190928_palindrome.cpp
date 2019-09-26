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
        
        for(int i = 2; i <= 64; i++){
            string str = "";
            bool check = false;
            while(temp >= i){
                str += to_string(temp % i);
                temp /= i;
            }
            string rever = str;
            reverse(rever.begin(), rever.end());
            for(int i = 0; i < str.length; i++){
                if(str[i] == rever[i]){
                    cout << 1 << endl;
                    check = true;
                    break;
                }
            }

            if(check) break;
            
        }
        cout << 0 << endl;        
    }

    in.close();
}