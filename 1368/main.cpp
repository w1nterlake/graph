#include <bits/stdc++.h>
#include <fstream>



std::vector<std::vector<int>> floyd(std::vector<std::vector<int>> &graph){
    int N = graph.size();
    std::vector<std::vector<int>> dist(N, std::vector<int> (N, 0));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(graph[i][j] == -1){
                dist[i][j] = INT_MAX;
            }
            else{
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
    int N, S, T;
    std::ifstream fin("INPUT.TXT");
    std::ofstream fout("OUTPUT.TXT");
    fin >> N >> S >> T;
    std::vector<std::vector<int>> graph (N, std::vector<int> (N, 0));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            fin >> graph[i][j];
        }
    }

    std::vector<std::vector<int>> res = floyd(graph);
if (res[S - 1][T - 1] == INT_MAX) {
    fout << -1;
}
else {
    fout << res[S - 1][T - 1];
}


    fin.close();
    fout.close();
    return 0;
}