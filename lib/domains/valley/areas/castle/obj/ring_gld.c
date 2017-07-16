// Amelia@Haven
#include <size.h>
#include <lib.h>
#include <vendor_types.h>
#include <armour_class.h>
#include <damage_types.h>
#include <armour_types.h>
inherit LIB_ARMOUR;

static void create() {
   armour::create();
   SetKeyName("ring");
   SetShort("a golden ring");
   SetId( ({ "ring","band","gold" }) );
   SetAdjectives( ({ "gold","golden" }) );
   SetLong("The ring is a simple band of gold, but large enough to "
           "stand out on one's finger.");
   SetMass(2);
   SetValue(65);
   SetDamagePoints(300);
   SetArmourType(A_RING);
  SetArmourClass(ARMOUR_CHAIN);
   SetVendorType(VT_TREASURE|VT_ARMOUR);
   // SetProtection(SLASH,3);
   SetMaterial( ({ "metal" }) );
   SetRepairDifficulty(7);
   SetRepairSkills( ([
                       "armour smithing" : 1,
                       "metal working" : 1,
                  ]) );
   SetSize(SIZE_SMALL);
}
