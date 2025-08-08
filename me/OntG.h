//
// Created by Ozge Ayaz on 7/21/25.
//

#ifndef OMCI_LIBRARY_ONTG_H
#define OMCI_LIBRARY_ONTG_H

#pragma once
#include "../ManagedEntity.h"
#include "../EntityFactory.h"
#include <vector>
#include <cstdint>
namespace omci {

    class OntG : public ManagedEntity {
    public:
        OntG(uint16_t entityId,
             uint16_t vendorId,
             uint16_t version,
             uint16_t serialNumber);

        uint16_t GetClassId() const override;
        uint16_t GetEntityId() const override;
        std::vector<uint8_t> SerializeAttributes() const override;

        static constexpr uint16_t CLASS_ID = 0x0001;

    private:
        uint16_t entityId_;
        uint16_t vendorId_;
        uint16_t version_;
        uint16_t serialNumber_;
    };


} // omci

#endif //OMCI_LIBRARY_ONTG_H
