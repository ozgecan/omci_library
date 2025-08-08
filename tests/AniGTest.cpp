//
// Created by Ozge Ayaz on 7/21/25.
//

#include "../me/AniG.h"
#include <gtest/gtest.h>

using namespace omci;

TEST(AniGTest, SerializeAttributesProducesCorrectBytes) {
uint16_t entityId = 0x0100;
bool sr = true;
uint8_t tcont = 4;
uint16_t gemBlockLen = 48;
AniG ani(entityId, sr, tcont, gemBlockLen);
std::vector<uint8_t> serialized = ani.SerializeAttributes();
std::vector<uint8_t> expected = {0x01, 0x04, 0x00, 0x30};

EXPECT_EQ(serialized.size(), expected.size());
EXPECT_EQ(serialized, expected);
}

