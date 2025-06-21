#include <iostream>
#include <ncurses.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "scene.h"
#include "character.h"
#include "functions.h"
#include "menu.h"
#define A 9



int main(void){

    int i, j, moves, flag = 0;
    moves = 1000;
    char map[9];
	initscr();
    if(menu() == 1){
	    strcpy(map, "map1.txt");
    }else{
        strcpy(map, "map2.dat");
    }
    clear();
    scene maze(map);
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
        if(are_together(asimenia, giannakis) == 1){
           flag = 1; 
           break;
            
        }
        
        maze.printScene();
        if((giannakis.getState() == 0 && asimenia.getState() == 0) || giannakis.getState() == 3 || asimenia.getState() == 3){
            printw("Uh oh! Both characters are trapped! The kingdom has fallen...\nPress any key to close the program.\n");
            refresh();
            getchar();
            endwin();
            return 0;
        }
        moves--;
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
			    	usleep(30000);
			    }
            }
        }
        clear();
        maze.setContent(maze.getLadderX(), maze.getLadderY(), 'L');
        maze.printScene();
        refresh();
        flag = 0;
        while(flag == 0){
            clear();
            escape(giannakis, maze);
            escape(asimenia, maze);
            if(giannakis.getX() == maze.getLadderX() && giannakis.getY() == maze.getLadderY()){
                flag = 1;
            }
            maze.printScene();
            refresh();
            usleep(10000);
        }
        printw("Yippee! The characters escaped! The kingdom has been saved! Rejoice!\nPress any key to close the program.\n");
        refresh();
        getchar();
        endwin();
        return 0;
    }
    printw("Oh no! The characters ran out of time! The evil Wizzard has won. The kingdom has fallen...\nPress any key to close the program.");
    refresh();
    getchar();
    endwin();
    return 0;

}