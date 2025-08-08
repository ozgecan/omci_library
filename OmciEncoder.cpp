//
// Created by Ozge Ayaz on 7/21/25.
//

#include "OmciEncoder.h"

namespace omci {
    std::vector<uint8_t> EncodeCreateBody(uint16_t classId, uint16_t entityId, const std::vector<uint8_t>& attributes) {
        std::vector<uint8_t> body;
        body.push_back((classId >> 8) & 0xFF);
        body.push_back(classId & 0xFF);
        body.push_back((entityId >> 8) & 0xFF);
        body.push_back(entityId & 0xFF);

        body.insert(body.end(), attributes.begin(), attributes.end());

        return body;
    }
    std::vector<uint8_t> EncodeSetBody(uint16_t classId, uint16_t entityId, AttributeMask mask, const std::vector<uint8_t>& attributes) {
        std::vector<uint8_t> body;
        body.push_back((classId >> 8) & 0xFF);
        body.push_back(classId & 0xFF);

        body.push_back((entityId >> 8) & 0xFF);
        body.push_back(entityId & 0xFF);

        body.push_back((mask >> 8) & 0xFF);
        body.push_back(mask & 0xFF);

        body.insert(body.end(), attributes.begin(), attributes.end());

        return body;
    }

    std::vector<uint8_t> EncodeGetBody(uint16_t classId, uint16_t entityId, AttributeMask mask) {
        std::vector<uint8_t> body;
        body.push_back((classId >> 8) & 0xFF);
        body.push_back(classId & 0xFF);

        body.push_back((entityId >> 8) & 0xFF);
        body.push_back(entityId & 0xFF);

        body.push_back((mask >> 8) & 0xFF);
        body.push_back(mask & 0xFF);

        return body;
    }
} // omci