#include <bits/stdc++.h>
#include <fstream>

bool DFS(std::vector<std::vector<int>> &graph, int K){
    std::stack<int> st;
    
    int size = graph.size() - 1;
    std::vector<int> used(size + 1, 0);
    int start = K;
    int count = 0;
    used[start] = 1;
    st.push(start);
    while(!st.empty()){
        int vertex = st.top();
        st.pop();
        for(int i = 0; i < graph[vertex].size(); i++){
            if(used[graph[vertex][i]] == 0){
                used[graph[vertex][i]] = 1;
                count++;
                st.push(graph[vertex][i]);
            }
        }
    }
    if(count == size - 1){
        return true;
    }
    return false;
}


int main(){
    int N, K;
    std::ifstream fin("INPUT.TXT");
    std::ofstream fout("OUTPUT.TXT");
    fin >> N >> K;
    std::vector<std::vector<int>> graph(N + 1);
    int a, b;
    while(1){
        fin >> a;
        if(a == 0){
            break;
        }
        fin >> b;
        graph[a].push_back(b);
    }

    if(DFS(graph, K)){
        fout << "Yes";
    }
    else{
        fout << "No";
    }





    fin.close();
    fout.close();
    return 0;
}


