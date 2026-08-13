#include <bits/stdc++.h>
#include <fstream>


std::vector<std::vector<int>> DFS(std::vector<std::vector<int>> &graph){
    int size = graph.size() - 1;
    std::vector<int> used (size + 1);
    std::stack<int> st;
    std::vector<std::vector<int>> comp;
    int count = 0;
    for(int start = 1; start <= size; start++){
        if(used[start] != 0){
            continue;
        }
        st.push(start);
        used[start] = 1;
        count++;
        comp.resize(count);
        comp[count - 1].push_back(start);
        while(!st.empty()){
            int vertex = st.top();
            st.pop();
            for(int child: graph[vertex]){
                if(used[child] == 0){
                    used[child] = 1;
                    st.push(child);
                    comp[count - 1].push_back(child);
                }
            }
        }
    }
    return comp;
}


int main(){
    int N, M;
    std::ifstream fin("INPUT.TXT");
    std::ofstream fout("OUTPUT.TXT");
    fin >> N >> M;
    std::vector<std::vector<int>> graph(N + 1);
    int a, b;
    for(int i = 0; i < M; i++){
        fin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    std::vector<std::vector<int>> res = DFS(graph);
    fout << res.size() << "\n";
    for(int i = 0; i < res.size(); i++){
        fout << res[i].size() << "\n";
        for(int k: res[i]){
            fout << k << " ";
        }
        fout << "\n";
    }


    fin.close();
    fout.close();
    return 0;
}