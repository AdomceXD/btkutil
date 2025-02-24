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