#include <bits/stdc++.h>
#include <fstream>


std::vector<int> dj(std::vector<std::vector<std::pair<int, int>>> &graph, int start){
    int N = graph.size() - 1;
    std::vector<int> dist (N + 1, -1);
    std::vector<int> used (N + 1, 0);
    dist[start] = 0;
    for(int i = 1; i < N + 1; i++){
        int v = -1;
        for(int j = 1; j < N + 1; j++){
            if(used[j] == 0 && dist[j] != -1 && (v == -1 || dist[j] < dist[v])){
                v = j;
            }
        }

        if(v == -1){
            break;
        }

        used[v] = 1;

        for(std::pair<int, int> par: graph[v]){
            int to = par.first;
            int w = par.second;
            if(dist[to] == -1 || dist[to] > dist[v] + w){
                dist[to] = dist[v] + w;
            }
        }
    }
    return dist;
}





int main(){
    int N;
    std::ifstream fin("INPUT.TXT");
    std::ofstream fout("OUTPUT.TXT");
    fin >> N;
    std::vector<int> price(N, 0);
    for(int i = 0; i < N; i++){
        fin >> price[i];
    }
    int M = 0;
    fin >> M;
    std::vector<std::vector<std::pair<int, int>>> graph(N + 1);
    int a, b;
    for(int i = 0; i < M; i++){
        fin >> a >> b;
        graph[a].push_back({b, price[a - 1]});
        graph[b].push_back({a, price[b - 1]});
    }

    std::vector<int> dist = dj(graph, 1);

    fout << dist[N];





    fin.close();
    fout.close();
    return 0;
}