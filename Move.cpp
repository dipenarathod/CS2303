#include <stdio.h>
#include <stdbool.h>
using namespace std;

int main(){
char board[8][8] ={
    {'-','-','-','-','-','-','-,','-'},
    {'-','-','-','-','-','-','-,','-'},
    {'-','-','-','-','-','-','-,','-'},
    {'-','-','-','-','-','-','-,','-'},
    {'-','-','-','-','-','-','-,','-'},
    {'-','-','-','-','-','-','-,','-'},
    {'-','-','-','-','-','-','r,','-'},
    {'-','-','-','-','-','b','-,','-'}
    };

int right = 0, left = 0, up =0;
//Move Piece
for (int i = 0; i < 8; i++)
{
    for(int j = 0; j < 8; j++){
        if(board[i][i] == 'b'){
            up = i-1;
            right = i +1; left = i-1;
            if (up >= 0)
            {
                if(right >= 1 && right < 8){
                    if (board[up][right])
                    {
                        cout << "There is a piece to the right and above"
                    } 
                }
                if (left >=0 && left <= 7)
                {
                    if (board[up][left] == 'r')
                    {
                        cout <<"Piece left and up"
                    }
                    
                }
                
            }
            
            
        }
    }
}
}

