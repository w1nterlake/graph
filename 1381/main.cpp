#include <bits/stdc++.h>
#include <fstream>

std::pair<std::vector<int>, std::vector<int>> dj(std::vector<std::vector<std::pair<int, int>>> &graph, int start){
    int N = graph.size() - 1;
    std::vector<int> dist (N + 1, -1);
    std::vector<int> used (N + 1, 0);
    std::vector<int> parent (N + 1, -1);
    dist[start] = 0;
    for(int step = 1; step <= N; step++){
        int v = -1;
        for(int j = 1; j <= N; j++){
            if(!used[j] && dist[j] != -1 && (v == -1 || dist[j] < dist[v])){
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
                parent[to] = v;
            }
        }
    }
    return {dist, parent};
}

std::pair<std::vector<int>, std::vector<int>> dj2(std::vector<std::vector<std::pair<int, int>>> &graph, int start){
    int N = graph.size() - 1;
    std::set<std::pair<int, int>> st;
    std::vector<int> used (N + 1, 0);
    std::vector<int> dist (N + 1, -1);
    std::vector<int> parent (N + 1, -1);
    dist[start] = 0;
    st.insert({0, start});
    while(!st.empty()){
        int v = st.begin()->second;
        st.erase(st.begin()); 

        if(used[v] == 1){
            continue;
        }

        used[v] = 1;
        for(std::pair<int, int> par: graph[v]){
            int to = par.first;
            int w = par.second;
            if(dist[to] == -1 || dist[to] > dist[v] + w){
                dist[to] = dist[v] + w;
                st.insert({dist[to], to});
                parent[to] = v;
            }
        }
    }
    return {dist, parent};
}



int main(){
    int N, S, F;
    std::ifstream fin("INPUT.TXT");
    std::ofstream fout("OUTPUT.TXT");
    fin >> N >> S >> F;
    std::vector<std::vector<std::pair<int, int>>> graph(N + 1);
    int a;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            fin >> a;
            if(i != j && a != -1){
                graph[i + 1].push_back({j + 1, a});
            }
        }
    }

    std::pair<std::vector<int>, std::vector<int>> res = dj2(graph, S);

if (res.first[F] == -1) {
    fout << -1;
}
else {
    std::vector<int> path = res.second;
    std::vector<int> r;

    int v = F;

    while (v != -1) {
        r.push_back(v);
        v = path[v];
    }

    for (int i = r.size() - 1; i >= 0; i--) {
        fout << r[i] << " ";
    }
}

    fin.close();
    fout.close();
    return 0;
}