#include <iostream>
#include<vector>
using namespace std;
void printboard(const vector<vector<char> >& board){
    for (int i=0;i<3;++i){
        for (int j=0;j<3;++j){
            cout<< board[i][j];
            if(j<2)cout<< "  |  ";
        }
cout<< endl;
if(i<2 )cout<<"----------"<<endl;
    }
}
bool checkwin(const vector<vector<char> >& board, char player){
    for (int i=0;i<3;++i){
        if (board[i][0]==player && board[i][1]==player && board[i][2]==player)return true;
        if (board[0][i]==player && board[1][i]==player && board[2][i]==player)return true;

    }
    if (board[0][0] ==player && board[1][1]==player && board[2][2]==player)return true;
    if (board[0][2] ==player && board[1][1]==player && board[2][0]==player)return true;
return false;
}
bool checkdraw(const vector<vector<char> >& board)
{
    for (int i =0;i<3;++i){
        for (int j=0;j<3;++j)
        {
            if (board[i][j]==' ')return false;
        }
    }
    return true;
}
int main(){
    char opt;
    do{
        vector<vector<char> >board(3, vector<char>(3,' '));
        char currentplayer='X';
        bool gamewon=false;
        bool gamedraw=false;

        system("CLS");

        while(!gamewon &&!gamedraw){
            cout<<"\n CURRENT BOARD\n"<<endl;
            printboard(board);
            cout<<"PLAYER"<<currentplayer<<endl;
            cout<<"ENTER YOUR MOVE (ROW AND COLUMN)"<<endl;
            int row,col;
            cin>>row>>col;
            if (row <1||row >3||col<1||col>3||board[row-1][col-1]!=' ')
            {

                cout<<"invalid move"<<endl;
                continue;
            }
            board[row-1][col-1]=currentplayer;
if (checkwin(board,currentplayer)){
    cout<<currentplayer<<"wins!!"<<endl;
    gamewon=true;
}
else if(checkdraw(board)){
    cout<<"IT'S A DRAW"<<endl;
    gamedraw=true;

        }
        currentplayer=(currentplayer == 'X')?'O':'X';
        }
        cout<<"thank you"<<endl;
        cout<<"want to play again?(Y/N)"<<endl;
        cin>>opt;
    }while(opt =='Y' ||opt=='y');
    return 0;

            }

