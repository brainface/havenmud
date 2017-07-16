//
// Free staff for necroes
// Created by: Rhakz@Haven -- Angel Cazares
// For: Baria
// Date: 06/04/99
//
#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("ebony staff");
  SetId( ({"staff","ebony staff"}) );
  SetAdjectives( ({"black"}) );
  SetShort("an ebony staff");
  SetLong("This is a staff made from black ebony.");
  SetVendorType(VT_WEAPON);
  SetDamagePoints(600);
  SetClass(10);
  SetValue(100);
  SetMass(200);
  SetWeaponType("pole");
  SetMaterial( ({"wood"}) );
  SetRepairSkills( ([
              "wood working" : 3,
                 ]) );
  SetRepairDifficulty(10);
  SetDamageType(BLUNT);
}
