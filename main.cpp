#include <iostream>
#include <memory>
#include "writer/Console/ConsoleWriter.h"
#include "batcher/Batcher.h"

namespace {
    void RunBulk(int sizeBuffer) {
        writerPtrType consoleOutput = std::make_shared<ConsoleWriter>();
        std::unique_ptr<Batcher> batcherPtr = std::make_unique<Batcher>(sizeBuffer);
        batcherPtr->addOutputs(consoleOutput);

        std::string command;
        while (std::getline(std::cin, command)) {
            batcherPtr->addCommand(command);
        }
    }
}

int main(int argc, char **argv) {
    std::cout << "Hello, World!" << std::endl;
    if (argc < 2) {
        std::cerr << "Invalid count argument" << std::endl;
        exit(EXIT_FAILURE);
    }

    try {
        int count = std::stoi(argv[1]);
        if (count == 0) {
            std::cerr << "Argument is zero" << std::endl;
            exit(EXIT_FAILURE);
        }

        RunBulk(count);
    } catch (std::exception &ex) {
        std::cerr << ex.what() << std::endl;
    }
    return 0;
}
