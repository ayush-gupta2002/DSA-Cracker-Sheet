#include <bits/stdc++.h>

vector<int> findCommonElements(vector<vector<int>> &mat)
{
    unordered_map<int,int> elements;
    int rows = mat.size();
    int cols = mat[0].size();
    vector<int> res;
    
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(i==0){
                elements[mat[i][j]] = 0;
            }
            else{
                if(elements.find(mat[i][j])!=elements.end() && elements[mat[i][j]]==i-1){
                    elements[mat[i][j]] = i;
                }
            }
        }
    }
    for(pair<int,int> i:elements){
        if(i.second==rows-1){
            res.push_back(i.first);
        }
    }
    return res;
    
    return res;
}

