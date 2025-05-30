class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>vis(n,vector<int>(m,0));
        //initializing the queue
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                    vis[i][j] = 2;
                }
                
            }
        }
        int tm=0;
        vector<int>drow = {-1,0,1,0};
        vector<int>dcol = {0,1,0,-1};
        while(!q.empty()){
            //extract the lowest item from the queue
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            //update time(cant do t++,cuz multiple oranges working simultaneously)
            tm = max(tm,t);
            q.pop();
            for(int i=0;i<4;i++){
                //checking all 4 directions for positions (row-1,col),.....
                int nrow = r + drow[i];
                int ncol = c+dcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol] != 2 && grid[nrow][ncol] == 1){
                    q.push({{nrow,ncol},t+1});
                    vis[nrow][ncol]=2;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]!=2 && grid[i][j] == 1)return -1;
            }
        }
        return tm;

    }
};
