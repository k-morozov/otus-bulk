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
};

TEST_F(BlockTest, exampleFromTask) {
    std::string text = "cmd1\ncmd2\n{\ncmd3\ncmd4\n}\n{\ncmd5\ncmd6\n{\ncmd7\ncmd8\n}\ncmd9\n}\n";
    std::istringstream sin(text);

    Settings settings(sin, sout, sout, count);
    auto bulkPtr = std::make_unique<Bulk>(settings);
    bulkPtr->run();

    const std::string expected = "bulk: cmd1 cmd2\nbulk: cmd3 cmd4\nbulk: cmd5 cmd6 cmd7 cmd8 cmd9\n";
    const std::string result = sout.str();

    ASSERT_TRUE(result.compare(expected));
}