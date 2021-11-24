
#include <AzCore/Memory/SystemAllocator.h>
#include <AzCore/Module/Module.h>

#include "SubyellortSystemComponent.h"

namespace Subyellort
{
    class SubyellortModule
        : public AZ::Module
    {
    public:
        AZ_RTTI(SubyellortModule, "{d7ce07d5-6f96-4558-8efd-105648f75d52}", AZ::Module);
        AZ_CLASS_ALLOCATOR(SubyellortModule, AZ::SystemAllocator, 0);

        SubyellortModule()
            : AZ::Module()
        {
            // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
            m_descriptors.insert(m_descriptors.end(), {
                SubyellortSystemComponent::CreateDescriptor(),
            });
        }

        /**
         * Add required SystemComponents to the SystemEntity.
         */
        AZ::ComponentTypeList GetRequiredSystemComponents() const override
        {
            return AZ::ComponentTypeList{
                azrtti_typeid<SubyellortSystemComponent>(),
            };
        }
    };
}// namespace Subyellort

AZ_DECLARE_MODULE_CLASS(Gem_Subyellort, Subyellort::SubyellortModule)
