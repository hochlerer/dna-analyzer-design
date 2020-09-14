//
// Created by y on 7/5/20.
//

#include "creation_command.h"
#include "new_cmd.h"
#include "load_cmd.h"
#include "dup_cmd.h"
#include "create_cmd_factory.h"


ICMD *CreateCmdFactory::create(const Parser& p) {
    try {
        s_commands.at(p.getCmdName())->createCMD(p);
        return s_commands.at(p.getCmdName());
    }

    catch (std::out_of_range &e) {
        return NULL;
    }

/*    if(p.getCmdName() == "new"){
        return new NewCmd(p);
    }
    if(p.getCmdName() == "load"){
        return new LoadCmd(p);
    }
    if(p.getCmdName() == "dup"){
        return new DupCmd(p);
    }
    if(p.getCmdName() == "save"){
        return new SaveCmd(p);
    }
    return NULL;
    */
}

std::map<std::string, ICMD*> CreateCmdFactory::s_commands = init();

std::map<std::string, ICMD*> CreateCmdFactory::init() {
    std::map<std::string, ICMD*> tempCommands;
    tempCommands.insert(std::pair<std::string, ICMD*> ("new", new NewCmd));
    tempCommands.insert(std::pair<std::string, ICMD*> ("load", new LoadCmd));
    tempCommands.insert(std::pair<std::string, ICMD*> ("dup", new DupCmd));
    std::cout<<"init commands\n";

    return tempCommands;
}

void CreateCmdFactory::release() {
    delete s_commands.at("new");
    delete s_commands.at("load");
    delete s_commands.at("dup");
    std::cout<<"destroy commands\n";

}

