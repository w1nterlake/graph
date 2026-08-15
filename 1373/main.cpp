#include <bits/stdc++.h>
#include <fstream>



std::vector<std::vector<int>> floyd(std::vector<std::vector<int>> &graph){
    int N = graph.size();
    std::vector<std::vector<int>> dist(N, std::vector<int> (N, INT_MAX));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(graph[i][j] != -1){
                dist[i][j] = graph[i][j];
            }
        }
    }
    for(int k = 0; k < N; k++){
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                if(dist[i][k] == INT_MAX || dist[k][j] == INT_MAX){
                    continue;
                }

                if(dist[i][j] > dist[i][k] + dist[k][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
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
    std::vector<std::vector<int>> graph (N, std::vector<int> (N, -1));
    int a, b, w;
    for(int i = 0; i < M; i++){
        fin >> a >> b >> w;
        graph[a - 1][b - 1] = w;
        graph[b - 1][a - 1] = w;
    }
    for(int i = 0; i < N; i++){
        graph[i][i] = 0;
    }
    std::vector<std::vector<int>> dist = floyd(graph);
    int max = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(max < dist[i][j] && dist[i][j] != INT_MAX){
                max = dist[i][j];
            }
        }
    }

    fout << max;

    fin.close();
    fout.close();
    return 0;
}