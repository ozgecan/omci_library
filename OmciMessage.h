//
// Created by Ozge Ayaz on 7/21/25.
//

#ifndef OMCI_LIBRARY_OMCIMESSAGE_H
#define OMCI_LIBRARY_OMCIMESSAGE_H

#include <cstdint>
#include <vector>

/*  Device Identifier
 *  In baseline OMCI messages, this field is defined to be 0x0A
 *  In extended OMCI messages, this field is defined to be 0X0B
 */

namespace omci {

    enum OmciMessageType: uint8_t {
        Create = 0x04,
        Delete = 0x06,
        Set = 0x08,
        Get = 0x09,
        GetAllAlarms = 0x0B,
        GetAllAlarmsNext = 0x0C,
        MibUpload = 0x0D,
        MibUploadNext = 0x0E,
        MibReset = 0x0F,
        AlarmNotification = 0x10,
        AttributeValueChange = 0x11,
        Test = 0x12,
        StartSoftwareDownload = 0x13,
        DownloadSection = 0x14,
        EndSoftwareDownload = 0x15,
        ActivateSoftware = 0x16,
        CommitSoftware = 0x17,
        SynchronizeTime = 0x18,
        Reboot = 0x19,
        GetNext = 0x1A,
        TestResult = 0x1B,
        GetCurrentData = 0x1C,
        SetTable = 0x1D,   // NOTE: Set table is defined only in the extended message set
    };

    class OmciMessage {
    public:
        uint16_t transactionId;
        OmciMessageType messageType;
        uint8_t deviceId;
        std::vector<uint8_t> payload;

        std::vector<uint8_t> Serialize() const;
        static OmciMessage Deserialize(const std::vector<uint8_t>& data);
    };

} // omci

#endif //OMCI_LIBRARY_OMCIMESSAGE_H
