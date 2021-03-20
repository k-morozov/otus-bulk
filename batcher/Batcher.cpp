//
// Created by focus on 20.03.2021.
//

#include "Batcher.h"

Batcher::Batcher(int count) : maxSizeBuffer(count){

}

void Batcher::addOutputs(writerPtrType newOutput) {
    if (!newOutput) {
        throw std::invalid_argument("newOuput is null");
    }

    _outputs.push_back(newOutput);
}

void Batcher::addCommand(const std::string &command) {
    _buffer.push_back(command);
    if (_buffer.size() == maxSizeBuffer) {
            for(const auto& out : _outputs) {
                out->out(_buffer);
            }

        _buffer.clear();
    }
}
