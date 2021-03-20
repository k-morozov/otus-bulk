//
// Created by focus on 20.03.2021.
//

#ifndef OTUS_BULK_BULK_H
#define OTUS_BULK_BULK_H

#include <memory>
#include <bulk/SettingsBulk.h>
#include "writer/Console/ConsoleWriter.h"
#include "batcher/Batcher.h"

class Bulk {
public:
    explicit Bulk(const Settings& settings);

    void run() {
        writerPtrType consoleOutput = std::make_shared<ConsoleWriter>(_settings.toConsole);
        std::unique_ptr<Batcher> batcherPtr = std::make_unique<Batcher>(_settings.sizeBuffer);
        batcherPtr->addOutputs(consoleOutput);

        std::string command;
        while (std::getline(_settings.from, command)) {
            batcherPtr->addCommand(command);
        }
    }

private:
    Settings _settings;
};


#endif //OTUS_BULK_BULK_H
