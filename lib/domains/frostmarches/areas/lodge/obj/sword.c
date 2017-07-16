#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
#include "../lodge.h"
inherit LIB_ITEM;
static void create() {
  item::create();
  SetKeyName("sword");
  SetId( ({"sword"}) );
  SetShort("a bearteeth sword");
  SetLong("This sword needs two hands to hold.  The whole sword is the lower "
  "part of an enormous bear's jaw, attached at the end is a leather handle.  "
  "The teeth on the sword are so sharp they glisten in the light.  This weapon "
  "is of good use.");
  SetClass(20);
  SetAdjectives( ({"bearteeth"}) );
  SetValue(250);
  SetDamageType(SLASH);
  SetVendorType(VT_WEAPON);
  SetWeaponType("slash");
  SetHands(2);
  SetDamagePoints(300);
  SetMaterial( ({"natural",}) );
  SetRepairSkills( ([
  "weapon smithing" : 7,
  ]) );
  SetRepairDifficulty(5);
}


/* Approved by Duuktsaryth on Sat Feb 19 17:29:11 2000. */
