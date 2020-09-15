//
// Created by y on 7/5/20.
//


#include "../model/structure_dna.h"
#include "../view/UI.h"
#include "system.h"


void System::startApp(UI& ui, IReader& input, IWriter& output) {
    StructureDna dnaStructure;
    ui.start(input, output, dnaStructure);

}

