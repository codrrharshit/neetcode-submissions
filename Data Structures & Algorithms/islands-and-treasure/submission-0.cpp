class Solution {
public:
    int m,n;
    vector<vector<int>>directions={{1,0},{0,1},{-1,0},{0,-1}};
    void islandsAndTreasure(vector<vector<int>>& grid) {
         m = grid.size();
        n = grid[0].size();
        queue<pair<int,int>> q;

    // Push all treasures into the queue initially
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 0) {
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()){
        auto [x,y] = q.front();
        q.pop();

        for(auto &dir: directions){
            int nx = x + dir[0];
            int ny = y + dir[1];

            if(nx < 0 || nx >= m || ny < 0 || ny >= n || grid[nx][ny] == -1) continue;

            if(grid[nx][ny] == 2147483647){
                // Update distance
                grid[nx][ny] = grid[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
        
    }
};
