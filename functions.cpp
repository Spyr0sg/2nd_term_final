#include <ncurses.h>
#include <stdlib.h>
#include <time.h>
#include "scene.h"
#include "character.h"

int init_scene(scene &s_name, char *map_name ){

	int x, y, posx, posy, flag;
	srand(time(NULL));
	scene s_name(map_name);
	x = s_name.getLength();
	y = s_name.getWidth();
	flag = 0;
	while (true){
		posx = (rand()%(x - 1))+1;
		posy = (rand()%(y - 1))+1;
		if(s_name.getContent(posx, posy){
			flag = 1;
			break;
		}
	}
	character G(posx, posy, "G");
	s_name.setContent(posx, posy, G.getName());
	return 0;

}
