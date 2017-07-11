/*  Bastard Sword - Bridge Builder - Level #2 Caverns  */

#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("bastard sword");
  SetId( ({ "sword", "bastard sword" }) );
  SetAdjectives( ({ "ordinary" }) );
  SetShort("a bastard sword");

  SetLong("The bastard sword is pretty ordinary, nothing special carved into "
          "the blade, no gems in the hilt.  This is an ordinary, everyday "
          "weapon capable of considerable injuries.");

  SetMass(350);
  SetValue(400);
  SetDamagePoints(750);

  SetVendorType(VT_WEAPON);
  SetMaterial("metal");
  SetRepairSkills( ([ "metal working" : 4,
                      "weapon smithing" : 4,
  ]) );
  SetRepairDifficulty(8);

SetWeaponType("slash");
  SetDamageType(SLASH);
  SetClass(15);
}
