//
// Created by y on 7/7/20.
//

#include "terminal.h"
#include "../controller/parser.h"
#include "../controller/ICMD.h"
#include "../controller/create_cmd_factory.h"

void Terminal::start(IReader& input, IWriter& output, StructureDna& dnaStructure) {
    CreateCmdFactory::init();

    while (true){
        Parser p;
        output.write("> cmd >>> ");
        input.read();
        p.parseCmd(input.getStr());

        if (p.getCmdName() == "quit") {
            break;
        }

        try {
            ICMD *command = CreateCmdFactory::create(p);
            command->run(p, dnaStructure, input, output);
        }

        catch (std::exception &e) {
            output.write(e.what());
            output.write("please enter again\n");
        }
    }
    CreateCmdFactory::release();
}

