//
// Created by y on 7/7/20.
//

#include "terminal.h"
#include "system.h"
#include "keyboard_reader.h"
#include "parser.h"
#include "ICMD.h"
#include "create_cmd_factory.h"
#include "screen_writer.h"
#include "terminal.h"

void Terminal::start(IReader& input, IWriter& output, StructureDna& dnaStructure) {
    while (true){
        Parser p;
        input.read();
        p.parseCmd(input.getStr());
        if (p.getCmdName() == "quit") {
            break;
        }
        try {
            ICMD *command = CreateCmdFactory::create(p);
            command->run(p, dnaStructure, output);
        }
        catch (std::invalid_argument e) {
            output.write(e.what());
            output.write("please enter again\n");
        }
    }
}

