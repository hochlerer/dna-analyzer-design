//
// Created by y on 7/5/20.
//

#include "system.h"
#include "keyboard_reader.h"
#include "parser.h"
#include "ICMD.h"
#include "create_cmd_factory.h"

void System::startApp() {
    KeyboardReader input;
    Parser p;
    while (true){
        input.read();
        p.parseCmd(input.getStr());
        if (p.getCmdName() == "quit"){
            break;
        }
        ICMD* command = CreateCmdFactory::create(p.getCmdName());
        command->run(p.getParams());
    }

}

