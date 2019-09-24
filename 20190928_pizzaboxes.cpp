#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ifstream in;
    in.open("input.txt");
    int t;
    in >> t;
    while(t--){
        int x, y;
        in >> x >> y;
        int arr1[x][y]; //2차원 배열 생성
        int arr2[x][y]; //각 배열별 최댓값만 저장할 새로운 배열
        int sum = 0; // 상자의 총 합
        int max_sum = 0; //최대값의 합
        int total; //총 버려야 하는 상자의 값

        //배열에 숫자들 넣어주기
        for(int i = x - 1; i >= 0; i--){
            for(int j = 0; j < y; j++){
                int temp;
                in >> temp;
                arr1[i][j] = temp;
                sum += temp;
            }
        }

        //각 배열별 최댓값 구하기(가로줄)
        for(int i = x - 1; i >= 0; i--){
            int temp = 0;
            int a, b;
            for(int j = 0; j < y; j++){
                if(arr1[i][j] >= temp){
                    temp = arr1[i][j];
                    a = i;
                    b = j;
                }
            }
            arr2[a][b] = temp;
        }

        //각 배열별 최댓값 구하기(세로줄)
        for(int j = 0; j < y; j++){
            int temp = 0;
            int a;
            int b;
            for(int i = x - 1; x >= 0; x++){
                if(arr1[i][j] >= temp){
                    temp = arr1[i][j];
                    a = i;
                    b = j;
                }
            }
            arr2[a][b] = temp;
        }

        for(int i = 0; i < x; i++){
            for(int j = 0; j < y; j++){
                max_sum += arr2[i][j];
            }
        }
        
        total = sum - max_sum;
        cout << total << endl;

    }

    in.close();
}