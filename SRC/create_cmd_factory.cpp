//
// Created by y on 7/5/20.
//

#include "creation_command.h"
#include "new_cmd.h"

#include "create_cmd_factory.h"


ICMD *CreateCmdFactory::create(const Parser& p) {
    if(p.getCmdName() == "new"){
        return new NewCMD(p);
    }
    //return NULL;
}

