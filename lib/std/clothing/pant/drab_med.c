/* Drab grey newbie pants */
#include <armour_types.h>
#include <armour_class.h>
#include <vendor_types.h>
#include <size.h>
#include <lib.h>
inherit LIB_ARMOUR;

static void create() {
  ::create(); SetArmourClass(ARMOUR_CLOTH); SetMaterials( ({ "textile" }) ); 
  SetValue(0);
  SetArmourType(A_PANTS);
  SetVendorType(VT_CLOTHING);
  SetKeyName("drab pants");
  SetDamagePoints(250);
  SetRepairSkills( ([
    "textile working" : 1,
    ]) );
  SetRepairDifficulty(2);
  SetShort("a pair of drab grey pants");
  SetSize(SIZE_MEDIUM);
  SetId( ({ "pants" }) );
  SetAdjectives( ({ "drab", "grey" }) );
  SetMaterial( ({ "textile" }) );
  SetWarmth(10);
  SetLong("This is a pair of drab grey pants. They are not much to "
          "look at, but they do cover the flesh.");
  SetMass(40);
  }
