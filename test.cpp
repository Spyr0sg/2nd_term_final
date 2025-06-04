#include <ncurses.h>
#include "scene.h"
#include "character.h"
#include "functions.h"


int main(void){

	initscr();
	//printw("Hello!\n");
	scene maze("map1.txt");
	character giannakis('G');
	character asimenia('S');
	setup_scene(maze, giannakis, asimenia);
	//maze.setContent(3,3, 'n');
	do{
	clear();
	printw("Size of map: x = %d, y = %d\n", maze.getHorizontalAxis(), maze.getVerticalAxis());
	check_move(giannakis, maze);
	check_move(asimenia, maze);
	maze.prints();
	printw("Giannakis position: x = %d, y = %d\n",giannakis.getX(), giannakis.getY());
	printw("Asimenia position: x = %d, y = %d\n",asimenia.getX(), asimenia.getY());
	refresh();
	}while(getchar() != '0');
	endwin();
	return 0;

}
