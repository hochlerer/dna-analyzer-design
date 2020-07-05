//
// Created by y on 7/5/20.
//

#ifndef DNA_NEW_CMD_H
#define DNA_NEW_CMD_H

#include "creation_command.h"


class NewCMD: public CreationCMD{
public:
    NewCMD(const Parser& params);
    void run(const Parser& params);

private:
};

#endif //DNA_NEW_CMD_H
