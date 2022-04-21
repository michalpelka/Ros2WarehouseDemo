
#pragma once

#include <AzCore/EBus/EBus.h>
#include <AzCore/Interface/Interface.h>

namespace Ros2WarehouseDemo
{
    class Ros2WarehouseDemoRequests
    {
    public:
        AZ_RTTI(Ros2WarehouseDemoRequests, "{6cf2ea60-22f0-435e-892e-1620b6d403fa}");
        virtual ~Ros2WarehouseDemoRequests() = default;
        // Put your public methods here
    };

    class Ros2WarehouseDemoBusTraits
        : public AZ::EBusTraits
    {
    public:
        //////////////////////////////////////////////////////////////////////////
        // EBusTraits overrides
        static constexpr AZ::EBusHandlerPolicy HandlerPolicy = AZ::EBusHandlerPolicy::Single;
        static constexpr AZ::EBusAddressPolicy AddressPolicy = AZ::EBusAddressPolicy::Single;
        //////////////////////////////////////////////////////////////////////////
    };

    using Ros2WarehouseDemoRequestBus = AZ::EBus<Ros2WarehouseDemoRequests, Ros2WarehouseDemoBusTraits>;
    using Ros2WarehouseDemoInterface = AZ::Interface<Ros2WarehouseDemoRequests>;

} // namespace Ros2WarehouseDemo
