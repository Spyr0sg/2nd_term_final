#ifndef FUNCTIONS
#define FUNCTIONS
#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include "scene.h"
#include "character.h"

int setup_scene(scene &scn, character &person1, character &person2){

	int x, y, posx, posy, i, j, count, flag;
	srand(time(NULL));
	x = scn.getHorizontalAxis();
	y = scn.getVerticalAxis();
	flag = 0;
	while (true){
		posx = (rand() % (x/2 - 1)) + 1;
		posy = (rand() % (y/2 - 1)) + 1;
		if(scn.getContent(posx, posy) == ' '){
			break;
		}
	}
	person1.move(posx, posy);
	scn.setContent(posx, posy, person1.getName());
	person2.move(0, posy);
	while(true){
		posx = (rand() % (x/2 - 1)) + x/2 + 1;
		posy = (rand() % (y/2 - 1)) + 1;
		if(scn.getContent(posx, posy) == ' '){
			break;
		}
	}
	person2.move(posx, posy);
        scn.setContent(posx, posy, person2.getName());
	/*count = 0;
	while(count < 2){
		for(i = 1; i < x - 1; i++){
			flag = 0;
			for(j = 1; j < y - 1; j++){
				if(s_name.getContent(i, j) == 'T'){
					posx = i;
					posy = j;
					flag = 1;
					break;
				}
			}
			if(flag = 1){
				break;
			}
		}
		count++;
	}*/
	return 0;

}

int check_move(character &person, scene &scn){

	srand(time(NULL));
	int i, j, posx, posy, flag, l, count;
	if(person.getState() != 0){
		return 0;
	}
	struct block{
		int x, y;
	};
	block* around = new block[4];
	posx = person.getX();
	posy = person.getY();
	around[0].x = posx - 1;
	around[0].y = posy;
        around[1].x = posx + 1;
        around[1].y = posy;
        around[2].x = posx;
        around[2].y = posy - 1;
        around[3].x = posx;
        around[3].y = posy + 1;
	for(i = 0; i < 4; i++){
		if(scn.getContent(around[i].x, around[i].y) == '*'){
			printw("W\n");
		}else if(scn.getContent(around[i].x, around[i].y) == ' '){
			printw("C\n");
		}else if(scn.getContent(around[i].x, around[i].y) == NULL){
			printw("N\n");
		}
	}
	count = 0;
	while(true){
		i = rand() % 4;
		l = person.getPathLength();
		j = 0;
		flag = 1;
		for(j = 1; j <= l; j ++){
			if(((person.getWasHereX(j) == around[i].x && person.getWasHereY(j) == around[i].y) || scn.getContent(around[i].x, around[i].y) == '*') && count <= 3){
				count++;
				around[i].x = 0;
				around[i].y = 0;
			}
		}
		if(scn.getContent(around[i].x, around[i].y) != '*'){
			scn.setContent(posx, posy, ' ');
			person.move(around[i].x, around[i].y);
			scn.setContent(around[i].x, around[i].y, person.getName());
			person.gotHere(around[i].x, around[i].y);
			break;
		}
	}
	delete[] around;
	return 0;

}



#endif

