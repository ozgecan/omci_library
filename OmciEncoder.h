//
// Created by Ozge Ayaz on 7/21/25.
//

#ifndef OMCI_LIBRARY_OMCIENCODER_H
#define OMCI_LIBRARY_OMCIENCODER_H

#pragma once
#include <vector>
#include <cstdint>
#include <map>

namespace omci {
    using AttributeMask = uint16_t;

    std::vector<uint8_t> EncodeCreateBody(uint16_t classId, uint16_t entityId, const std::vector<uint8_t>& attributes);
    std::vector<uint8_t> EncodeSetBody(uint16_t classId, uint16_t entityId, AttributeMask mask, const std::vector<uint8_t>& attributes);
    std::vector<uint8_t> EncodeGetBody(uint16_t classId, uint16_t entityId, AttributeMask mask);

    class OmciEncoder {

    };

} // omci

#endif //OMCI_LIBRARY_OMCIENCODER_H
