//
//  main.cpp
//  Umfang_Rechner
//
//  Created by Leonard Schuetz on 25.12.13.
//  Copyright (c) 2013 Leonard Schuetz. All rights reserved.
//

#include <iostream>
#include <termios.h>
#include <unistd.h>

#define PI 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679
using namespace std;

int main()
{
    system("clear");
    
    int durchmesser, oberflaeche;
    
    printf("Durchmesser(cm): "); cin >> durchmesser; printf("\n");
    oberflaeche = PI * durchmesser * durchmesser;
    printf("Fläche der Kugel: %i", oberflaeche); printf("\n");
    
    printf("Press any key to close this tool");
    
    //Set the new termios variables
    struct termios old_tio, new_tio;
    /* get the terminal settings for stdin */
    tcgetattr(STDIN_FILENO,&old_tio);
    /* we want to keep the old setting to restore them a the end */
    new_tio=old_tio;
    /* disable canonical mode (buffered i/o) and local echo */
    new_tio.c_lflag &=(~ICANON & ~ECHO);
    /* set the new settings immediately */
    tcsetattr(STDIN_FILENO,TCSANOW,&new_tio);
    
    char m;
    cin >> m;
    
    /* restore the former settings */
    tcsetattr(STDIN_FILENO,TCSANOW,&old_tio);
    //Enables local echo
    new_tio.c_lflag |= ECHO;
    
    system("reset");
    
    return 0;
}