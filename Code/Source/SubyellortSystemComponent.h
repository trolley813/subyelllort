
#pragma once

#include <AzCore/Component/Component.h>

#include <Subyellort/SubyellortBus.h>

namespace Subyellort
{
    class SubyellortSystemComponent
        : public AZ::Component
        , protected SubyellortRequestBus::Handler
    {
    public:
        AZ_COMPONENT(SubyellortSystemComponent, "{583a6ffe-bdb4-47a2-969a-23efdbda3ed2}");

        static void Reflect(AZ::ReflectContext* context);

        static void GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided);
        static void GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible);
        static void GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required);
        static void GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent);

        SubyellortSystemComponent();
        ~SubyellortSystemComponent();

    protected:
        ////////////////////////////////////////////////////////////////////////
        // SubyellortRequestBus interface implementation

        ////////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////////
        // AZ::Component interface implementation
        void Init() override;
        void Activate() override;
        void Deactivate() override;
        ////////////////////////////////////////////////////////////////////////
    };
}
