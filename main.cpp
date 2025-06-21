#include <iostream>
#include <ncurses.h>
#include <stdio.h>
#include <unistd.h>
#include "scene.h"
#include "character.h"
#include "functions.h"


int main(void){

    int i, j, moves, flag = 1;
    moves = 1000;
	initscr();
	scene maze("map1.txt");
	character giannakis('G');
	character asimenia('S');
	setup_scene(maze, giannakis, asimenia);
    set_object('T', maze);
    set_object('T', maze);
    set_object('K', maze);
	maze.printScene();
    printw("Giannakis position: x = %d, y = %d\n",giannakis.getX(), giannakis.getY());
	printw("Asimenia position: x = %d, y = %d\n",asimenia.getX(), asimenia.getY());
    printw("Press any key to begin.\n");
     refresh();
    getchar();
	while(moves > 0){
        clear();
        check_move(giannakis, maze);
        if(are_together(asimenia, giannakis) == 1){
           flag = 1; 
           break;
            
        }
        check_move(asimenia, maze);
        maze.printScene();
        moves--;
        printw("Giannakis position: x = %d, y = %d\n",giannakis.getX(), giannakis.getY());
        printw("Asimenia position: x = %d, y = %d\n",asimenia.getX(), asimenia.getY());
        printw("Moves left: %d\n", moves);
        usleep(50000);
        refresh();
    }
    if(flag == 1){
        for(j = 0; j < maze.getVerticalAxis(); j++){
		    for(i = 0; i < maze.getHorizontalAxis(); i++ ){
			    if(maze.getContent(i, j) == '*' || maze.getContent(i, j) == 'T' || maze.getContent(i, j) == 'K'){
                    clear();
			    	maze.setContent(i, j, ' ');
                    maze.printScene();
                    refresh();
			    	usleep(50000);
			    }
            }
        }
    }
    printw("Moves have been depleted. Press any key to continue.");
    refresh();
    getchar();
    endwin();
    return 0;

}