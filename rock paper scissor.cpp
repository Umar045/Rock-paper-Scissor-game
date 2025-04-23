#include<iostream>
#include<cstdlib>

using namespace std;
class Game{
	public:
		virtual char getcomputermove()=0;
        virtual int getresult(char playermove, char computermove)=0;
	    virtual  void playgame()=0;
};
class Game1:public Game{
	public:
		char getcomputermove() override{
		int move;
		
		
		move=rand()%3;
		if(move==0){
			return 'p';
		}
		else if(move==2){
			return 's';
		}
			return 'r';
	}
	int getresult(char computermove, char playermove){
		if(playermove==computermove){
			return 0;
		}
		if(playermove=='s'&& computermove=='p'){
			return 1;
			
		}
		if(playermove=='s'&& computermove=='r'){
			return -1;
		}
		
		if(playermove=='p' && computermove=='r'){
			return 1;
		}
		if(playermove=='p' && computermove=='s'){
			return -1;
		}
		if(playermove=='r' && computermove=='p'){
			return -1;
		}
		if(playermove=='r' && computermove=='s'){
			return 1;
		}
		return 0;
	}
	void playgame(){
		char playermove;
		cout<<"\n\t\t\tWelcome to the Rock Paper Scissor Game.";
		cout<<"\n\t\t\t Enter r for Rock p for paper s for Scissor ";
		while(true){
			cin>>playermove;
			if(playermove=='r'|| playermove=='p'|| playermove=='s'){
				break;
			}
			else{
				cout<<"Invalid input(Enter r for Rock p for paper s for Scissor)";
			}
			
		}
	
	char computermove=getcomputermove();
	int result=getresult(playermove,computermove);
	if(result==0){
		cout<<"\n\t\t\tGame Draw.";
	}
	if(result==1){
		cout<<"\n\t\t\tplayer Won.";
	}
	if(result==-1){
		cout<<"\n\t\t\tcomputer is won.";
	}
	
	cout<<"\n\t\t\tYour Move: "<<playermove<<endl;
	cout<<"\n\t\t\tComputer Move: "<<computermove<<endl;
}
};
int main(){
	Game1 ob1;
	ob1.playgame();
	return 0;
}