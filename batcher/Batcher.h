//
// Created by focus on 20.03.2021.
//

#ifndef OTUS_BULK_BATCHER_H
#define OTUS_BULK_BATCHER_H

#include <vector>
#include <memory>
#include "writer/Writer.h"

class Batcher {
public:
    explicit Batcher(int);

    void addOutputs(writerPtrType);

    void addCommand(const std::string&);

    virtual ~Batcher();

private:
    std::vector<writerPtrType> _outputs;
    const int maxSizeBuffer;
    commandsType _buffer;

    int _blockStatus;

    void forcedOutBlock();
};


#endif //OTUS_BULK_BATCHER_H
