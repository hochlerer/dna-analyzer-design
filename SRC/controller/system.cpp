//
// Created by y on 7/5/20.
//

#include "system.h"
#include "../model/structure_dna.h"
#include "callback.h"
#include "../controller/create_cmd_factory.h"
#include "../controller/ICMD.h"
#include "../view/UI.h"
#include "io_callback.h"


void System::startApp(UI& ui, IReader& input, IWriter& output) {
    StructureDna dnaStructure;
    Callback<System> callback(*this, &System::execCmd);
    CreateCmdFactory::init();
    ui.start(callback, input, output, dnaStructure);

    CreateCmdFactory::release();
}


void System::execCmd(Parser &p, StructureDna &dnaStructure, IOCallback<UI> &ioCallback) {
    CreateCmdFactory::create(p)->run(p, dnaStructure, ioCallback);
}


