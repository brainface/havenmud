#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <armour_class.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
   armour::create();
   SetKeyName("pants");
   SetShort("a pair of leather pants");
   SetId( ({ "pants" }) );
   SetAdjectives( ({ "pair of","leather" }) );
   SetLong("The pants are a strong black leather sewn together "
           "with great talent.  Silver-gold buttons shaped "
           "like dragons make the pants easy to put on and "
           "take off, as well as adding to the value.");
   SetMass(25);
   SetArmourType(A_PANTS);
    SetArmourClass(ARMOUR_LEATHER);
   SetValue(355);
   SetClass(10,9);
   SetVendorType(VT_ARMOUR);
   SetDamagePoints(250);
   SetMaterial( ({ "leather","metal" }) );
   SetWarmth(20);
   SetRepairDifficulty(12);
   SetRepairSkills( ([
                       "leather working" : 0,
                       "metal working" : 0,
                  ]) );
}
