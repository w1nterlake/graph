#include <bits/stdc++.h>
#include <fstream>


std::vector<int> BFS(std::vector<std::vector<int>> &graph, int start){
    std::queue<int> q;
    int size = graph.size() - 1;
    std::vector<int> dist(size + 1, -1);
    q.push(start);
    dist[start] = 0;

    while(!q.empty()){
        int vertex = q.front();
        q.pop();
        //std::cout << vertex << " ";
        for(int child: graph[vertex]){
            if(dist[child] == -1){
                q.push(child);
                dist[child] = dist[vertex] + 1;
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
    std::vector<std::vector<int>> graph(N + 1);
    int a, b;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            fin >> a;
            if(a){
                graph[i + 1].push_back(j + 1);
            }
        }
    }
    fin >> a >> b;


    std::vector<int> dist = BFS(graph, a);
    fout << dist[b];





    fin.close();
    fout.close();
    return 0;
}