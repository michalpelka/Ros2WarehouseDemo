
#pragma once

#include <AzCore/Component/Component.h>

#include <Ros2WarehouseDemo/Ros2WarehouseDemoBus.h>

namespace Ros2WarehouseDemo
{
    class Ros2WarehouseDemoSystemComponent
        : public AZ::Component
        , protected Ros2WarehouseDemoRequestBus::Handler
    {
    public:
        AZ_COMPONENT(Ros2WarehouseDemoSystemComponent, "{63403c86-3745-4a1f-a9a5-215f0d9de85b}");

        static void Reflect(AZ::ReflectContext* context);

        static void GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided);
        static void GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible);
        static void GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required);
        static void GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent);

        Ros2WarehouseDemoSystemComponent();
        ~Ros2WarehouseDemoSystemComponent();

    protected:
        ////////////////////////////////////////////////////////////////////////
        // Ros2WarehouseDemoRequestBus interface implementation

        ////////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////////
        // AZ::Component interface implementation
        void Init() override;
        void Activate() override;
        void Deactivate() override;
        ////////////////////////////////////////////////////////////////////////
    };
}
