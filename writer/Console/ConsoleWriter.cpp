//
// Created by focus on 20.03.2021.
//

#include <iostream>
#include "writer/Console/ConsoleWriter.h"

void ConsoleWriter::out(const commandsType & cmds) {
    std::cout << "Bulk: ";
    for (const auto& cmd : cmds) {
        std::cout << cmd << " ";
    }
    std::cout << std::endl;

}
