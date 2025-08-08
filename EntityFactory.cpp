//
// Created by Ozge Ayaz on 7/21/25.
//

#include "EntityFactory.h"

namespace omci {
    EntityFactory& EntityFactory::Instance() {
        static EntityFactory instance;
        return instance;
    }

    void EntityFactory::Register(uint16_t classId, omci::EntityFactory::Creator creator) {
        registry_[classId] = creator;
    }

    std::shared_ptr<ManagedEntity> EntityFactory::Create(uint16_t classId, uint16_t entityId) {
        auto it = registry_.find(classId);
        if( it!= registry_.end()) {
            return it->second(entityId);
        }
        return nullptr;
    }
} // omci