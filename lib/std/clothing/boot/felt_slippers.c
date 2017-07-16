  /* slipper
  Luna 12/16/98
*/
#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create();
   SetArmourClass(ARMOUR_CLOTH); SetMaterials( ({ "textile" }) );
  SetKeyName("slippers");
  SetShort("a pair of felt slippers");
  SetId( ({"slippers"}) );
  SetAdjectives( ({"brocade","natural"}) );
  SetLong("These slippers are made of felt and are "
          "adorned with a myriad of small jewels. "
          "These would be perfect with a special gown.");
  SetMass(20);
  SetValue(100);
  SetDamagePoints(25);
  SetMaterial("textile");
  SetWarmth(5);
  SetArmourType(A_BOOT);
}
