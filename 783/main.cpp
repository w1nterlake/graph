#include <bits/stdc++.h>
#include <fstream>


int DFS(std::vector<std::vector<char>> &graph){
    int N = 8;
    std::vector<std::vector<int>> used(N, std::vector<int> (N, 0));
    int x, y;
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    int ans = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            std::stack<std::pair<int, int>> st;
            if(used[i][j] == 1){
                continue;
            }
            st.push({j, i});
            used[i][j] = 1;
            while(!st.empty()){
                x = st.top().first;
                y = st.top().second;
                st.pop();
                for(int k = 0; k < 4; k++){
                    int x1 = x + dx[k];
                    int y1 = y + dy[k];
                    if(x1 >= 0 && x1 < N && y1 >= 0 && y1 < N){
                        if(used[y1][x1] == 0 && graph[y1][x1] != graph[y][x]){
                            used[y1][x1] = 1;
                            st.push({x1, y1});
                        }
                    }
                }
            }
            ans++;

        }
    }
    return ans;
}


int main(){
    int N = 8;
    std::vector<std::vector<char>> graph(N, std::vector<char> (N));
    std::ifstream fin("INPUT.TXT");
    std::ofstream fout("OUTPUT.TXT"); 
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            fin >> graph[i][j];
        }
    }

    int ans = DFS(graph);

    fout << ans;


    fin.close();
    fout.close();
    return 0;
}