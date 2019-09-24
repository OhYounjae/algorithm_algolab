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
        long sum = 0; // 상자의 총 합
        long max_sum = 0; //최대값의 합

        for(int i = 0; i < x; i++){
            for(int j = 0; j < y; j++){
                arr2[i][j] = 0;
            }
        }

        //배열에 숫자들 넣어주기(가로줄 최댓값 구하면서 배열에 저장)
        for(int i = 0; i < x; i++){
            long maxi = 0;
            int a ,b;
            for(long j = 0; j < y; j++){
                long temp;
                in >> temp;
                arr1[i][j] = temp;
                sum += temp;
                if(temp >= maxi){
                    maxi = temp;
                    a = i;
                    b = j;
                }
                
            }
            arr2[a][b] = maxi;
            //cout << arr2[a][b] << endl;
            
        }
        //cout << endl;


        //각 배열별 최댓값 구하기(세로줄)
        for(int j = 0; j < y; j++){
            long maxi = 0;
            int a;
            int b;
            for(int i = 0; i < x; i++){
                if(arr1[i][j] >= maxi){
                    maxi = arr1[i][j];
                    a = i;
                    b = j;
                }
            }
            //cout << maxi << ' ';
            arr2[a][b] = maxi;
        }
        //cout << endl;


        // for(int i = 0; i < x; i++){
        //     for(int j = 0; j < y; j++){
        //         cout << arr2[i][j] << ' ';
        //     }
        //     cout << endl;
        // }

        //각 배열의 최대값 합 구하기
        for(int i = 0; i < x; i++){
            for(int j = 0; j < y; j++){
                max_sum += arr2[i][j];
            }
            
        }

        long total = sum - max_sum;
        cout << total << endl;

    }

    in.close();
}