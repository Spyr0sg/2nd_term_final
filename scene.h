#ifndef SCENE_H
#define SCENE_H
#include <iostream>
#include <string>
#include <vector>
#include <curses.h>
using namespace std;

class scene{

	private:
		vector<vector<char> > env; //environment 2d vector
		int x = 0, y = 0;
		FILE *map;
	public:
		scene(char* map_name);
		int build(char* map_name); //Initialize map environment
		int prints(); //Print map environment on window
		int getVerticalAxis();
		int getHorizontalAxis();
		int getContent(int i, int j);
		int setContent(int i, int j, int c);

};


scene :: scene(char* map_name){

	int x_max, y_max, ln;
	map = fopen(map_name, "r");
	char c= ' ';
	if(map == NULL){
		printw("File handling error. Map data could not be loaded\n");
	}else{
		x_max = 0;
		y_max = 0;
		while(true){
			c = fgetc(map);
			if (c == '\n'){
				y_max++;
			}else if(c == EOF){
				y_max++;
				break;
			}
		}
		y = y_max;
		rewind(map);
		ln = 0;
		while(true){
			c = fgetc(map);
			if(c != '\n' && c != EOF){
				ln++;
			}else{
				if (ln > x_max){
					x_max = ln;
				}
				ln = 0;
				if (c == EOF){
					break;
				}
			}

		}
		x = x_max - 1;
		fclose(map);
		build(map_name);
		;
	}

}


int scene :: build(char* map_name){

	int i, j, c;
	FILE* map;
	map = fopen(map_name, "r");
        if(map == NULL){
                printw("File handling error. Map data could not be loaded\n");
		return 1;
	}
	if( x == 0 || y == 0){
		printw("The size of the map has not been declared. Cannot build environment.\n");
		return 1;
	}
	env.resize(x);
	for(i = 0; i < x; i++){
		env[i].resize(y);
	}
	for(j = 0; j < y; j++){
		c = fgetc(map);
		i = 0;
		while(i < x){
			if(c != '\n'){
				env[i][j] = static_cast<char>(c);
				i++;
			}
			c = fgetc(map);
		}
		if(c == EOF){
			break;
		}
	}
	fclose(map);
	return 0;

}


int scene :: prints(){

	int i, j;
	for(j = 0; j < y; j++){
		for(i = 0; i < x; i++){
			if( env[i][j] != '\n'){
				printw("%c",env[i][j]);
			}
		}
		printw("\n");
	}
	return 0;

}


int scene :: getHorizontalAxis(){

	return x;

}


int scene :: getVerticalAxis(){

	return y;

}


int scene :: getContent(int i, int j){

	if(i < 0 || i > x || j < 0 || j > y){
		return 1;
	}
	int c = env[i][j];
	return c;

}

int scene :: setContent(int i, int j, int c){

	if(i < 0 || i > x || j < 0 || j > y){
                return 1;
        }
	env[i][j] = c;
	return 0;

}

#endif

