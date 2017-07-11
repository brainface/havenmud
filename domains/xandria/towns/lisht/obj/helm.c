//Selket@Haven
//2006
#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
#include <vendor_types.h>
 inherit LIB_ARMOUR;

static void create() {
    armour::create();
    SetKeyName("helm");
    SetId( ({ "helm","helmet" }) );
    SetAdjectives( ({ "metal","heavy" }) );
    SetShort("a metal helm");
    SetLong("This is a heavy metal helm designed to keep the "
            "weather and weapons from hitting one's head. ");
    SetDamagePoints(3000);
    SetVendorType(VT_ARMOUR);
    SetArmourClass(ARMOUR_CHAIN);
    SetMass(300);
    SetValue(300);
    SetArmourType(A_HELMET);
    SetMaterial( ({ "metal" }) );
    SetWarmth(3);
}
