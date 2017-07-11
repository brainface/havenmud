// Written by Vanyel
#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include "ice.h"
inherit LIB_SENTIENT;

static void create() {
  sentient::create();
  SetKeyName("ice elemental");
  SetShort("an ice elemental");
  SetId( ({ "elemental" }) );
  SetAdjectives( ({ "icy", "ice", "blue" }) );
  SetRace("elemental");
  SetClass("cavalier");
  SetLong("Made entirely of ice, this strange beast crackles as he walks, "
    "spreading ice dust off of his shoulders.  Although this beast looks "
    "fearsome, he has a look of honor about him.");
  SetGender("male");
  AddLimb("elemental limb", "torso", 1, ({ A_WEAPON }) );
  SetMeleeDamageType(COLD|BLUNT);
  SetInventory( ([
     ICE_OBJ + "/icicle" : "wield icicle",
     ]) );
  SetLevel(20 + random(10));
  SetWander(19);
  SetNoCorpse(1);
  SetMorality(100);
}
