//
// Created by Ozge Ayaz on 7/21/25.
//

#ifndef OMCI_LIBRARY_MANAGEDENTITY_H
#define OMCI_LIBRARY_MANAGEDENTITY_H

#pragma once
#include <vector>
#include <cstdint>

namespace omci {

    class ManagedEntity {
    public:
        virtual ~ManagedEntity() = default;

        virtual uint16_t GetClassId() const = 0;
        virtual uint16_t GetEntityId() const = 0;
        virtual std::vector<uint8_t> SerializeAttributes() const = 0;
    };

} // omci


#endif //OMCI_LIBRARY_MANAGEDENTITY_H
