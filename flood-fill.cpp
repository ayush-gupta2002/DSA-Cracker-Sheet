class Solution {
public:

    void bfs(int sr,int sc,vector<vector<int> >&image,int color){
        int n = image.size();
        int m = image[0].size();
        vector<vector<int>> visited(n,vector<int> (m,0));
        int startingColor = image[sr][sc];

        queue<pair<int,int>> q;
        q.push(make_pair(sr,sc));
        visited[sr][sc] = 1;

        while(!q.empty()){
            pair<int,int> topPair = q.front();
            int row = topPair.first;
            int col = topPair.second;
            image[row][col] = color;
            q.pop();

            if(row > 0){
                int above = image[row-1][col];
                if(above == startingColor && visited[row-1][col] == 0){
                    q.push(make_pair(row-1,col));
                    visited[row-1][col] = 1;
                }
            }
            if(row < image.size()-1){
                int below = image[row+1][col];
                if(below == startingColor && visited[row+1][col] == 0){
                    q.push(make_pair(row+1,col));
                    visited[row+1][col] = 1;
                }
            }
            if(col < image[0].size()-1){
                int right = image[row][col+1];
                if(right == startingColor && visited[row][col+1] == 0){
                    q.push(make_pair(row,col+1));
                    visited[row][col+1] = 1;
                }
            }
            if(col > 0){
                int left = image[row][col-1];
                if(left == startingColor && visited[row][col-1] == 0){
                    q.push(make_pair(row,col-1));
                    visited[row][col-1] =1 ;
                }
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();

        bfs(sr,sc,image,color);
        return image;
        
    }
};
