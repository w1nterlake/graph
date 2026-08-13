#include <bits/stdc++.h>
#include <fstream>


std::vector<int> dj(std::vector<std::vector<std::pair<int, int>>> &graph, int start){
    int N = graph.size();
    std::vector<int> dist(N, -1);
    std::vector<int> used(N, 0);
    dist[start] = 0;
    for(int i = 0; i < N; i++){
        int v = -1;
        for(int j = 0; j < N; j++){
            if(used[j] == 0 && dist[j] != -1 && (v == -1 || dist[v] > dist[j])){
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


std::vector<int> dj2(std::vector<std::vector<std::pair<int, int>>> &graph, int start){
    int N = graph.size();;
    std::set<std::pair<int, int>> st;
    std::vector<int> used(N, 0);
    std::vector<int> dist(N, -1);
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
            }
        }
    }
    return dist;
}


int main(){
    int N, M, S;
    std::ifstream fin("INPUT.TXT");
    std::ofstream fout("OUTPUT.TXT");
    fin >> N >> M >> S;
    std::vector<std::vector<std::pair<int, int>>> graph (N);
    int a, b, z;
    for(int i = 0; i < M; i++){
        fin >> a >> b >> z;
        graph[a].push_back({b, z});
        graph[b].push_back({a, z});
    }
    std::vector<int> res = dj2(graph, S);
    for(int i = 0; i < res.size(); i++){
if (res[i] == -1) {
    fout << 2009000999 << " ";
}
else {
    fout << res[i] << " ";
}
    }





    fin.close();
    fout.close();
    return 0;
}