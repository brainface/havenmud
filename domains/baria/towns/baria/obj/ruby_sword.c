//
// Ruby sword for warrior
// Created by: Rhakz@Haven -- Angel Cazares
// For: Baria
// Date: 09/04/99
//
#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("ruby shortsword");
  SetId( ({ "shortsword" }) );
  SetAdjectives( ({ "beautiful", "ruby" }) );
  SetShort("a beautiful ruby shortsword");
  SetLong("This beautiful and well crafted shortsword has its blade "
          "made out from red ruby. The hilt is made of a shiny silver "
          "metal.");
  SetVendorType(VT_WEAPON);
  SetDamagePoints(1800);
  SetClass(16);
  SetValue(650);
  SetMass(400);
  SetWeaponType("slash");
  SetMaterial( ({ "natural" }) );
  SetRepairSkills( ([
     "natural working" : 20,
  ]) );
  SetRepairDifficulty(60);
  SetDamageType(SLASH);
}
