//
// Created by focus on 20.03.2021.
//

#ifndef OTUS_BULK_BULK_H
#define OTUS_BULK_BULK_H

#include <memory>
#include <bulk/SettingsBulk.h>


class Bulk {
public:
    explicit Bulk(const Settings& settings);

    void run();

private:
    Settings _settings;
};


#endif //OTUS_BULK_BULK_H
