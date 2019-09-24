#include <iostream>
#include <fstream>

using namespace std;

int arr[1001];

int main(){
    ifstream in;
    in.open("input.txt");
    int t;
    in >> t;
    for(int i = 2; i < 1001; i++){ // 배열 초기화
        arr[i] = 1;
    }
    for(int i = 2; i < 1001; i++){ //에라토스테네스의 체 정리끝
        for(int j = i * 2; j < 1001;j += i){
            arr[j] = 0;
        }
    }

    while(t--){
        int temp;
        in >> temp;
        
        // 조합 temp의 절반부터
        // ex) temp = 20
        for(int i = temp/2; i > 1; i--){
            int j = temp - i;
            if(arr[i] && arr[j]){
                cout << i << ' ' << j << endl;
                break;
            }
        }
        
    }

    in.close();
}