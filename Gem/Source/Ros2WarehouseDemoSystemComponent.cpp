
#include <AzCore/Serialization/SerializeContext.h>
#include <AzCore/Serialization/EditContext.h>
#include <AzCore/Serialization/EditContextConstants.inl>

#include "Ros2WarehouseDemoSystemComponent.h"

namespace Ros2WarehouseDemo
{
    void Ros2WarehouseDemoSystemComponent::Reflect(AZ::ReflectContext* context)
    {
        if (AZ::SerializeContext* serialize = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serialize->Class<Ros2WarehouseDemoSystemComponent, AZ::Component>()
                ->Version(0)
                ;

            if (AZ::EditContext* ec = serialize->GetEditContext())
            {
                ec->Class<Ros2WarehouseDemoSystemComponent>("Ros2WarehouseDemo", "[Description of functionality provided by this System Component]")
                    ->ClassElement(AZ::Edit::ClassElements::EditorData, "")
                        ->Attribute(AZ::Edit::Attributes::AppearsInAddComponentMenu, AZ_CRC("System"))
                        ->Attribute(AZ::Edit::Attributes::AutoExpand, true)
                    ;
            }
        }
    }

    void Ros2WarehouseDemoSystemComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC("Ros2WarehouseDemoService"));
    }

    void Ros2WarehouseDemoSystemComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        incompatible.push_back(AZ_CRC("Ros2WarehouseDemoService"));
    }

    void Ros2WarehouseDemoSystemComponent::GetRequiredServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& required)
    {
    }

    void Ros2WarehouseDemoSystemComponent::GetDependentServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
    }

    Ros2WarehouseDemoSystemComponent::Ros2WarehouseDemoSystemComponent()
    {
        if (Ros2WarehouseDemoInterface::Get() == nullptr)
        {
            Ros2WarehouseDemoInterface::Register(this);
        }
    }

    Ros2WarehouseDemoSystemComponent::~Ros2WarehouseDemoSystemComponent()
    {
        if (Ros2WarehouseDemoInterface::Get() == this)
        {
            Ros2WarehouseDemoInterface::Unregister(this);
        }
    }

    void Ros2WarehouseDemoSystemComponent::Init()
    {
    }

    void Ros2WarehouseDemoSystemComponent::Activate()
    {
        Ros2WarehouseDemoRequestBus::Handler::BusConnect();
    }

    void Ros2WarehouseDemoSystemComponent::Deactivate()
    {
        Ros2WarehouseDemoRequestBus::Handler::BusDisconnect();
    }
}
