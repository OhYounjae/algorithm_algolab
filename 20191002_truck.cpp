#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

queue<int> truck;

int main(){
    ifstream in;
    in.open("input.txt");
    
    int t;
    in >> t;
    while(t--){
        int n, w, L;
        in >> n >> w >> L;
        //n: 트럭의 수, w: 다리의 길이, L: 최대하중

        int n_w = w - 1; //배열 bridge의 최대 인덱스 값
        int bridge[w];
        for(int i = 0; i < w; i++){
            bridge[i] = 0;
        }

        int weight = 0;//현재 무게
        int cnt = 1;
        while (n--){ //큐에 각 트럭의 무게 입력
            int temp;
            in >> temp;
            truck.push(temp);
        }
        
        while(!truck.empty()){
            if(weight + truck.front() <= L){ // 다리위에 차 올려놓는 것
                bridge[n_w] = truck.front();
                weight += truck.front();
                truck.pop();
            }
            // 움직여
            weight -= bridge[0];
            for(int i = 0; i < n_w; i++){
                bridge[i] = bridge[i+1];
            }
            bridge[n_w] = 0;

            // 초 += 1
            cnt += 1;
        }
        // cout << weight << endl;

        while(weight != 0){//마지막으로 들어간 트럭, 다리 건너게 해주기
            weight -= bridge[0];
            for(int i = 0; i < n_w; i++){
                bridge[i] = bridge[i+1];
                if (bridge[i] != 0){
                    //cout << bridge[i] << " " << i << endl;
                    //cout << weight << endl;
                }
            }
            bridge[n_w] = 0;
            
            // 초 += 1
            cnt += 1;
        }
        cout << cnt << endl;
        
    }

    in.close();
}