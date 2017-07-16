/*  Newbie Clothing of the Robe variety */
#include <lib.h>
#include <damage_types.h>
#include <armour_types.h>
#include <armour_class.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
  ::create(); SetArmourClass(ARMOUR_CLOTH); SetMaterials( ({ "textile" }) ); 
  SetValue(0);
  SetVendorType(VT_CLOTHING);
  SetArmourType(A_BODY_ARMOUR);
  SetKeyName("drab robe");
  SetShort("a long drab grey robe");
  SetAdjectives( ({ "long", "drab", "grey" }) );
  SetId( ({ "robe" }) );
  SetLong("This rather billowy grey robe is very dull and serves "
          "as only basic clothing.");
  SetRepairSkills( ([
      "textile working" : 1,
      ]) );
  SetMaterial( ({ "textile" }) );
  SetWarmth(15);
  SetRepairDifficulty(2);
  SetMass(60);
  SetDamagePoints(500);
  //PIERCE, 2);
 }
