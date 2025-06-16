#ifndef CHARACTER
#define CHARACTER
#include <ncurses.h>
#include <vector>



struct position{
	int x, y, check;
};

class character{

	private:
		int x,y, state, has_key, path_len;
		char name;
		std :: vector<position> path;
	public:
		character(char input);
		character(int i, int j, char input);
		void move(int i, int j);
		int getState();
		void setState(int input);
		int getName();
		int getInventory();
		void setInventory(int input);
		int getX();
		int getY();
		void gotHere(int i, int j);
		int getWasHereX(int i);
		int getWasHereY(int i);
		int getWasHereCheck(int i);
		void setWasHereCheck(int i);
		int getPathLength();

};


character :: character(char input){

	x = 0;
	y = 0;
	name = input;
	state = 0;
	has_key = 0;
	path.push_back({0, 0});
	//path[0].x = 0;
	//path[0].y = 0;
	path_len = 0;

}


character :: character(int i, int j, char input){

	x = i;
	y = j;
	name = input;
	state = 0;
	has_key = 0;
	path.push_back({0, 0});
	path_len = 0;

}


void character :: move(int i, int j){

	x = i;
	y = j;

}


int character :: getState(){

	return state;

}


void character :: setState(int input){

	state = input;

}


int character :: getName(){

	return static_cast<int>(name);

}


int character :: getInventory(){

	return has_key;

}


void character :: setInventory(int input){

	if(input == 0 || input == 1){
		has_key = input;
	}

}


int character :: getX(){

	return x;

}


int character :: getY(){

        return y;

}


void character :: gotHere(int i, int j){

	path.push_back({i, j, 1});
	path_len++;

}


int character :: WasHereX(int i){

	if(i < path_len){
		return path[i].x;
	}else{
		return 0;
	}

}


int character :: WasHereY(int i){

	if(i < path_len){
		return path[i].y;
        }else{
		return 0;
	}

}


int character :: WasHereCheck(int i){

	if( i < path_len){
		return path[i].check;
	}else{
		return 0;
	}

}


void character :: setWasHereCheck(int i){

	if ( path[i].check == 0){
		path[i].check = 1;
	}else{
		path[i].check = 0;
	}

}


int character :: getPathLength(){

	return path_len;

}
#endif
