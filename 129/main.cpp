#include <bits/stdc++.h>
#include <fstream>

//std::vector<std::vector<int>>

std::vector<std::vector<int>> BFS(std::vector<std::vector<int>> &graph){
    int N = graph.size(), M = graph[0].size();
    std::vector<std::vector<int>> ans (N, std::vector<int> (M, 0));
    std::vector<std::vector<int>> used (N, std::vector<int> (M, 0));
    std::vector<std::vector<int>> dist (N, std::vector<int> (M, 0));
    int x, y;
    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            std::queue<std::pair<int, int>> q; 
            if(used[i][j]){
                continue;
            }
            q.push({i, j});
            used[i][j] = 1;
            int count = 1;
            dist[i][j] = 0;
            while(!q.empty()){
                y = q.front().first;
                x = q.front().second;
                q.pop();
                std::cout << x << y << "    " << dist[y][x] << "\n";
                for(int k = 0; k < 4; k++){
                    int x1 = x + dx[k];
                    int y1 = y + dy[k];
                    if(x1 >= 0 && x1 < M && y1 >= 0 && y1 < N){
                        if(used[y1][x1] == 0){
                            q.push({y1, x1});
                            used[y1][x1] = 1;
                            dist[y1][x1] = dist[y][x] + 1;
                        }
                    }
                }
            }
        }
    }
    return dist;
}


std::vector<std::vector<int>> BFS2(std::vector<std::vector<int>> &graph){
    int N = graph.size(), M = graph[0].size();
    
    std::vector<std::vector<int>> dist(N, std::vector<int> (M, 0));
    
    int x, y;
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            std::vector<std::vector<int>> used(N, std::vector<int> (M, 0));
            std::queue<std::pair<int, int>> q;
            q.push({i, j});
            used[i][j] = 1;
            std::vector<std::vector<int>> d(N, std::vector<int> (M, 0));
            d[i][j] = 0;
            bool exit = false;
            if(graph[i][j] == 1){
                dist[i][j] = 0;
                continue;
            }
            while(!q.empty()){
                int x = q.front().second;
                int y = q.front().first;
                q.pop();
                for(int k = 0; k < 4; k++){
                    int x1 = x + dx[k];
                    int y1 = y + dy[k];
                    if(x1 >= 0 && x1 < M && y1 >= 0 && y1 < N){
                        if(!used[y1][x1]){
                            used[y1][x1] = 1;
                            q.push({y1, x1});
                            d[y1][x1] = d[y][x] + 1;
                            if(graph[y1][x1] == 1){
                                dist[i][j] = d[y1][x1];
                                exit = true;
                            }
                        }

                    }

                }
                if(exit){
                    break;
                }
            }
        }
    }
    return dist;
}


std::vector<std::vector<int>> BFS3(std::vector<std::vector<int>> &graph){
    int N = graph.size(), M = graph[0].size();
    std::queue<std::pair<int, int>> q;
    std::vector<std::vector<int>> used (N, std::vector<int> (M, 0));
    std::vector<std::vector<int>> dist (N, std::vector<int> (M, -1));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(graph[i][j] == 1){
                q.push({i, j});
                used[i][j] = 1;
                dist[i][j] = 0;
            }
        }
    }
    int x, y;
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    while(!q.empty()){
        x = q.front().second;
        y = q.front().first;
        q.pop();

        for(int i = 0; i < 4; i++){
            int x1 = x + dx[i];
            int y1 = y + dy[i];
            if(x1 >= 0 && x1 < M && y1 >= 0 && y1 < N){
                if(used[y1][x1] == 0){
                    q.push({y1, x1});
                    used[y1][x1] = 1;
                    if(dist[y1][x1] == -1){
                        dist[y1][x1] = dist[y][x] + 1; 
                    }
                }
            }
        }
    }
    return dist;
}

int main(){
    int N, M;
    std::ifstream fin("INPUT.TXT");
    std::ofstream fout("OUTPUT.TXT");
    fin >> N >> M;
    std::vector<std::vector<int>> graph(N, std::vector<int> (M, 0));

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            fin >> graph[i][j];
        }
    }



    std::vector<std::vector<int>> res = BFS3(graph);

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            fout << res[i][j] << " ";
        }
        fout << "\n";
    }





    fin.close();
    fout.close();
    return 0;
}