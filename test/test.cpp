//
// Created by focus on 20.03.2021.
//

#include <gtest/gtest.h>
#include "bulk/Bulk.h"

TEST(CoreTest, exampleFirstTest) {
    const int count = 3;
    std::istringstream sin("cmd1\ncmd2\ncmd3\n");
    std::ostringstream sout;

    Settings settings(sin, sout, sout, count);
    auto bulkPtr = std::make_unique<Bulk>(settings);
    bulkPtr->run();

    const std::string expected = "bulk: cmd1 cmd2 cmd3\n";
    const std::string result = sout.str();

    ASSERT_TRUE(result.compare(expected));
}

TEST(CoreTest, moreOneBuffer) {
    const int count = 3;
    std::istringstream sin("cmd1\ncmd2\ncmd3\ncmd4\n");
    std::ostringstream sout;

    Settings settings(sin, sout, sout, count);
    auto bulkPtr = std::make_unique<Bulk>(settings);
    bulkPtr->run();

    const std::string expected = "bulk: cmd1 cmd2 cmd3\n";
    const std::string result = sout.str();

    ASSERT_TRUE(result.compare(expected));
}

TEST(CoreTest, moreTwoBuffer) {
    const int count = 3;
    std::istringstream sin("cmd1\ncmd2\ncmd3\ncmd4\ncmd5\n");
    std::ostringstream sout;

    Settings settings(sin, sout, sout, count);
    auto bulkPtr = std::make_unique<Bulk>(settings);
    bulkPtr->run();

    const std::string expected = "bulk: cmd1 cmd2 cmd3\n";
    const std::string result = sout.str();

    ASSERT_TRUE(result.compare(expected));
}

TEST(CoreTest, moreThreeBuffer) {
    const int count = 3;
    std::istringstream sin("cmd1\ncmd2\ncmd3\ncmd4\ncmd5\ncmd6\n");
    std::ostringstream sout;

    Settings settings(sin, sout, sout, count);
    auto bulkPtr = std::make_unique<Bulk>(settings);
    bulkPtr->run();

    const std::string expected = "bulk: cmd1 cmd2 cmd3\nbulk: cmd4 cmd5 cmd6\n";
    const std::string result = sout.str();

    ASSERT_TRUE(result.compare(expected));
}
