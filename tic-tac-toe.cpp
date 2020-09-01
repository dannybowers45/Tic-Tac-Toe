//Write a tic tac toe program
//Players enter their moves by entering the position number
//After each move program displays game
#include <string>
#include <iostream>
#include <cmath>
using namespace std;
void printGame(char cB[3][3]); //,int iB[3][3]
void input1(char cB[3][3], int iB[3][3], bool &k);
void input2(char cB[3][3], int iB[3][3], bool &k);
void bot(char cB[3][3], int iB[3][3], bool &k);
bool winner(int iB[3][3]);
void single (char cB[3][3], int iB[3][3], bool &k);
void multi (char cB[3][3], int iB[3][3], bool &k);

int main(){
  int gameMode;
  cout<< "Type '1' for Single Player '2' for Multi-Player"<<endl;
  cin>>gameMode;

int a=0;
char numbers [9] = {'1','2','3','4','5','6','7','8','9'}; //To fill cB
char cB[3][3]; //CHAR BOARD
int iB[3][3];  //INT BOARD (To track who wins)

for (int x=0; x<3; x++){
  for(int y=0; y<3; y++){
    cB[x][y]=numbers[a]; //Filling character array
    iB[x][y]=0; //filling int array with 0s
    a++;
  }
}
printGame(cB); //iB
bool k;
k=winner(iB);
if (gameMode==1)
  multi(cB, iB, k);

else{
  single(cB, iB, k);
}

return 0;
}

void single(char cB[3][3], int iB[3][3], bool &k){
while(k==false){ //(j==false)&&
  if (k==false)
  input1(cB,iB,k); //player 1
  if (k==false)
  input2(cB,iB,k); //player 2
}
}
void multi (char cB[3][3], int iB[3][3], bool &k){
  while(k==false){ //(j==false)&&
    if (k==false)
    input1(cB,iB,k); //player 1
    if (k==false)
    bot(cB,iB,k); //player 2

}
}

void printGame(char cB[3][3]){ //, int iB[3][3]
cout<<endl;
  for (int x=0; x<3; x++){
    if (x>0)
      cout<<endl;
    for(int y=0; y<3; y++){
      cout<<cB[x][y]<<" ";
    }
}
cout<<endl;
cout<<endl;
// for (int xx=0; xx<3; xx++){
//   if (xx>0)
//     cout<<endl;
//   for(int yy=0; yy<3; yy++){
//     cout<<iB[xx][yy]<<" ";
//   }
// }

}

void input1(char cB[3][3], int iB[3][3], bool &k){
char p1;
int u=0;
while(u==0){
cout<<"Player 1 input location of 'X'"<<endl;
cin>>p1;
for (int x=0; x<3; x++){
  for(int y=0; y<3; y++){   //could optimize with hashmaps
    if (cB[x][y]==p1){
      cB[x][y]='X';
      iB[x][y]=5;
      printGame(cB);//iB
      k=winner(iB);
      u++;
    }
  }
}
}
}

void input2(char cB[3][3], int iB[3][3], bool &k){
char p2;
int u=0;
while(u==0){
cout<<"Player 2 input location of 'O'"<<endl;
cin>>p2;
for (int x=0; x<3; x++){
  for(int y=0; y<3; y++){
    if (cB[x][y]==p2){
      cB[x][y]='O';
      iB[x][y]=41;
      printGame(cB);//iB
      k=winner(iB);
      u++;
    }
  }
}
}
}
void bot(char cB[3][3], int iB[3][3], bool &k){
  char inpc;

  int a=0,b=0,c=0,d=0,e=0,f=0,g=0,h=0;
  for (int x=0; x<3; x++){
      a+=iB[x][0];//All the columns
      b+=iB[x][1];
      c+=iB[x][2];
      d+=iB[0][x];//All the rows
      e+=iB[1][x];
      f+=iB[2][x];
      }
      g=iB[0][0]+iB[1][1]+iB[2][2];//Diagonals
      h=iB[0][2]+iB[1][1]+iB[2][0];

      if ((a+b+c)<51){
        if (iB[0][0]==0)
        inpc='1';
        else if (iB[0][2]==0)
        inpc='3';
        else if (iB[2][0]==0)
        inpc='7';
        else if (iB[2][2]==0)
        inpc='9';
      }
      else if (a==10 || a== 82){
        for(int c=0; c<3; c++){
          if (iB[c][0]==0)
            inpc=(char)(c*3+1+'0');
        }
      }
      else if (b==10 || b==82){
        for(int c=0; c<3; c++){
          if (iB[c][1]==0)
            inpc=(char)(c*3+2+'0');
        }
      }
      else if (c==10 || c==82){
        for(int c=0; c<3; c++){
          if (iB[c][2]==0)
            inpc=(char)(c*3+3+'0');
        }
      }
      else if (d==10|| d==82){
        for(int c=0; c<3; c++){
          if (iB[0][c]==0)
            inpc=(char)(c+1+'0');
        }
      }
      else if (e==10|| e==82){
        for(int c=0; c<3; c++){
          if (iB[1][c]==0)
            inpc=(char)(c+4+'0');
        }
      }
      else if (f==10|| f==82){
        for(int c=0; c<3; c++){
          if (iB[2][c]==0)
            inpc=(char)(c+7+'0');
        }
      }
      else if (g==10|| g==82){
        for(int c=0; c<3; c++){
          if (iB[c][c]==0) //1,5,9
            inpc=(char)(c*4+1+'0'); //Diagonals
        }
      }
      else if (h==10|| h==82){
        int q=3; //
        for(int c=0; c<3; c++){
          q--;
          if (iB[c][q]==0) //3,5,7
            inpc=(char)(c*2+3+'0'); //Diagonals
        }
      }
      else{
        char rando = (char)(rand() % 10 +'0');
        for (int a=0; a<3; a++){
          for(int b=0; b<3; b++){
            if (cB[a][b]==rando){
              inpc=rando;
            }
          }
      }
}
      for (int a=0; a<3; a++){
        for(int b=0; b<3; b++){
          if (cB[a][b]==inpc){
            cB[a][b]='O';
            iB[a][b]=41;
            printGame(cB);//iB
            k=winner(iB);
}
}
}
}
bool winner(int iB[3][3]){
int a=0,b=0,c=0,d=0,e=0,f=0,g=0,h=0;
for (int x=0; x<3; x++){
    a+=iB[x][0];//All the rows
    b+=iB[x][1];
    c+=iB[x][2];
    d+=iB[0][x];//All the columns
    e+=iB[1][x];
    f+=iB[2][x];
    }
    g=iB[0][0]+iB[1][1]+iB[2][2];//Diagonals
    h=iB[0][2]+iB[1][1]+iB[2][0];
    if((a==15)||(b==15)||(c==15)||(d==15)||(e==15)||(f==15)||(g==15)||(h==15)){
      cout<<"Player 1 Wins! "<<endl;
      return true;
    }
    else if((a==123)||(b==123)||(c==123)||(d==123)||(e==123)||(f==123)||(g==123)||(h==123)){
      cout<<"Player 2 Wins! "<<endl;
      return true;
    }
    else if((a+b+c)==189){ //5*5+40*4
      cout<<"Cat's Game! "<<endl;
      return true;
    }
    else{
      return false;
    }
}
