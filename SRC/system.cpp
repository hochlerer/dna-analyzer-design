//
// Created by y on 7/5/20.
//

#include "system.h"
#include "keyboard_reader.h"
#include "parser.h"
#include "ICMD.h"
#include "create_cmd_factory.h"
#include "screen_writer.h"


void System::startApp() {
    while (true){
        KeyboardReader input;
        ScreenWriter sw;
        Parser p;
        std::string output;
        input.read();
        p.parseCmd(input.getStr());
        if (p.getCmdName() == "quit"){
            break;
        }
        ICMD* command = CreateCmdFactory::create(p);
        command->run(p);
        output = command->printAfterCommand();
        sw.write(output.c_str());
    }

}

