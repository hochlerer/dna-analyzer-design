//
// Created by y on 7/5/20.
//

#include "system.h"
#include "../model/structure_dna.h"
#include "ICMD.h"
#include "../view/UI.h"

void System::startApp(UI& ui, IReader& input, IWriter& output) {
    StructureDna dnaStructure;
    ui.start(input, output, dnaStructure);

}

