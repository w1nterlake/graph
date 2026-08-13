#include <bits/stdc++.h>
#include <fstream>


std::vector<int> dj(std::vector<std::vector<std::pair<int, int>>> &graph, int start){
    int size = graph.size() - 1;
    std::vector<int> dist (size + 1, -1);
    std::vector<int> used (size + 1, 0);
    dist[start] = 0;
    for(int i = 1; i < size + 1; i++){
        int vertex = -1;
        for(int j = 1; j < size + 1; j++){
            if(!used[j] && dist[j] != -1 && (vertex == -1 || dist[j] < dist[vertex])){
                vertex = j; 
            }
        }

        if(vertex == -1){
            break;
        }

        used[vertex] = 1;

        for(std::pair<int, int> par: graph[vertex]){
            if(dist[par.first] > dist[vertex] + par.second || dist[par.first] == -1){
                dist[par.first] = dist[vertex] + par.second;  
            }
        }

    }

    return dist;
}


std::vector<int> dj2(std::vector<std::vector<std::pair<int, int>>> &graph, int start){
    int N = graph.size() - 1;
    std::set<std::pair<int, int>> st;
    std::vector<int> dist (N + 1, -1);
    std::vector<int> used (N + 1, 0);
    dist[start] = 0;
    st.insert({0, start});
    while(!st.empty()){
        int vertex = st.begin()->second;
        st.erase(st.begin());


        
        for(std::pair<int, int> par: graph[vertex]){
            int to = par.first;
            int w = par.second;
            if(dist[to] == -1 || dist[to] > dist[vertex] + w){
                if(dist[to] != -1){
                    st.erase({dist[to], to});
                }
                
                dist[to] = dist[vertex] + w;
                st.insert({dist[to], to});
            }
        }
    }
    return dist;
}

std::vector<int> dj3(std::vector<std::vector<std::pair<int, int>>> &graph, int start){
    int N = graph.size() - 1;
    std::vector<int> dist(N + 1, -1);
    std::vector<int> used(N + 1, 0);
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> q;
    dist[start] = 0;
    q.push({0, start});
    


}



int main(){
    int N, S, F;
    std::ifstream fin("INPUT.TXT");
    std::ofstream fout("OUTPUT.TXT");
    fin >> N >> S >> F;
    std::vector<std::vector<std::pair<int, int>>> graph (N + 1);
    int a;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            fin >> a;
            if(i != j && a != -1){
                graph[i + 1].push_back(std::make_pair(j + 1, a));
            }
        }
    }

    std::vector<int> res = dj2(graph, S);
    fout << res[F];



    fin.close();
    fout.close();
    return 0;
}