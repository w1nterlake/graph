#include<bits/stdc++.h>
#include <fstream>


std::vector<std::vector<int>> floyd(std::vector<std::vector<std::pair<int, int>>> &graph){
    int N = graph.size() - 1;
    std::vector<std::vector<int>> dist(N, std::vector<int> (N, INT_MAX));
    for(int i = 1; i < N + 1; i++){
        for(std::pair<int, int> par: graph[i]){
            dist[i - 1][par.first - 1] = par.second;
        }
    }
    for(int i = 0; i < N; i++){
        dist[i][i] = 0;
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
    std::vector<std::vector<std::pair<int, int>>> graph(N + 1);
    int a, b, w;
    for(int i = 0; i < M; i++){
        fin >> a >> b >> w;
        graph[a].push_back({b, w});
        graph[b].push_back({a, w});
    }

    std::vector<std::vector<int>> res = floyd(graph);
    std::vector<int> maxDist (N, 0);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(maxDist[i] < res[i][j]){
                maxDist[i] = res[i][j]; 
            }
        }
    }
    int max = maxDist[0];
    int indx = 0;

    for(int i = 0; i < N; i++){
        if(max > maxDist[i]){
            max = maxDist[i];
            indx = i;
        }
    }

    fout << indx + 1;

    fin.close();
    fout.close();
    return 0;
}