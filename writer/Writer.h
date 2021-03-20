//
// Created by focus on 20.03.2021.
//

#ifndef OTUS_BULK_WRITER_H
#define OTUS_BULK_WRITER_H

#include <string>
#include <memory>
#include <vector>

class Writer;
using commandsType = std::vector<std::string>;
using writerPtrType = std::shared_ptr<Writer>;

class Writer {
public:
    virtual void out(const commandsType&) = 0;
};

#endif //OTUS_BULK_WRITER_H
