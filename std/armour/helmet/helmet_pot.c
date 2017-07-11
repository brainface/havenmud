#include <lib.h>
#include <damage_types.h>
#include <armour_types.h>
#include <vendor_types.h>
#include <armour_class.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
   armour::create();
   SetKeyName("cooking pot helmet");
   SetShort("a cooking pot helmet");
   SetId( ({ "helmet","pot","pot helmet" }) );
   SetAdjectives( ({ "cooking" }) );
   SetLong("The cooking pot helmet is such that any child could see "
           "exactly how it is part of a knight's suit of armour, but "
           "never be able to explain how.  It gleams dully beneath "
           "its years, and the stubby handle has a tarnished glare.");
   SetMass(15);
   SetValue(5);
  SetArmourClass(ARMOUR_REINFORCED);
   SetVendorType(VT_ARMOUR);
  SetSize(SIZE_MEDIUM);
   SetArmourType(A_HELMET);
   SetDamagePoints(250);
   SetMaterial( ({ "metal" }) );
   SetWarmth(0);
   SetRepairDifficulty(5);
   SetRepairSkills( ([
                       "metal working" : 1,
                       "armour smithing" : 1,
                  ]) );
}
