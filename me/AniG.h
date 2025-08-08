//
// Created by Ozge Ayaz on 7/21/25.
//

#ifndef OMCI_LIBRARY_ANIG_H
#define OMCI_LIBRARY_ANIG_H

#pragma once
#include <vector>
#include <cstdint>

namespace omci {

    class AniG {
    private:
        uint16_t entityId_;
        bool srIndication_;
        uint8_t totalTcontNumber_;
        uint16_t gemBlockLength_;

    public:
        AniG(uint16_t entityId,
             bool srIndication,
             uint8_t totalTcontNumber,
             uint16_t gemBlockLength);

        std::vector<uint8_t> SerializeAttributes() const;
        uint16_t GetEntityId() const { return entityId_;}
        static constexpr uint16_t ClassId() {return 0x0002;}
        enum AttributeMask: uint16_t {
            SR_INDICATION                = 0x0002,
            TOTAL_TCONT_NUMBER           = 0x0004,
            GEM_BLOCK_LENGTH             = 0x0008,
            DEPRECATED                   = 0x0010,
            PIGGYBACK_DBA_REPORTING      = 0x0020,
            SF_THRESHOLD                 = 0x0040,
            SD_THRESHOLD                 = 0x0080,
            ARC                          = 0x0100,
            ARC_INTERVAL                 = 0x0200,
            ONU_RESPONSE_TIMEOUT         = 0x0400,
            TX_OPTICAL_LEVEL             = 0x0800,
            RX_OPTICAL_LEVEL             = 0x1000,
            LOWER_RX_OPTICAL_THRESHOLD  = 0x2000,
            UPPER_RX_OPTICAL_THRESHOLD  = 0x4000,
            ONU_POWER_SUPPLY             = 0x8000
        };
    };

} // omci

#endif //OMCI_LIBRARY_ANIG_H
