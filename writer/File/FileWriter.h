//
// Created by focus on 20.03.2021.
//

#ifndef OTUS_BULK_FILEWRITER_H
#define OTUS_BULK_FILEWRITER_H

#include "writer/Writer.h"

class FileWriter : public Writer {
public:
    void out(const commandsType &) override;

private:
//    std::fstream& outStream;
    std::string getFileName(const Command&);
};


#endif //OTUS_BULK_FILEWRITER_H
