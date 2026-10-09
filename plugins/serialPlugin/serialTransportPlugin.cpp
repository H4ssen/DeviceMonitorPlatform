#include <QString>
#include "serialTransportPlugin.h"
#include "IDeviceTransport.h"
#include "serialTransport.h"


std::unique_ptr<IDeviceTransport> create(const TransportConfig& config) {
    return std::make_unique<SerialTransport>(config);
}
