//
// Created by focus on 20.03.2021.
//

#include <iostream>
#include "writer/Console/ConsoleWriter.h"

ConsoleWriter::ConsoleWriter(std::ostream &stream) : outStream(stream){

}


void ConsoleWriter::out(const commandsType & cmds) {
    outStream << "bulk: ";
    for (auto it = cmds.begin(); it!=cmds.end(); ++it) {
        outStream << it->text;
        if (std::next(it) != cmds.end()) {
            outStream << ", ";
        }
    }
    outStream << std::endl;

}

