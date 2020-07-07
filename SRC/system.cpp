//
// Created by y on 7/5/20.
//

#include "system.h"
#include "keyboard_reader.h"
#include "parser.h"
#include "ICMD.h"
#include "create_cmd_factory.h"
#include "screen_writer.h"
#include "terminal.h"

void System::startApp(IReader* input, IWriter* output) {
    Terminal cmd;
    cmd.start(input, output);

}

