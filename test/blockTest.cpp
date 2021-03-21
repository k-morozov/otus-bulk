//
// Created by focus on 21.03.2021.
//

#include <gtest/gtest.h>
#include "bulk/Bulk.h"

class BlockTest : public ::testing::Test {
protected:
    void SetUp() {
        count = 3;
    }

    int count = 3;
    std::ostringstream sout;
    std::stringstream ss;
};

TEST_F(BlockTest, exampleFromTaskDemo) {
    ss << "cmd1\n";
    ss << "cmd2\n";
    ss << "{\n";
    ss << "cmd3\n";
    ss << "cmd4\n";
    ss << "}\n";
    ss << "{\n";
    ss << "cmd5\n";
    ss << "cmd6\n";
    ss << "{\n";
    ss << "cmd7\n";
    ss << "cmd8\n";
    ss << "}\n";
    ss << "cmd9\n";
    ss << "}\n";

    Settings settings(ss, sout, sout, count);
    auto bulkPtr = std::make_unique<Bulk>(settings);
    bulkPtr->run();

    const std::string expected = "bulk: cmd1, cmd2\nbulk: cmd3, cmd4\nbulk: cmd5, cmd6, cmd7, cmd8, cmd9\n";
    const std::string result = sout.str();
    EXPECT_STREQ(result.c_str(), expected.c_str());
}

TEST_F(BlockTest, exampleFromTask) {
    ss << "cmd1\n";
    ss << "cmd2\n";
    ss << "{\n";
    ss << "cmd3\n";
    ss << "cmd4\n";
    ss << "}\n";
    ss << "{\n";
    ss << "cmd5\n";
    ss << "cmd6\n";
    ss << "{\n";
    ss << "cmd7\n";
    ss << "cmd8\n";
    ss << "}\n";
    ss << "cmd9\n";
    ss << "}\n";
    ss << "{\n";
    ss << "cmd10\n";
    ss << "cmd11\n";

    Settings settings(ss, sout, sout, count);
    auto bulkPtr = std::make_unique<Bulk>(settings);
    bulkPtr->run();

    const std::string expected = "bulk: cmd1, cmd2\nbulk: cmd3, cmd4\nbulk: cmd5, cmd6, cmd7, cmd8, cmd9\n";
    const std::string result = sout.str();

    EXPECT_STREQ(result.c_str(), expected.c_str());
}