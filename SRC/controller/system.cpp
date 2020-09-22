//
// Created by y on 7/5/20.
//

#include "system.h"
#include "../model/structure_dna.h"
#include "callback.h"
#include "../controller/create_cmd_factory.h"
#include "../controller/ICMD.h"
#include "../view/UI.h"


void System::startApp(UI& ui, IReader& input, IWriter& output) {
    StructureDna dnaStructure;
    Callback<System> callback(*this, &System::execCmd);
    ui.start(callback, input, output, dnaStructure);
}

void System::execCmd(Parser &p, StructureDna &dnaStructure, IReader &input, IWriter &output) {
    CreateCmdFactory::create(p)->run(p, dnaStructure, input, output);
}

