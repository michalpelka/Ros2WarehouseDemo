
#include <AzCore/Memory/SystemAllocator.h>
#include <AzCore/Module/Module.h>

#include "Ros2WarehouseDemoSystemComponent.h"

namespace Ros2WarehouseDemo
{
    class Ros2WarehouseDemoModule
        : public AZ::Module
    {
    public:
        AZ_RTTI(Ros2WarehouseDemoModule, "{ce86f590-1dc4-4020-a444-b75d83e27721}", AZ::Module);
        AZ_CLASS_ALLOCATOR(Ros2WarehouseDemoModule, AZ::SystemAllocator, 0);

        Ros2WarehouseDemoModule()
            : AZ::Module()
        {
            // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
            m_descriptors.insert(m_descriptors.end(), {
                Ros2WarehouseDemoSystemComponent::CreateDescriptor(),
            });
        }

        /**
         * Add required SystemComponents to the SystemEntity.
         */
        AZ::ComponentTypeList GetRequiredSystemComponents() const override
        {
            return AZ::ComponentTypeList{
                azrtti_typeid<Ros2WarehouseDemoSystemComponent>(),
            };
        }
    };
}// namespace Ros2WarehouseDemo

AZ_DECLARE_MODULE_CLASS(Gem_Ros2WarehouseDemo, Ros2WarehouseDemo::Ros2WarehouseDemoModule)
