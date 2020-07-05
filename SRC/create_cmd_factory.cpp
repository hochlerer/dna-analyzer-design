//
// Created by y on 7/5/20.
//

#include "creation_command.h"
#include "new_cmd.h"

#include "create_cmd_factory.h"


ICMD *CreateCmdFactory::create(const std::string &command) {
    if(command == "new"){
        return new NewCMD;
    }
    return NULL;
}

