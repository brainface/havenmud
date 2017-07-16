#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <size.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
   armour::create();
   SetKeyName("cotton maid hat");
   SetId( ({ "hat" }) );
   SetAdjectives( ({ "cotton", "maid" }) );
   SetShort("a cotton maid hat");
   SetLong("The hat is made of a black and white cotton. It simply sits "
           "right on top of ones head.");
   SetVendorType(VT_ARMOUR);
   SetMass(10);
  SetSize(SIZE_MEDIUM);
  SetArmourClass(ARMOUR_CLOTH);
   SetValue(150);
   SetDamagePoints(5000);
   SetMaterial( ({ "textile" }) );
   SetArmourType(A_HELMET);
  SetWarmth(5);
   SetRepairDifficulty(200);
   SetRepairSkills( ([
                       "textile working" : 200,
                       "armour smithing" : 200,
                  ]) );
}
