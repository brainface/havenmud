// Amelia@Haven

#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
#include <armour_types.h>
#include <armour_class.h>

inherit LIB_ARMOUR;

static void create() {
   armour::create();
   SetKeyName("old gold ring");
   SetShort("an old golden ring");
   SetId( ({ "ring","band","gold" }) );
   SetAdjectives( ({ "old","gold","golden" }) );
   SetLong("The ring is a simple band of gold, but large enough to "
           "stand out on one's finger.  It is old looking, as if "
           "its lain around for a long time.");
   SetMass(2);
   SetValue(45);
   SetDamagePoints(125);
   SetArmourType(A_RING);
   SetArmourClass(ARMOUR_CHAIN);
   SetVendorType(VT_TREASURE|VT_ARMOUR);
   // SetProtection(SLASH,4);
   // SetProtection(PIERCE,4);
   // SetProtection(BLUNT,4);
   SetMaterial( ({ "metal" }) );
   SetRepairDifficulty(11);
   SetRepairSkills( ([
                       "armour smithing" : 2,
                       "metal working" : 2,
                  ]) );
}


