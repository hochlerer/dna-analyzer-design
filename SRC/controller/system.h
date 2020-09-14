//
// Created by y on 7/5/20.
//

#ifndef DNA_SYSTEM_H
#define DNA_SYSTEM_H
class IReader;
class IWriter;
class UI;

class System{
public:
    void startApp(UI& ui, IReader& input, IWriter& output);

private:
};

#endif //DNA_SYSTEM_H
