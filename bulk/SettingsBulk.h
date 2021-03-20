//
// Created by focus on 20.03.2021.
//

#ifndef OTUS_BULK_SETTINGSBULK_H
#define OTUS_BULK_SETTINGSBULK_H

#include <iostream>

struct Settings {
    Settings() = delete;

    Settings(
            std::istream& from,
            std::ostream& toConsole,
            std::ostream& toFile,
            int sizeBuffer):
                from(from),
                toConsole(toConsole),
                toFile(toFile),
                sizeBuffer(sizeBuffer) {
    }

    Settings(const Settings & settings):
        from(settings.from),
        toConsole(settings.toConsole),
        toFile(settings.toFile),
        sizeBuffer(settings.sizeBuffer) {
    }

    std::istream& from;
    std::ostream& toConsole;
    std::ostream& toFile;
    int sizeBuffer;
};
#endif //OTUS_BULK_SETTINGSBULK_H
