//
//  main.cpp
//  leetCode_WordSearch
//
//  Created by Adi Bangun on 21/06/2015.
//  Copyright (c) 2015 Adi Bangun. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

bool existUtil(vector<vector<char>>&mBoard, string mWord,int mRow,int mCol,int mWordPos){
    if(mBoard[mRow][mCol]!=mWord.at(mWordPos) || mBoard[mRow][mCol]=='#')
        return false;
    if(mWordPos == mWord.length()-1)
        return true;
    char c = mBoard[mRow][mCol];
    mBoard[mRow][mCol] = '#';
    if((mRow > 0 && existUtil(mBoard,mWord,mRow-1,mCol,mWordPos+1)) || (mRow < mBoard.size()-1 && existUtil(mBoard,mWord,mRow+1,mCol,mWordPos+1)) || (mCol > 0 && existUtil(mBoard,mWord,mRow,mCol-1,mWordPos+1)) || (mCol < mBoard[0].size()-1 && existUtil(mBoard,mWord,mRow,mCol+1,mWordPos+1))){
        mBoard[mRow][mCol] = c;
        return true;
    }
    mBoard[mRow][mCol] = c;
    return false;
}

bool exist(vector<vector<char>>&board, string word){
    int rows = static_cast<int>(board.size()-1);
    int cols = static_cast<int>(board[0].size());
    for(int row =0;row<rows;row++){
        for(int col = 0;col<cols;col++)
            if(existUtil(board,word,row,col,0))
                return true;
    }
    return false;
    
}
int main(int argc, const char * argv[]) {
    // insert code here...
    char c;
    vector<vector<char>> board(4,vector<char>(4));
    for (int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            cin >> c;
            (board[i])[j] = c;
        }
    }
    cout << (int)board.size() << endl;
    cout << (int)board[0].size() << endl;
    string word;
    cout << "insert a word to find: ";
    cin >> word;
    if(exist(board,word))
        cout << "found" << endl;
    else
        cout << "the word does not exist" << endl;
    return 0;
}
