#include "OmciMessage.h"
#include "OmciEncoder.h"
#include <iostream>
#include <iomanip>
// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
void printHex(const std::vector<uint8_t>& data) {
    std::cout << "Hex: ";
    for (uint8_t byte : data) {
        std::cout << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(byte) << " ";
    }
    std::cout << std::dec << "\n";
}

void test1() {
    omci::OmciMessage msg;
    msg.transactionId = 0x1234;
    msg.messageType = omci::OmciMessageType::Get;
    msg.deviceId = 0x0A;
    msg.payload = std::vector<uint8_t>(32, 0x00);  // dummy payload

    auto encoded = msg.Serialize();

    auto decoded = omci::OmciMessage::Deserialize(encoded);

    std::cout << "TX ID: " << std::hex << decoded.transactionId << "\n";
    std::cout << "Msg Type: " << static_cast<int>(decoded.messageType) << "\n";
    std::cout << "Payload size: " << decoded.payload.size() << "\n";
}

void test2() {
    uint16_t classId = 0x002;       // ANI-G
    uint16_t entityId = 0x100;      // Instance
    omci::AttributeMask mask = 0x0004;    // e.g., only attribute 3
    std::vector<uint8_t> attrs = {0x00, 0x10};  // Dummy values

    omci::OmciMessage createMsg {
            .transactionId = 0x1001,
            .messageType = omci::OmciMessageType::Create,
            .deviceId = 0x0A,
            .payload = omci::EncodeCreateBody(classId, entityId, attrs)
    };

    omci::OmciMessage setMsg {
            .transactionId = 0x1002,
            .messageType = omci::OmciMessageType::Set,
            .deviceId = 0x0A,
            .payload = omci::EncodeSetBody(classId, entityId, mask, attrs)
    };

    omci::OmciMessage getMsg {
            .transactionId = 0x1003,
            .messageType = omci::OmciMessageType::Get,
            .deviceId = 0x0A,
            .payload = omci::EncodeGetBody(classId, entityId, mask)
    };

    std::cout << "[Create] Serialized OMCI:\n";
    printHex(createMsg.Serialize());

    std::cout << "[Set] Serialized OMCI:\n";
    printHex(setMsg.Serialize());

    std::cout << "[Get] Serialized OMCI:\n";
    printHex(getMsg.Serialize());
}

int main() {
    test1();
    test2();
}