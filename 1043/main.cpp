#include <bits/stdc++.h>
#include <fstream>



int BFS(std::vector<std::vector<char>> &graph){
    int N = graph.size();
    int M = graph[0].size();
    std::vector<std::vector<int>> used (N, std::vector<int> (M, 0));
    int x, y;
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    int ans = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            std::queue<std::pair<int, int>> q;
            if(used[i][j] == 1 || graph[i][j] == '.'){
                continue;
            }
            q.push({i, j});
            used[i][j] = 1;
            while(!q.empty()){
                x = q.front().second;
                y = q.front().first;
                q.pop();
                for(int k = 0; k < 4; k++){
                    int x1 = x + dx[k];
                    int y1 = y + dy[k];
                    if(x1 >= 0 && x1 < M && y1 >= 0 && y1 < N){
                        if(used[y1][x1] == 0 && graph[y1][x1] == '*'){
                            q.push({y1, x1});
                            used[y1][x1] = 1;
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
    int N, M;
    std::ifstream fin("INPUT.TXT");
    std::ofstream fout("OUTPUT.TXT");
    fin >> N >> M;
    std::vector<std::vector<char>> graph(N, std::vector<char> (M));

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            fin >> graph[i][j];
        }
    }


    int res = BFS(graph);

    fout << res;


    fin.close();
    fout.close();
    return 0;
}