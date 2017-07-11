#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <armour_class.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
   armour::create();
   SetKeyName("boots");
   SetShort("a pair of leather boots");
   SetId( ({ "boots","boot" }) );
   SetAdjectives( ({ "pair of","leather" }) );
   SetLong("The boots are made of a tough leather and "
           "have various decorations stiched on to the "
           "outside that add to their value.  The inside "
           "is soft and comfortable.");
   SetMass(35);
    SetArmourClass(ARMOUR_LEATHER);
   SetValue(275);
   SetClass(10,9);
   SetArmourType(A_BOOT);
   SetProperty("multiples",1);
   SetVendorType(VT_ARMOUR);
   SetDamagePoints(210);
   SetMaterial( ({ "leather" }) );
   SetRepairDifficulty(15);
   SetRepairSkills( ([
                       "leather working" : 1,
                  ]) );
}
