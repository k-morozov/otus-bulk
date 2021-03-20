//
// Created by focus on 20.03.2021.
//

#ifndef OTUS_BULK_CONSOLEWRITER_H
#define OTUS_BULK_CONSOLEWRITER_H

#include "writer/Writer.h"

class ConsoleWriter : public Writer {
public:
    void out(const commandsType &) override;

};


#endif //OTUS_BULK_CONSOLEWRITER_H
