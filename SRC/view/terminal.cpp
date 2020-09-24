//
// Created by y on 7/7/20.
//

#include "terminal.h"
#include "../controller/system.h"
#include "../controller/parser.h"
#include "../controller/create_cmd_factory.h"
//#include "../controller/io_callback.h"
#include "IWriter.h"
#include "IReader.h"


void Terminal::start(Callback<System> &callback, IReader &input, IWriter &output, StructureDna &dnaStructure) {
    IOCallback<UI> ioCallback(*this, &UI::read, &UI::write);

    while (true){
        Parser p;
        write("> cmd >>> ");
        read();
        p.parseCmd(input.getStr());

        if (p.getCmdName() == "quit") {
            break;
        }

        try {
            callback(p, dnaStructure, ioCallback);
        }

        catch (std::exception &e) {
            write(e.what());
//            output.write("\nplease enter again\n");
            write("\n");
        }
    }
}

void Terminal::write(const std::string& output) const {
    m_output.write(output.c_str());
}

const std::string& Terminal::read() const {
    m_input.read();
    return m_input.getStr();
}