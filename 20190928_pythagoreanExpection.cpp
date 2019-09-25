#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main(){
    ifstream in;
    in.open("input.txt");
    int t;
    in >> t;
    while(t--){
        int n, m;
        in >> n >> m; //n은 팀 개수, m은 전체 경기 수
        int arr1[1001] = {0, }; //득점 기록 배열
        int arr2[1001] = {0, }; //실점 기록 배열
        int total[1001] = {0, }; //기댓값 기록 배열        

        for(int i = 0; i < m; i++){
            //p는 team1의 득점이자 team2의 실점
            //q는 team2의 득점이자 team1의 실점
            int team1, team2, p, q; 
            in >> team1 >> team2 >> p >> q;

            //team1의 득점과 실점 처리
            arr1[team1] += p;
            arr2[team1] += q;

            //team2의 득점과 실점 처리
            arr1[team2] += q;
            arr2[team2] += p;

            // cout << arr1[team1] << ' ' << arr1[team2] << endl;
            // cout << arr2[team1] << ' ' << arr2[team2] << endl;
        }

        for(int i = 1; i < n + 1; i++){
            total[i] = arr1[i] * arr1[i] *1000;
            total[i] /= (arr1[i]*arr1[i] + arr2[i]*arr2[i]);
        }
        int maxi = 0;
        int mini = 987654321;
        for(int i = 1; i < n+1; i++){
            if(total[i] >= maxi){
                maxi = total[i];
            }

            if(total[i] <= mini){
                mini = total[i];
            }
        }
        cout << maxi << endl << mini << endl;

    }

    in.close();
}