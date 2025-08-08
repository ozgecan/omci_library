//
// Created by Ozge Ayaz on 7/21/25.
//
#include "../me/OntG.h"
#include <gtest/gtest.h>
#include <vector>

using namespace omci;

TEST(OntGTest, SerializeAttributesProducesCorrectBytes) {
    uint16_t entityId = 0x0100;
    uint16_t vendorId = 0x1234;
    uint16_t version = 0x0101;
    uint16_t serialNumber = 0xABCD;

    OntG ontg(entityId, vendorId, version, serialNumber);
    std::vector<uint8_t> data = ontg.SerializeAttributes();
    std::vector<uint8_t> expected = {
            0x12, 0x34, // vendorId
            0x01, 0x01, // version
            0xAB, 0xCD  // serialNumber
    };

    EXPECT_EQ(data, expected);
}
