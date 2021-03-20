//
// Created by focus on 20.03.2021.
//

#include <iostream>
#include "writer/Console/ConsoleWriter.h"

ConsoleWriter::ConsoleWriter(std::ostream &stream) : outStream(stream){

}


void ConsoleWriter::out(const commandsType & cmds) {
    outStream << "Bulk: ";
    for (const auto& cmd : cmds) {
        outStream << cmd << " ";
    }
    outStream << std::endl;

}

