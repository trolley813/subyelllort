
#include <AzCore/Serialization/SerializeContext.h>
#include <AzCore/Serialization/EditContext.h>
#include <AzCore/Serialization/EditContextConstants.inl>

#include "SubyellortSystemComponent.h"

namespace Subyellort
{
    void SubyellortSystemComponent::Reflect(AZ::ReflectContext* context)
    {
        if (AZ::SerializeContext* serialize = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serialize->Class<SubyellortSystemComponent, AZ::Component>()
                ->Version(0)
                ;

            if (AZ::EditContext* ec = serialize->GetEditContext())
            {
                ec->Class<SubyellortSystemComponent>("Subyellort", "[Description of functionality provided by this System Component]")
                    ->ClassElement(AZ::Edit::ClassElements::EditorData, "")
                        ->Attribute(AZ::Edit::Attributes::AppearsInAddComponentMenu, AZ_CRC("System"))
                        ->Attribute(AZ::Edit::Attributes::AutoExpand, true)
                    ;
            }
        }
    }

    void SubyellortSystemComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC("SubyellortService"));
    }

    void SubyellortSystemComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        incompatible.push_back(AZ_CRC("SubyellortService"));
    }

    void SubyellortSystemComponent::GetRequiredServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& required)
    {
    }

    void SubyellortSystemComponent::GetDependentServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
    }
    
    SubyellortSystemComponent::SubyellortSystemComponent()
    {
        if (SubyellortInterface::Get() == nullptr)
        {
            SubyellortInterface::Register(this);
        }
    }

    SubyellortSystemComponent::~SubyellortSystemComponent()
    {
        if (SubyellortInterface::Get() == this)
        {
            SubyellortInterface::Unregister(this);
        }
    }

    void SubyellortSystemComponent::Init()
    {
    }

    void SubyellortSystemComponent::Activate()
    {
        SubyellortRequestBus::Handler::BusConnect();
    }

    void SubyellortSystemComponent::Deactivate()
    {
        SubyellortRequestBus::Handler::BusDisconnect();
    }
}
