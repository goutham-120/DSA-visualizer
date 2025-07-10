// ConsoleUtils.h
#pragma once
#include <iostream>
using namespace std;
#define red "\033[31m"
 #define green "\033[32m"
 #define yellow "\033[33m"
 #define blue "\033[34m"
#define purple "\033[35m"
#define cyan "\033[36m"
#define white "\033[37m"
inline void clearConsole() {
    cout << "\033[3J\033[H"<<flush;
}
inline void gotoxy(int x, int y) {
    clearConsole();
    cout << "\033[" << x << ";" << y << "H";
    cout << "\033[0J"<<flush;
   
}


#ifdef _WIN32
    #include <conio.h>
#else
    #include <termios.h>
    #include <unistd.h>
    inline int _getch() {
        struct termios oldt, newt;
        int ch;
        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
        ch = getchar();
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
        return ch;
    }
#endif