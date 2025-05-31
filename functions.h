#ifndef FUNCTIONS
#define FUNCTIONS
#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include "scene.h"
#include "character.h"

int setup_scene(scene &s_name, character &person1){

	int x, y, posx, posy, i, j, count, flag;
	srand(time(NULL));
	x = s_name.getHorizontalAxis();
	y = s_name.getVerticalAxis();
	flag = 0;
	while (true){
		posx = (rand() % (x - 1)) + 1;
		posy = (rand() % (y - 1)) + 1;
		if(s_name.getContent(posx, posy) == ' '){
			flag = 1;
			break;
		}
	}
	person1.move(posx, posy);
	s_name.setContent(posx, posy, person1.getName());
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

int can_move(character &person, scene &scn){

	srand(time(NULL));
	void* path;
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
/*	count = 0;
	l = person.getLineLength();
	j == 0;
	for(i = 1; i <= l; i++){
		path = person.wasHere();
		if(around[j].x == path.x && around[j].y == path.y){
			j++
			count++;
		}
		if(count == 4){
			break;
		}
	}*/
	flag == 1;
	while(true){
		i = rand() % 4;
		if(scn.getContent(around[i].x, around[i].y) != '*'){
			scn.setContent(posx, posy, ' ');
			person.move(around[i].x, around[i].y);
			scn.setContent(around[i].x, around[i].y, person.getName());
			break;
		}
	}
	delete[] around;
	return 0;

}



#endif

