#include <ncurses.h>
#include "scene.h"
#include "character.h"
#include "functions.h"


int main(void){

	initscr();
	//printw("Hello!\n");
	scene maze("map1.txt");
	character giannakis('G');
	setup_scene(maze, giannakis);
	//maze.setContent(3,3, 'n');
	do{
	clear();
	printw("Size of map: x = %d, y = %d\n", maze.getHorizontalAxis(), maze.getVerticalAxis());
	can_move(giannakis, maze);
	maze.prints();
	printw("Giannakis position: x = %d, y = %d\n",giannakis.getX(), giannakis.getY());
	refresh();
	}while(getchar() != '0');
	endwin();
	return 0;

}
