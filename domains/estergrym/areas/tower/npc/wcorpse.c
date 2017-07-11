#include <lib.h>
#include <std.h>
#include <damage_types.h>
#include "../defs.h"

inherit LIB_NPC;

static void create() {
  ::create();
  SetRace("human");
  SetGender("male");
  SetClass("rogue");
  SetLevel(random(7)+40);
  SetKeyName("corpse");
  SetId( ({ "corpse","undead_wander"}) );
  SetShort("a walking corpse");
  SetAdjectives( ({ "walking", "undead" }) );
  SetLong("This humanoid has stitches strewn about his body. They "
          "line his arms and torso all the way up to his neck. His "
          "eyes are completely missing above his cut off nose. The "
          "thin hair on his head is covered in a thick oil which "
          "endows his entire body.");
  SetUndead(1);
  SetInventory( ([
  TOWER_OBJ + "tvest"   : "wear vest",
  TOWER_OBJ + "knife"   : "wield stiletto",
  ]) );
  SetWander(5);
  SetDie("The corpse coughs up a black puff of smoke before collapsing.");
  SetMorality(-35);
  SetResistance(ACID, "high");
  SetResistance(GAS, "high");
  SetResistance(HUNGER, "high");
  SetResistance(DISEASE, "high");
}
