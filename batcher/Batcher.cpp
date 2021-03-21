//
// Created by focus on 20.03.2021.
//

#include <chrono>
#include "Batcher.h"

Batcher::Batcher(int count) : maxSizeBuffer(count), _blockStatus(0){

}

void Batcher::addOutputs(writerPtrType newOutput) {
    if (!newOutput) {
        throw std::invalid_argument("newOutput is null");
    }

    _outputs.push_back(newOutput);
}

void Batcher::addCommand(const std::string &textCommand) {
    if (textCommand == "{") {
        if (_blockStatus == 0 && !_buffer.empty()) {
            forcedOutBlock();
        }
        ++_blockStatus;
    } else if (textCommand == "}") {
        --_blockStatus;
        if (_blockStatus == 0 && !_buffer.empty()) {
            forcedOutBlock();
        }
    } else {
        auto time = std::chrono::system_clock::now();
        Command command{textCommand, time};
        _buffer.push_back(command);
        if (_blockStatus == 0 && _buffer.size() == static_cast<std::size_t>(maxSizeBuffer)) {
            forcedOutBlock();
        }
    }

}

void Batcher::forcedOutBlock() {
    for(const auto& out : _outputs) {
        out->out(_buffer);
    }

    _buffer.clear();
}

Batcher::~Batcher() {
    if (_blockStatus == 0 && !_buffer.empty()) {
        forcedOutBlock();
    }
}
