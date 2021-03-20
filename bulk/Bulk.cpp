//
// Created by focus on 20.03.2021.
//

#include "Bulk.h"
#include "writer/Console/ConsoleWriter.h"
#include "batcher/Batcher.h"

Bulk::Bulk(const Settings & settings) : _settings(settings) {

}

void Bulk::run() {
    writerPtrType consoleOutput = std::make_shared<ConsoleWriter>(_settings.toConsole);
    std::unique_ptr<Batcher> batcherPtr = std::make_unique<Batcher>(_settings.sizeBuffer);
    batcherPtr->addOutputs(consoleOutput);

    std::string command;
    while (std::getline(_settings.from, command)) {
        batcherPtr->addCommand(command);
    }
}
