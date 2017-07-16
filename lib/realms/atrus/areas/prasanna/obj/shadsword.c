#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("obsidian sword");
  SetRepairDifficulty(22);
  SetMaterial( ({ "metal" }) );
  SetRepairSkills( ([
    "metal working" : 6,
    "weapon smithing" : 6,
     ]) );
  SetShort("a shiny obsidian sword");
  SetAdjectives( ({ "shiny","obsidian","dark","black" }) );
  SetId( ({ "sword" }) );
  SetLong("This sword is carved from pure obsidian, and hardened with dark "
          "magic to withstand the rigors of battle. It's blade is polished "
          "to perfection, and has a slightly serrated edge.");
  SetClass(14);
  SetDamagePoints(950);
  SetValue(250);
  SetMass(150);
  SetVendorType(VT_WEAPON);
  SetWeaponType("slash");
  SetDamageType(SLASH);
  }

