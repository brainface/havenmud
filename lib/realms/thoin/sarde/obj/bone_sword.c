//
// Bone sword for ashtang
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
  SetKeyName("bone sword");
  SetId( ({ "sword" }) );
  SetAdjectives( ({ "massive", "bone" }) );
  SetShort("a massive bone sword");
  SetLong("This huge white sword has been made entirely out of a single piece "
          "of a dragon's bone. The blade is very thick, but its edge is "
          "extremely sharp. This sword could only have been created by an "
          "expert smithy."
  );
  SetHands(2);
  SetVendorType(VT_WEAPON);
  SetDamagePoints(2300);
  SetClass(24);
  SetValue(800);
  SetMass(800);
  SetWeaponType("slash");
  SetMaterial( ({"natural"}) );
  SetRepairSkills( ([
     "natural working" : 40,
  ]) );
  SetRepairDifficulty(60);
  SetDamageType(SLASH);
  SetProperty("history", "The sword was once part of a bone belonging "
                         "a dragon. When the dragon died and decayed, "
                         "someone started to forge a weapon out from "
                         "the only bone left, and this sword is the "
                         "result"
             );
}
