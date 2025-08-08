//
// Created by Ozge Ayaz on 7/21/25.
//

#include "OntG.h"

namespace omci {
    OntG::OntG(uint16_t entityId, uint16_t vendorId, uint16_t version, uint16_t serialNumber)
            : entityId_(entityId), vendorId_(vendorId), version_(version), serialNumber_(serialNumber) {}

    uint16_t OntG::GetClassId() const {
        return CLASS_ID;
    }

    uint16_t OntG::GetEntityId() const {
        return entityId_;
    }

    std::vector<uint8_t> OntG::SerializeAttributes() const {
        std::vector<uint8_t> data;
        data.push_back((vendorId_ >> 8) & 0xFF);
        data.push_back(vendorId_ & 0xFF);
        data.push_back((version_ >> 8) & 0xFF);
        data.push_back(version_ & 0xFF);
        data.push_back((serialNumber_ >> 8) & 0xFF);
        data.push_back(serialNumber_ & 0xFF);
        return data;
    }

// Static registration block
    namespace {
        struct OntGRegistrar {
            OntGRegistrar() {
                EntityFactory::Instance().Register(OntG::CLASS_ID, [](uint16_t entityId) {
                    return std::make_shared<OntG>(entityId, 0xAAAA, 0x0101, 0x1234);
                });
            }
        } _ontg_registrar;
    }
} // omci