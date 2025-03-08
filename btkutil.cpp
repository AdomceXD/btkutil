#include <iostream>
#include <sys/ioctl.h>
#include <string>

void BTKmargin(int a){
    struct winsize w;
    ioctl(0, TIOCGWINSZ, &w);
    //Minus the length of text in cols divide by 2 again
    int leftMargin = w.ws_col / 2 - a;
    for (int i=0;i<leftMargin;i++){
        std::cout << ' ';
    }

}

void BTKdebug(const char* msg, bool endl){
        if(endl==1){
            std::cout << "[\033[33mDEBUG\033[0m] " << msg << "\n";
        } else {
            std::cout << "[\033[33mDEBUG\033[0m] " << msg;
        }
}

char BTKTextColor(int color){
    if(color>7){
        std::cout << "\033[0m";
    } else if (color==1){ //RED
        std::cout << "\033[31m";
    } else if (color==2){ //GREEN
        std::cout << "\033[32m";
    } else if (color==3){ //YELLOW
        std::cout << "\033[33m";
    } else if (color==4){ //BLUE
        std::cout << "\033[34m";
    } else if (color==5){ //MAGENTA
        std::cout << "\033[35m";
    } else if (color==6){ //CYAN
        std::cout << "\033[36m";
    } else if (color==7){ //WHITE
        std::cout << "\033[37m";
    } else if(color==0) {
        std::cout << "\033[0m"; //RESET
    }
    return 0;
}
