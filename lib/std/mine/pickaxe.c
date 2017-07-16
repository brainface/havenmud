/*  A pickaxe suitable for a gnome */
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;
inherit LIB_DIGGING;

static void create() {
  item::create();
  SetKeyName("pickaxe");
  SetHands(2);
  SetWeaponType("hack");
  SetDamageType(SLASH);
  SetDamagePoints(500);
  SetValue(200);
  SetClass(15);
  SetShort("a large pickaxe");
  SetMaterial( ({ "wood", "metal" }) );
  SetRepairDifficulty(10);
  SetRepairSkills( ([
      "metal working" : 0,
      "wood working" : 0,
      "weapon smithing" : 0,
      ]) );
  SetMass(120);
  SetId( ({ "axe", "pickaxe" }) );
  SetAdjectives( ({ "large" }) );
  SetLong("This large pickaxe is designed for hacking into the walls of "
          "caves and destroying rock. It would make a fine weapon.");
  SetVendorType(VT_WEAPON);
  }
