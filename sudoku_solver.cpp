#include<iostream>
#include<vector>
using namespace std;

bool is_valid(vector<vector<int>> matrix,int x,int y,int z){
    for(int i=0;i<9;i++){
        if(matrix[y][i]==z || matrix[i][x]==z){
            return false;
        }
    }

    int startRow = y - y % 3;
    int startCol = x - x % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (matrix[i + startRow][j + startCol] == z) {
                return false;
            }
        }
    }
    return true;
}

bool sudoku_helper(vector<vector<int>> &matrix){
    bool numbers[9];
    for(int y=0;y<9;y++){
        for(int x=0;x<9;x++){
            for(int i=0;i<9;i++){
                numbers[i] =false;
            }
            if(matrix[y][x]==0){
                for(int i=0;i<9;i++){
                    if(matrix[y][i]!=0){
                        numbers[matrix[y][i]-1] = true;
                    }
                    if(matrix[i][x]!=0){
                        numbers[matrix[i][x]-1] = true;
                    }
                }
                int startRow = y - y % 3;
                int startCol = x - x % 3;
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        if (matrix[i + startRow][j + startCol]!=0){
                            numbers[matrix[i + startRow][j + startCol]-1] = true;
                        }
                    }
                }
                    for(int i=0;i<9;i++){
                        if(numbers[i]==false && is_valid(matrix,x,y,i+1)){
                            matrix[y][x] = i+1;
                            if(sudoku_helper(matrix)){
                                return true;
                            }
                            matrix[y][x] = 0;
                            
                        }
                    }
                
                return false;                 
            }
        }
    }
    return true;
}

int main(){
    vector<vector<int>> matrix(9, vector<int>(9, 0));
    for(int i=0;i<9;i++){
        for(int a=0;a<9;a++){
            cin>>matrix[i][a];
        }
    }
    if(sudoku_helper(matrix)){
        cout<<endl;
        cout<<"The solution is:"<<endl;
        for(int i=0;i<9;i++){
        for(int a=0;a<9;a++){
            cout<<matrix[i][a]<<" ";
        }
        cout<<endl;
    }
    }
    else{
        cout<<endl;
        cout<<"No solutions.";
    }
    return 0;
}