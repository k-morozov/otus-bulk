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
    std::stringstream ss;
};

TEST_F(MainTest, exampleFirstTest) {
    ss << "cmd1\n";
    ss << "cmd2\n";
    ss << "cmd3\n";

    Settings settings(ss, sout, sout, count);
    auto bulkPtr = std::make_unique<Bulk>(settings);
    bulkPtr->run();

    const std::string expected = "bulk: cmd1, cmd2, cmd3\n";
    const std::string result = sout.str();

    EXPECT_STREQ(result.c_str(), expected.c_str());
}

TEST_F(MainTest, moreOneBuffer) {
    ss << "cmd1\n";
    ss << "cmd2\n";
    ss << "cmd3\n";
    ss << "cmd4\n";

    Settings settings(ss, sout, sout, count);
    auto bulkPtr = std::make_unique<Bulk>(settings);
    bulkPtr->run();

    const std::string expected = "bulk: cmd1, cmd2, cmd3\nbulk: cmd4\n";
    const std::string result = sout.str();

    EXPECT_STREQ(result.c_str(), expected.c_str());
}

TEST_F(MainTest, moreTwoBuffer) {
    ss << "cmd1\n";
    ss << "cmd2\n";
    ss << "cmd3\n";
    ss << "cmd4\n";
    ss << "cmd5\n";

    Settings settings(ss, sout, sout, count);
    auto bulkPtr = std::make_unique<Bulk>(settings);
    bulkPtr->run();

    const std::string expected = "bulk: cmd1, cmd2, cmd3\nbulk: cmd4, cmd5\n";
    const std::string result = sout.str();

    EXPECT_STREQ(result.c_str(), expected.c_str());
}

TEST_F(MainTest, moreThreeBuffer) {
    ss << "cmd1\n";
    ss << "cmd2\n";
    ss << "cmd3\n";
    ss << "cmd4\n";
    ss << "cmd5\n";
    ss << "cmd6\n";

    Settings settings(ss, sout, sout, count);
    auto bulkPtr = std::make_unique<Bulk>(settings);
    bulkPtr->run();

    const std::string expected = "bulk: cmd1, cmd2, cmd3\nbulk: cmd4, cmd5, cmd6\n";
    const std::string result = sout.str();

    EXPECT_STREQ(result.c_str(), expected.c_str());
}

TEST_F(MainTest, moreOneBufferOverTwo) {
    ss << "cmd1\n";
    ss << "cmd2\n";
    ss << "cmd3\n";
    ss << "cmd4\n";
    ss << "cmd5\n";
    ss << "cmd6\n";
    ss << "cmd7\n";

    Settings settings(ss, sout, sout, count);
    auto bulkPtr = std::make_unique<Bulk>(settings);
    bulkPtr->run();

    const std::string expected = "bulk: cmd1, cmd2, cmd3\nbulk: cmd4, cmd5, cmd6\nbulk: cmd7\n";
    const std::string result = sout.str();

    EXPECT_STREQ(result.c_str(), expected.c_str());
}
