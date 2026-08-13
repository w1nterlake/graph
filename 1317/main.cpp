#include <bits/stdc++.h>
#include <fstream>





int DFS(std::vector<std::vector<char>> &graph){
    int N = graph.size();
    int M = graph[0].size();
    static std::vector<std::vector<int>> used(N, std::vector<int> (M, 0));
    int x, y;
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    int count = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            std::stack<std::pair<int, int>> st;
            if(used[i][j] == 1 || graph[i][j] == '.'){
                continue;
            }

            st.push({i, j});

            while(!st.empty()){
                x = st.top().first;
                y = st.top().second;
                st.pop();
                used[x][y] = 1;

                for(int i = 0; i < 4; i++){
                    int x1 = x + dx[i];
                    int y1 = y + dy[i];
                    if(x1 >= 0 && x1 < N && y1 >= 0 && y1 < M){
                        if(used[x1][y1] == 0 && graph[x1][y1] == '#'){
                            st.push({x1, y1});
                        }
                    }
                }
            }
            count++;
        }
    }
    return count;
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

    int res = DFS(graph);
    fout << res;


    fin.close();
    fout.close();
    return 0;
}