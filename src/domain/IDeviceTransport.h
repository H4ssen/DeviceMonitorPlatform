#pragma once


class IDeviceTransport {


    public:
        virtual ~IDeviceTransport() = default;
        virtual bool connect()  = 0;
        virtual bool disconnect()  = 0;
};