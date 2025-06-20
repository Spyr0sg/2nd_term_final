#include <iostream>
#include <ncurses.h>
#include <stdio.h>
#include <unistd.h>
#include "scene.h"
#include "character.h"
#include "functions.h"


int main(void){

    int moves, fl = 0;
    moves = 1000;
	initscr();
	scene maze("map1.txt");
	character giannakis('G');
	character asimenia('S');
	setup_scene(maze, giannakis, asimenia);
    set_object('T', maze);
    set_object('T', maze);
    set_object('K', maze);
	maze.printscene();
    printw("Giannakis position: x = %d, y = %d\n",giannakis.getX(), giannakis.getY());
	printw("Asimenia position: x = %d, y = %d\n",asimenia.getX(), asimenia.getY());
    printw("Press any key to begin.\n");
    refresh();
    getchar();
	while(moves > 0){
        clear();
        check_move(giannakis, maze);
        
        if(are_together(asimenia, giannakis) == 1){
            break;
            fl = 1;
        }
        check_move(asimenia, maze);
        if(asimenia.getState() == 1 && giannakis.getState() == 1){
            break;
        }
        maze.printscene();
        moves--;
        printw("Giannakis position: x = %d, y = %d\n",giannakis.getX(), giannakis.getY());
        printw("Asimenia position: x = %d, y = %d\n",asimenia.getX(), asimenia.getY());
        printw("Moves left: %d\n", moves);
        usleep(50000);
        
        refresh();
    }
    if(fl == 1){
        destroy(maze);
    }
    printw("Moves have been depleted. Press any key to continue.");
    refresh();
    getchar();
    endwin();
    return 0;

}