/*  Crude Spear - Kobold - Level #1 Caverns  */

#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("crude spear");
  SetId( ({ "spear" }) );
  SetAdjectives( ({ "crude" }) );
  SetShort("a crude spear");

  SetLong("The crude spear isn't the best in the world, in fact it's probably "
          "one of the worst.  The wooden shaft is crooked and bent, the "
          "spearhead is on crooked, and it is held in place half-heartedly by "
          "a badly tied piece of catgut.");

  SetMass(110);
  SetValue(25);
  SetDamagePoints(175);

  SetVendorType(VT_WEAPON);
  SetMaterial( ({ 
  		"natural", 
  		"wood" 
  		}) );
  SetRepairSkills( ([ 
  		"weapon smithing" : 1,
      "wood working" : 1,
      "stone working" : 2,
  ]) );
  SetRepairDifficulty(2);

  SetWeaponType("pierce");
  SetDamageType(PIERCE);
  SetClass(4);
}
