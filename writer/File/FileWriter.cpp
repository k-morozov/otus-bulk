//
// Created by focus on 20.03.2021.
//

#include "FileWriter.h"
#include <sstream>
#include <fstream>
#include <unistd.h>

void FileWriter::out(const commandsType & commands) {
    if (commands.empty()) {
        return;
    }

    auto fileName = getFileName(commands.front());
    std::ofstream streamFile(fileName, std::ofstream::out);

    streamFile << "bulk ";
    for(const auto& cmd : commands) {
        streamFile << cmd.text << " ";
    }
//    sleep(1);
}

std::string FileWriter::getFileName(const Command & command) {
    auto sec = std::chrono::duration_cast<std::chrono::seconds>(command.time.time_since_epoch()).count();
    std::stringstream fileName;
    fileName << "bulk" << sec << ".log";
    return fileName.str();
}


