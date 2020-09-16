//
// Created by y on 7/5/20.
//

#include <stdexcept>

#include "creation_command.h"
#include "new_cmd.h"
#include "load_cmd.h"
#include "dup_cmd.h"
#include "save_cmd.h"
#include "len_cmd.h"
#include "del_cmd.h"
#include "rename_cmd.h"
#include "find_cmd.h"
#include "count_cmd.h"
#include "create_cmd_factory.h"


ICMD *CreateCmdFactory::create(const Parser& p) {
    try {
        s_commands.at(p.getCmdName())->createCMD(p);

        return s_commands.at(p.getCmdName());
    }

    catch (std::out_of_range &e) {

        return s_commands.at("new");
    }
}

std::map<std::string, ICMD*> CreateCmdFactory::s_commands;

void CreateCmdFactory::init() {
    s_commands.insert(std::pair<std::string, ICMD*> ("new", new NewCmd));
    s_commands.insert(std::pair<std::string, ICMD*> ("load", new LoadCmd));
    s_commands.insert(std::pair<std::string, ICMD*> ("dup", new DupCmd));
    s_commands.insert(std::pair<std::string, ICMD*> ("save", new SaveCmd));
    s_commands.insert(std::pair<std::string, ICMD*> ("len", new LenCmd));
    s_commands.insert(std::pair<std::string, ICMD*> ("del", new DelCmd));
    s_commands.insert(std::pair<std::string, ICMD*> ("rename", new RenameCmd));
    s_commands.insert(std::pair<std::string, ICMD*> ("find", new FindCmd));
    s_commands.insert(std::pair<std::string, ICMD*> ("count", new CountCmd));
}

void CreateCmdFactory::release() {
    delete s_commands.at("new");
    delete s_commands.at("load");
    delete s_commands.at("dup");
    delete s_commands.at("save");
    delete s_commands.at("len");
    delete s_commands.at("del");
    delete s_commands.at("rename");
    delete s_commands.at("find");
    delete s_commands.at("count");
}

