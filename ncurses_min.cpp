#include <curses.h>
#inlcude "modele.hpp"
#include <iostream>
#include <ctime>

using namespace std;

using Plateau = vector<vector<int>>;

int main() {
    int s = 0;
    srand(time(0));
    Plateau t = plateauInitial();
    cout << "Score: " << s;
    cout << endl << endl; 
    cout << dessine(t);
    char cdir[128];
    cdir['a'] = 0;
    cdir['d'] = 1;
    cdir['w'] = 2;
    cdir['s'] = 3;
    Plateau newgamet = plateauVide();
    Plateau newt = plateauVide();
    Plateau ancienPlateau = plateauVide();
    while (!estTerminé(t, ancienPlateau) && !estGagnant(t))
    {
        ancienPlateau = t;
        char c;
        cin >> c;
        int dircurrent = cdir[c];
        // cout << dircurrent << endl; //test wasd
        newt = déplacement(t, dircurrent, s);
        newgamet = Nouvelletuille(newt);
        system("cls");
        cout << "Score: " << s;
        cout << endl << endl;
        cout << dessine(newgamet);
        t = newgamet;
    }
    return 0;

}
