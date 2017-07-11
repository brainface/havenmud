#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <size.h>
#include <armour_class.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
   armour::create();
   SetKeyName("knitted sock");
   SetShort("a knitted sock");
   SetId( ({ "sock" }) );
   SetAdjectives( ({ "knitted" }) );
   SetLong("Some grandmother has painstackingly knitted this sock into "
           "a bright, garish design.");
   SetMass(2);
  SetSize(SIZE_MEDIUM);
  SetArmourClass(ARMOUR_CLOTH);
   SetValue(10);
   SetVendorType(VT_ARMOUR);
   SetArmourType(A_SOCK);
   SetDamagePoints(250);
   SetWear("The sock is soft, but slightly abrasive, as if some "
           "twigs were stuck in it, or little slivers of wood.");
   SetMaterial( ({ "textile" }) );
  SetWarmth(4);
   SetRepairDifficulty(5);
   SetRepairSkills( ([
                       "textile working" : 2,
                       "armour smithing" : 1,
                  ]) );
}
