#ifndef CHARACTER
#define CHARACTER
#include <ncurses.h>

using namespace std;

struct position{
	int x, y;
};

class character{

	private:
		int x,y, state, has_key, path_len;
		char name;
		struct position{
			int x, y;
		};
		vector<position> path;
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
		int gotHere(int i, int j);
//		position wasHere(int i);
		int getPathLenght();

};


character :: character(char input){

	x = 0;
	y = 0;
	name = input;
	state = 0;
	has_key = 0;
	path.push_back({0, 0});
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


int character :: gotHere(int i, int j){

	path.push_back({i, j});
	path_len++;

}


/*position character :: wasHere(int i){

	if(i >= path_len){
		return path[i];
	}
	}else{
		return path[0];
	}

}*/

int character :: getPathLenght(){

	return path_len;

}
#endif
