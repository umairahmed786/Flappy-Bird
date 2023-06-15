#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <iostream>
#include<windows.h>

using namespace std;
void gotoxy( short x, short y );


int ghostx=5;
int ghosty=5;
int pmanx=10;
int pmany=10;
int leftLimit=0;
int rightLimit=20;
string ghostDirection="Right";
void movePacmanLeft();
void movePacmanRight();
void movePacmanUP();
void movePacmanDown();
void moveGhost();
int main(void) {
  system("cls");
  
  int x=2;
  int key=4000;
  bool gameRunning=true;
  //showing pacman 
  gotoxy(pmanx,pmany);
  cout<<"P";
  while(gameRunning){//ascii codee for escape
    if(GetAsyncKeyState( VK_LEFT )){ //ascii LEFT arrow
       movePacmanLeft();
    }
    if(GetAsyncKeyState( VK_RIGHT )){ //ascii right arrow
       movePacmanRight();
    }

    if(GetAsyncKeyState( VK_UP )){ // up arrow key
       movePacmanUP();
    }
    if(GetAsyncKeyState( VK_DOWN)){ //down arrow key
       movePacmanDown();
    }
      if(GetAsyncKeyState( VK_ESCAPE) ){
        gameRunning=false;
      }

      moveGhost();
      Sleep(100);

  }

  
}
void movePacmanUP(){
  gotoxy(pmanx,pmany);
  cout<<" ";
  if(pmany>1){ // this condition stop pacman to cross the boundaries.
    pmany=pmany-1;
  }
  
  gotoxy(pmanx,pmany);
  cout<<"P";

}
void movePacmanDown(){
  gotoxy(pmanx,pmany);
  cout<<" ";
  pmany=pmany+1;
  gotoxy(pmanx,pmany);
  cout<<"P";

}

void movePacmanRight(){
  gotoxy(pmanx,pmany);
  cout<<" ";
  pmanx=pmanx+1;
  gotoxy(pmanx,pmany);
  cout<<"P";


}
void movePacmanLeft(){
  gotoxy(pmanx,pmany);
  cout<<" ";
  pmanx=pmanx-1;
  gotoxy(pmanx,pmany);
  cout<<"P";


}

void moveGhost(){
  
  gotoxy(ghostx,ghosty);
  cout<<" ";
  if(ghostDirection=="Right") {
     ghostx=ghostx+1;
     
  }
  if(ghostDirection=="Left"){
    ghostx=ghostx-1;
  }

  if(ghostx>=rightLimit) {
    ghostDirection="Left";
  }
  if(ghostx<=leftLimit){
    ghostDirection="Right";
  }
   gotoxy(ghostx,ghosty);
   cout<<"<-{}";

}
void gotoxy( short x, short y )
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE) ;
    COORD position = { x, y } ;
    SetConsoleCursorPosition( hStdout, position ) ;
}