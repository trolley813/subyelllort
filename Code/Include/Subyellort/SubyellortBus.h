
#pragma once

#include <AzCore/EBus/EBus.h>
#include <AzCore/Interface/Interface.h>

namespace Subyellort
{
    class SubyellortRequests
    {
    public:
        AZ_RTTI(SubyellortRequests, "{aa326adc-f693-4cbe-83c1-a094e5210288}");
        virtual ~SubyellortRequests() = default;
        // Put your public methods here
    };
    
    class SubyellortBusTraits
        : public AZ::EBusTraits
    {
    public:
        //////////////////////////////////////////////////////////////////////////
        // EBusTraits overrides
        static constexpr AZ::EBusHandlerPolicy HandlerPolicy = AZ::EBusHandlerPolicy::Single;
        static constexpr AZ::EBusAddressPolicy AddressPolicy = AZ::EBusAddressPolicy::Single;
        //////////////////////////////////////////////////////////////////////////
    };

    using SubyellortRequestBus = AZ::EBus<SubyellortRequests, SubyellortBusTraits>;
    using SubyellortInterface = AZ::Interface<SubyellortRequests>;

} // namespace Subyellort
