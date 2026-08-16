#include <bits/stdc++.h>
#include <fstream>

#define MIN(a, b) ((a) > (b) ? (b) : (a))

std::vector<int> dj1(std::vector<std::vector<std::vector<int>>> &graph, int start, int mid){
    int N = graph.size() - 1;
    std::vector<int> used(N + 1, 0);
    std::vector<int> dist(N + 1, -1);
    dist[start] = 0;
    int minw = INT_MAX;
    for(int i = 1; i < N + 1; i++){
        int v = -1;
        for(int j = 1; j < N + 1; j++){
            if(used[j] == 0 && dist[j] != -1 && (v == -1 || dist[j] < dist[v])){
                v = j;
            }
        }

        if(v == -1){
            continue;
        }
        
        used[v] = 1;

        for(std::vector<int> trip: graph[v]){
            int to = trip[0];
            int time = trip[1];
            int weigth = trip[2];
            if((dist[to] == -1 || dist[to] > dist[v] + time) && (3000000 + 100 * mid) <= weigth){
                dist[to] = dist[v] + time;
            }
        }

    }
    return dist;
}

std::vector<int> dj2(std::vector<std::vector<std::vector<int>>> &graph, int start, int mid){
    int N = graph.size() - 1;
    std::vector<int> dist(N + 1, -1);
    std::set<std::pair<int, int>> st;
    std::vector<int> used(N + 1, 0);
    dist[start] = 0;
    st.insert({0,  start});
    while(!st.empty()){
        int v = st.begin()->second;
        st.erase(st.begin());
        if(used[v] == 1){
            continue;
        }
        used[v] = 1;

        for(std::vector<int> trip: graph[v]){
            int to = trip[0];
            int time = trip[1];
            int w = trip[2];
            if((dist[to] == -1 || dist[to] > dist[v] + time) && (3000000 + 100 * mid) <= w){
                dist[to] = dist[v] + time;
                st.insert({dist[to], to});
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
    std::vector<std::vector<std::vector<int>>> graph(N + 1);
    int a, b, t, w;
    for(int i = 0; i < M; i++){
        fin >> a >> b >> t >> w;
        graph[a].push_back({b, t, w});
        graph[b].push_back({a, t, w});
    }
    int l = 0;
    int r = 1e+7;
    int mid;
    int ans = 0;
    while(l <= r){
        mid = (l + r) / 2;
        std::vector<int> dist = dj2(graph, 1, mid);
        if(dist[N] == -1 || dist[N] > 1440){
            r = mid - 1;
        }
        else{
            l = mid + 1;
            ans = mid;
        }
    }

    fout << ans;




    fin.close();
    fout.close();
    return 0;
}