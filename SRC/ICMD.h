//
// Created by y on 7/5/20.
//

#ifndef DNA_ICMD_H
#define DNA_ICMD_H
#include <vector>
#include <string>

class ICMD{
public:
    virtual void run(const std::vector<std::string>& params) = 0;

private:
};

#endif //DNA_ICMD_H
