#ifndef FUNCTIONS
#define FUNCTIONS
#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include "scene.h"
#include "character.h"

int setup_scene(scene &scn, character &character1, character &character2){

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
	character1.move(posx, posy);
	scn.setContent(posx, posy, character1.getName());
	character2.move(0, posy);
	while(true){
		posx = (rand() % (x/2 - 1)) + x/2 + 1;
		posy = (rand() % (y/2 - 1)) + 1;
		if(scn.getContent(posx, posy) == ' '){
			break;
		}
	}
	character2.move(posx, posy);
    scn.setContent(posx, posy, character2.getName());
	return 0;

}


int set_object(char sprite, scene& scn){

	int i, j;
	srand(time(NULL));
	while(true){

		i = rand()%scn.getHorizontalAxis();
		j = rand()%scn.getVerticalAxis();
		if(scn.getContent(i, j) == ' '){
			scn.setContent(i, j, sprite);
			break;
		} 
	}
	return 0;
}


int check_move(character &character, scene& scn){
	
	int i, j, posx, posy, flag, l, count;
	srand(time(NULL));
	if(character.getState() == 1 || character.getState() == 2 ){
		struct block{
				int x, y, f = 0;
		};
		block* around = new block[4];
		posx = character.getX();
		posy = character.getY();
		around[0].x = posx - 1;
		around[0].y = posy;
        around[1].x = posx + 1;
   	    around[1].y = posy;
   	    around[2].x = posx;
		around[2].y = posy - 1;
   		around[3].x = posx;
        around[3].y = posy + 1;
		count = 0;
		l = character.getPathLength();
		j = 0;
		flag = 0;
		for(i = 0; i < 4; i++){
			for(j = 1; j <= l; j ++){
				if(((character.WasHereX(j) == around[i].x && character.WasHereY(j) == around[i].y) || scn.getContent(around[i].x, around[i].y) == '*') && count < 4){
					count++;
					around[i].f = 1; 
				}
				if(scn.getContent(around[i].x, around[i].y) == 'C' && character.getState() == 2){
					scn.setContent(posx, posy, ' ');
					character.move(around[i].x, around[i].y);
					scn.setContent(around[i].x, around[i].y, character.getName());
					character.gotHere(around[i].x, around[i].y);
					flag = 1;
				}
			} 
		}
		while(flag == 0){
			i = rand()%4;
			if((around[i].f == 0 || count == 4) && scn.getContent(around[i].x, around[i].y) != '*'){
				if(scn.getContent(around[i].x, around[i].y) == 'T'){
					scn.setContent(posx, posy, ' ');
					if(character.getState() == 1){
						character.setState(0);
					}else{
						character.setState(3);
					}
					character.move(around[i].x, around[i].y);
					scn.setContent(around[i].x, around[i].y, 'C');
					if(around[i].f == 0){
						character.gotHere(around[i].x, around[i].y);
					}
				}else if(scn.getContent(around[i].x, around[i].y) == 'K'){
					scn.setContent(posx, posy, ' ');
					character.move(around[i].x, around[i].y);
					scn.setContent(around[i].x, around[i].y, character.getName());
					if(around[i].f == 0){
						character.gotHere(around[i].x, around[i].y);
					}
					character.setState(2);
				}else if(scn.getContent(around[i].x, around[i].y) != 'C'){
					scn.setContent(posx, posy, ' ');
					character.move(around[i].x, around[i].y);
					scn.setContent(around[i].x, around[i].y, character.getName());
					if(around[i].f == 0){
						character.gotHere(around[i].x, around[i].y);
					}
				}
				break;
			}
			
		}
		delete[] around;
	}else if(character.getState() == 4){
		int x, y;
		x = scn.getLadderX();
		y = scn.getLadderY();
		return 1;

	}
	
	return 0;

}

int are_together(character& character1, character& character2){

	if(character1.getX() == character2.getX() && character1.getY() == character2.getY()){
		character1.setState(4);
		character2.setState(4);
		return 1;
	}
	return 0;

}

int escape(character& character, scene& scn){

	int nextX = character.getX(), nextY = character.getY();
	if(character.getX() != scn.getLadderX()){
		if(scn.getLadderX() > character.getX()){
			nextX++;
		}else{
			nextX--;
		}
	}
	if(scn.getLadderY() != character.getY()){
		if(scn.getLadderY() > character.getY()){
			nextY++;
		}else{
			nextY--;
		}
	}
	scn.setContent(character.getX(), character.getY(), ' ');
	character.move(nextX, nextY);
	scn.setContent(character.getX(), character.getY(), character.getName());
	return 0;

}


#endif

