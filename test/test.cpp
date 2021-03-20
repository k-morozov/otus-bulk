//
// Created by focus on 20.03.2021.
//

#include <gtest/gtest.h>
#include "bulk/Bulk.h"

class MainTest : public ::testing::Test {
protected:
    void SetUp() {
        count = 3;
    }

    int count = 3;
    std::ostringstream sout;
};

TEST_F(MainTest, exampleFirstTest) {
    std::istringstream sin("cmd1\ncmd2\ncmd3\n");

    Settings settings(sin, sout, sout, count);
    auto bulkPtr = std::make_unique<Bulk>(settings);
    bulkPtr->run();

    const std::string expected = "bulk: cmd1 cmd2 cmd3\n";
    const std::string result = sout.str();

    ASSERT_TRUE(result.compare(expected));
}

TEST_F(MainTest, moreOneBuffer) {
    std::istringstream sin("cmd1\ncmd2\ncmd3\ncmd4\n");

    Settings settings(sin, sout, sout, count);
    auto bulkPtr = std::make_unique<Bulk>(settings);
    bulkPtr->run();

    const std::string expected = "bulk: cmd1 cmd2 cmd3\n";
    const std::string result = sout.str();

    ASSERT_TRUE(result.compare(expected));
}

TEST_F(MainTest, moreTwoBuffer) {
    std::istringstream sin("cmd1\ncmd2\ncmd3\ncmd4\ncmd5\n");

    Settings settings(sin, sout, sout, count);
    auto bulkPtr = std::make_unique<Bulk>(settings);
    bulkPtr->run();

    const std::string expected = "bulk: cmd1 cmd2 cmd3\n";
    const std::string result = sout.str();

    ASSERT_TRUE(result.compare(expected));
}

TEST_F(MainTest, moreThreeBuffer) {
    std::istringstream sin("cmd1\ncmd2\ncmd3\ncmd4\ncmd5\ncmd6\n");

    Settings settings(sin, sout, sout, count);
    auto bulkPtr = std::make_unique<Bulk>(settings);
    bulkPtr->run();

    const std::string expected = "bulk: cmd1 cmd2 cmd3\nbulk: cmd4 cmd5 cmd6\n";
    const std::string result = sout.str();

    ASSERT_TRUE(result.compare(expected));
}

TEST_F(MainTest, moreOneBufferOverTwo) {
    std::istringstream sin("cmd1\ncmd2\ncmd3\ncmd4\ncmd5\ncmd6\ncmd7\n");

    Settings settings(sin, sout, sout, count);
    auto bulkPtr = std::make_unique<Bulk>(settings);
    bulkPtr->run();

    const std::string expected = "bulk: cmd1 cmd2 cmd3\nbulk: cmd4 cmd5 cmd6\n";
    const std::string result = sout.str();

    ASSERT_TRUE(result.compare(expected));
}
