//
//  Summary: Empty coconut and weapon for drunkard
//  Created by Rhakz - Angel Cazares
//  Date: 10/14/98
//
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("coconut");
  SetId( ({ "coconut","empty coconut"}) );
  SetShort("an empty coconut");
  SetLong("This empty coconut was used to serve a Barian Cocktail. "
          "It could be used as a weapon too.");
  SetVendorType(VT_WEAPON);
  SetMaterial( ({"natural"}) );
  SetDamagePoints(120);
  SetClass(3);
  SetValue(1);
  SetMass(30);
  SetWeaponType("blunt");
  SetDamageType(BLUNT);
}

