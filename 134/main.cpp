#include <bits/stdc++.h>
#include <fstream>





std::vector<int> dj1(std::vector<std::vector<std::vector<int>>> &graph, int start){
    int N = graph.size() - 1;
    std::vector<int> used(N + 1, 0);
    std::vector<int> dist(N + 1, -1);
    dist[start] = 0;

    for(int i = 1; i <= N; i++){
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


        for(std::vector<int> trip: graph[v]){
            int to = trip[0];
            int t1 = trip[1];
            int l1 = trip[2];
            if(dist[v] > t1){
                continue;
            }

            if(dist[to] == -1 || dist[to] > l1){
                dist[to] = l1;
            }
        }
    }
    return dist;
}

std::vector<int> dj2(std::vector<std::vector<std::vector<int>>> &graph, int start){
    int N = graph.size() - 1;
    std::vector<int> dist(N + 1, -1);
    std::vector<int> used(N + 1, 0);
    std::set<std::pair<int, int>> st;
    st.insert({0, start});
    dist[start] = 0;
    while(!st.empty()){
        int v = st.begin()->second;
        st.erase(st.begin());
        if(used[v] == 1){
            continue;
        }
        used[v] = 1;
        for(std::vector<int> trip: graph[v]){
            int to = trip[0];
            int t1 = trip[1];
            int l1 = trip[2];
            if(dist[v] > t1){
                continue;
            }
            if(dist[to] == -1 || dist[to] > l1){
                dist[to] = l1;
                st.insert({dist[to], to});
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
    int d, v;
    fin >> d >> v;

    int M;
    fin >> M;
    std::vector<std::vector<std::vector<int>>> graph (N + 1);
    int a, b, t, l;
    for(int i = 0; i < M; i++){
        fin >> a >> t >> b >> l;
        std::vector<int> tmp = {b, t, l};
        graph[a].push_back(tmp);
    }

    std::vector<int> dist = dj2(graph, d);

    fout << dist[v];



    fin.close();
    fout.close();
    return 0;
}