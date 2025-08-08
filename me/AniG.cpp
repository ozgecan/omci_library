//
// Created by Ozge Ayaz on 7/21/25.
//

#include "AniG.h"

namespace omci {
    AniG::AniG(uint16_t entityId, bool srIndication, uint8_t totalTcontNumber, uint16_t gemBlockLength)
    : entityId_(entityId),
    srIndication_(srIndication),
    totalTcontNumber_(totalTcontNumber),
    gemBlockLength_(gemBlockLength){}

    std::vector<uint8_t> AniG::SerializeAttributes() const {
        std::vector<uint8_t> result;
        result.push_back(srIndication_ ? 1 : 0);
        result.push_back(totalTcontNumber_);
        result.push_back((gemBlockLength_ >> 8) & 0xFF);
        result.push_back(gemBlockLength_ & 0xFF);
        return result;
    }
} // omci