//
// Created by Ozge Ayaz on 7/21/25.
//

#ifndef OMCI_LIBRARY_ENTITYFACTORY_H
#define OMCI_LIBRARY_ENTITYFACTORY_H

#pragma once
#include <cstdint>
#include <memory>
#include <functional>
#include <unordered_map>
#include "ManagedEntity.h"

namespace omci {

    class EntityFactory {
    public:
        using Creator = std::function<std::shared_ptr<ManagedEntity>(uint16_t entityId)>;
        static EntityFactory& Instance();
        void Register(uint16_t classId, Creator creator);
        std::shared_ptr<ManagedEntity> Create(uint16_t classId, uint16_t entityId);

    private:
        std::unordered_map<uint16_t, Creator> registry_;
        EntityFactory() = default;
    };

} // omci

#endif //OMCI_LIBRARY_ENTITYFACTORY_H
