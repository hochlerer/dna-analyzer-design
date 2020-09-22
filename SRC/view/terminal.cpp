//
// Created by y on 7/7/20.
//

#include "terminal.h"
#include "../controller/system.h"
#include "../controller/parser.h"
#include "../controller/create_cmd_factory.h"
#include "IWriter.h"
#include "IReader.h"


void Terminal::start(Callback<System> &callback, IReader &input, IWriter &output, StructureDna &dnaStructure) {
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
            callback(p, dnaStructure, input, output);
        }

        catch (std::exception &e) {
            output.write(e.what());
            output.write("\nplease enter again\n");
        }
    }
    CreateCmdFactory::release();
}

