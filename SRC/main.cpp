#include <iostream>

#include "view/keyboard_reader.h"
#include "view/screen_writer.h"
#include "view/terminal.h"
#include "controller/system.h"


int main() {
    std::cout<<"---main---"<<std::endl;

    KeyboardReader read;
    ScreenWriter write;
    System s;
    Terminal terminal(read, write);
    s.startApp(terminal , read, write);


    std::cout<< "end of program" <<std::endl;
    return 0;
}
