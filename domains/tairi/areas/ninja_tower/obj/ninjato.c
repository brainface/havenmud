
#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("ninja-to");
  SetShort("a black ninja-to");
  SetId( ({ "ninja-to", "to", "knife" }) );
  SetAdjectives( ({  "ninja" }) );
  SetLong("This sword is called a ninja-to. It is a smaller than "
          "average weapon used for lightning quick strikes in close "
          "combat rather than the full reaching weapons of conventional "
          "battle. The blade of this weapon has been darkened black. "
  );
  SetWeaponType("knife");
  SetDamageType(SLASH);
  SetVendorType(VT_WEAPON);
  SetClass(15);
  SetDamagePoints(1200);
  SetValue(600);

  SetMass(85);
  SetMaterial("metal");
  SetRepairSkills( ([
     "metal working" : 2,
     "weapon smithing" : 2,
    ]) );
  SetRepairDifficulty(9);
}
