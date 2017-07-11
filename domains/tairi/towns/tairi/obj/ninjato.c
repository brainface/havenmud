/* A small sword/knife */
#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("ninja-to");
  SetShort("a small sword");
  SetId( ({ "ninja-to", "to", "sword" }) );
  SetAdjectives( ({ "small", "ninja" }) );
  SetLong("This sword is called a ninja-to.  It is a smaller than "
          "average weapon used for lightning quick strikes in close "
          "combat rather than the full reaching weapons of conventional "
          "battle. The blade of this weapon has been darkened black.");
  SetWeaponType("slash");
  SetDamageType(SLASH);
  SetVendorType(VT_WEAPON);
  SetClass(15);
  SetDamagePoints(1200);
  SetValue(600);
  SetMass(85);
  SetMaterial("metal");
  SetRepairSkills( ([
     "metal working" : 5,
     "weapon smithing" : 5,
    ]) );
  SetRepairDifficulty(15);
}
