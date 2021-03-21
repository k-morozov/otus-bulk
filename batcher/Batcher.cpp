//
// Created by focus on 20.03.2021.
//

#include "Batcher.h"

Batcher::Batcher(int count) : maxSizeBuffer(count), _blockStatus(0){

}

void Batcher::addOutputs(writerPtrType newOutput) {
    if (!newOutput) {
        throw std::invalid_argument("newOutput is null");
    }

    _outputs.push_back(newOutput);
}

void Batcher::addCommand(const std::string &command) {
    if (command == "{") {
        if (_blockStatus == 0 && !_buffer.empty()) {
            forcedOutBlock();
        }
        ++_blockStatus;
    } else if (command == "}") {
        --_blockStatus;
        if (_blockStatus == 0 && !_buffer.empty()) {
            forcedOutBlock();
        }
    } else {
        _buffer.push_back(command);
        if (_blockStatus == 0 && _buffer.size() == maxSizeBuffer) {
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
