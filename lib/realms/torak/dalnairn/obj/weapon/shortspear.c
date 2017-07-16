// Torak@Haven 2017

#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  ::create();
  SetKeyName("spear");
  SetShort("an iron tipped short spear");
  SetId( ({ "spear", "pole" }) );
  SetAdjectives( ({ "iron", "tipped", "short", "thin", "semiflexible" }) );
  SetLong(
    "A short thin pole of semiflexible wood tipped with an iron spear point."
  );
  SetWeaponType("pole");
  SetDamageType(PIERCE);
  SetVendorType(VT_WEAPON);
  SetClass(30 + random(6));
  SetDamagePoints(4000);
  SetValue(random(500)+1000);
  SetMass(100);
  SetMaterial("metal");
  SetRepairSkills( ([
     "metal working" : 10,
     "wood working" : 10,
     "weapon smithing" : 10,
    ]) );
  SetHands(1);
  SetRepairDifficulty(25);
}
