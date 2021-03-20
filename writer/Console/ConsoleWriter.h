//
// Created by focus on 20.03.2021.
//

#ifndef OTUS_BULK_CONSOLEWRITER_H
#define OTUS_BULK_CONSOLEWRITER_H

#include <iostream>
#include "writer/Writer.h"

class ConsoleWriter : public Writer {
public:
    ConsoleWriter(std::ostream& stream = std::cout);
    void out(const commandsType &) override;

private:
    std::ostream& outStream;
};


#endif //OTUS_BULK_CONSOLEWRITER_H
