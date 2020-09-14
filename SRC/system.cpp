//
// Created by y on 7/5/20.
//

#include "system.h"
#include "structure_dna.h"
#include "ICMD.h"
#include "create_cmd_factory.h"
#include "terminal.h"

void System::startApp(IReader& input, IWriter& output) {
    StructureDna dnaStructure;
    Terminal cmd;
    cmd.start(input, output, dnaStructure);

}

