#include <bits/stdc++.h>
#include <fstream>




std::vector<std::vector<int>> BFS(int x, int y, int N){
    std::queue<std::pair<int, int>> q;
    std::vector<std::vector<int>> dist (N + 1, std::vector<int> (N + 1, -1));
    q.push(std::make_pair(x, y));
    int dx[] = {2, 1, -1, -2, -2, -1, 1, 2};
    int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
    dist[x][y] = 0;
    while(!q.empty()){
        int x1, y1;
        x1 = q.front().first;
        y1 = q.front().second;
        q.pop();
        int x2, y2;
        for(int i = 0; i < 8; i++){
            x2 = x1 + dx[i];
            y2 = y1 + dy[i];
            if(x2 >= 1 && x2 <= N && y2 >= 1 && y2 <= N && dist[x2][y2] == -1){
                q.push(std::make_pair(x2, y2));
                dist[x2][y2] = dist[x1][y1] + 1;
            }
        }
    }
    return dist;
}




int main(){
    int N;
    std::ifstream fin("INPUT.TXT");
    std::ofstream fout("OUTPUT.TXT");
    int x1, x2, y1, y2;
    fin >> N;
    fin >> x1 >> y1;
    fin >> x2 >> y2;
    std::vector<std::vector<int>> res = BFS(x1, y1, N);
    fout << res[x2][y2];





    fout.close();
    fin.close();
    return 0;
}