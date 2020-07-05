//
// Created by y on 7/5/20.
//

#include "system.h"
#include "keyboard_reader.h"
#include "parser.h"
#include "ICMD.h"
#include "create_cmd_factory.h"
#include <iostream>

void System::startApp() {
    while (true){
        KeyboardReader input;
        Parser p;
        input.read();
        p.parseCmd(input.getStr());
        if (p.getCmdName() == "quit"){
            break;
        }
        ICMD* command = CreateCmdFactory::create(p);
        command->run(p);
    }

}

