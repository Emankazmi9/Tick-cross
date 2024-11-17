#include<iostream>
#include<cstdlib>
using namespace std;
char board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int choice;
char turn='x';
int row , column;
bool draw;
void functionone(){ 
  system("cls");

    cout<<"tick cross game"<<endl;
    cout<<"player1[x]"<<endl;
    cout<<"player2[0]"<<endl;
 
 cout<<"\t     |     |      \n";
 cout<<"\t"<<board[0][0]<<"    |\t"<< board[0][1]<<"  |\t"<<board[0][2]<<"\n";
 cout<<"\t_____|_____|______ \n";
 cout<<"\t     |     |      \n";
 cout<<"\t"<<board[1][0]<<"    |\t"<< board[1][1]<<"  |\t"<<board[1][2]<<"\n";
 cout<<"\t_____|_____|______ \n";
 cout<<"\t     |     |      \n";
 cout<<"\t"<<board[2][0]<<"    |\t"<< board[2][1]<<"  |\t"<<board[2][2]<<"\n";
 cout<<"\t     |     |      \n";
  
}
void player_turn(){
   if(turn=='x'){
  cout<<"\t\t\tplayer1[x] turn :"<<endl;
   }
  if(turn=='0'){
  cout<<"\t\t\tplayer2[0] turn :"<<endl;  
  }
  cin>>choice;
   switch (choice)
   {
   case 1:  row=0; column=0; break;
   case 2:  row=0; column=1; break;
   case 3:  row=0; column=2; break;
   case 4:  row=1; column=0; break;
   case 5:  row=1; column=1; break;
   case 6:  row=1; column=2; break;
   case 7:  row=2; column=0; break;
   case 8:  row=2; column=1; break;
   case 9:  row=2; column=2; break;
 default:
   cout<<"invalid entry"; 
    break;
   }
   if(turn=='x' && board[row][column]!='x' &&board[row][column]!='0')
   {
   board[row][column]='x';
   turn='0';
   }
   else if(turn=='0' && board[row][column]!='x'&&board[row][column]!='0')
   {
   board[row][column]='0';
   turn='x';
   }
  else 
  {
   cout<<"invalid entry \n please enter another number";
   player_turn();  
  } 

}
bool gameover(){
    for(int i=0;i<3;i++)
    if(board[0][i]==board[1][i]&&board[0][i]==board[2][i]||board[i][0]==board[i][1]&&board[i][0]==board[i][2])
     return false;
    
    if(board[0][0]==board[1][1]&&board[0][0]==board[2][2]||board[0][2]==board[1][1]&&board[0][2]==board[2][0]){
      return false;
    }
    for(int i=0;i<3;i++)
    for(int j=0;j<3;j++)
    if (board[i][j]!='x'&&board[i][j]!='0')
    
      return true;
    
    draw=true;
    return false; 

   
  }
int main(){
   while(gameover()){
   functionone();
   player_turn();
   functionone();
   }
   if(turn=='x'&& draw==false)
   cout<<"\t\t\tplayer 2[0] is winner game is over";
   
   else if(turn =='0'&& draw==false)
   cout<<"\t\t\tplayer 1[x] is winner game is over";
   
   else{
    cout<<"game is draw!!!!";
   }
 
    return 0;
}