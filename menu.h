#include <ncurses.h>

int menu(){
    int choice = 2;
    do{
        clear();
        printw("\n\n");
        printw("        The Adventure of Giannakis\n");
        printw("        and Asimenia\n");
        printw("                                             |DDP \n");
        printw("                                             | \n");
        printw("                                         |_|TT|_|\n");
        printw("                                          | ++ | \n");
        printw("       _||_    /\\        ****   *****     |    | \n");
        printw("       (``)   (``)        ********       |_|TT|_| \n");
        printw("       /||`````/ \\             ***        | ++ | \n");
        printw("       /  \\   /___\\                       | || | \n");
        printw("-------------------------------------------------==\n");
        printw("Choose map:\n");
        if(choice == 2){
            printw("[map1] map2\n");
            choice = 1;
        }else{
            printw(" map1 [map2]\n");
            choice = 2;
        }
        refresh();
    }while(getchar() != ' ');
    return choice;
}