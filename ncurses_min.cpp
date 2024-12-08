#include "modele.hpp"
#include <curses.h>
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

using Plateau = vector<vector<int>>;

int main() {

    // Inicijalizacija ncurses
    initscr();
    cbreak();
    keypad(stdscr, TRUE);

    // Kreiranje prozora
    int height = 20, width = 20, start_y = 0, start_x = 0;
    WINDOW *win = newwin(height, width, start_y, start_x);
    wrefresh(win);

    int c;

    int s = 0;
    srand(time(0));
    Plateau t = plateauInitial();
    printw("%d", s);
    printw("%s", dessine(t).c_str());
    refresh();   

    Plateau newt = plateauVide();
    Plateau ancienPlateau = plateauVide();

    while (!estTerminé(t, ancienPlateau) && !estGagnant(t))
    {
        ancienPlateau = t;
        c = getch();
        
        if (c == KEY_LEFT) {
            newt = déplacement(t,0,s);  
        } else if (c == KEY_RIGHT) {
            newt = déplacement(t,1,s); 
        } else if (c == KEY_UP) {
            newt = déplacement(t,2,s); 
        } else if (c == KEY_DOWN) {
            newt = déplacement(t,3,s); 
        }
    
        t = Nouvelletuille(newt);
                
        clear();
        printw("%d", s);
        printw("%s", dessine(t).c_str());
        refresh(); 
    } 

    delwin(win);
    endwin();
    return 0;
}

