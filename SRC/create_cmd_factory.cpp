//
// Created by y on 7/5/20.
//

#include "creation_command.h"
#include "new_cmd.h"
#include "load_cmd.h"
#include "dup_cmd.h"
#include "create_cmd_factory.h"


ICMD *CreateCmdFactory::create(const Parser& p) {
    if(p.getCmdName() == "new"){
        return new NewCmd(p);
    }
    if(p.getCmdName() == "load"){
        return new LoadCmd(p);
    }
    if(p.getCmdName() == "dup"){
        return new DupCmd(p);
    }
    return NULL;
}

