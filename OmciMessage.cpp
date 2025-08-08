//
// Created by Ozge Ayaz on 7/21/25.
//

#include "OmciMessage.h"

namespace omci {

    std::vector<uint8_t> OmciMessage::Serialize() const {
        std::vector<uint8_t> result;
        result.reserve(4+payload.size());

        result.push_back((transactionId >> 8) & 0xFF);
        result.push_back(transactionId & 0xFF);

        result.push_back(static_cast<uint8_t>(messageType));
        result.push_back(deviceId);
        result.insert(result.end(), payload.begin(), payload.end());
        return result;
    }

    OmciMessage OmciMessage::Deserialize(const std::vector<uint8_t> &data) {
        if (data.size() < 4) {
            throw std::runtime_error("OMCI Message too short");
        }

        OmciMessage msg;
        msg.transactionId = (data[0] << 8) | data[1];
        msg.messageType = static_cast<OmciMessageType>(data[2]);
        msg.deviceId = data[3];
        msg.payload.assign(data.begin() + 4, data.end());
        return msg;
    }
} // omci