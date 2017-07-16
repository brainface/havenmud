#include <lib.h>
#include <std.h>
#include <damage_types.h>
#include "../defs.h"

inherit LIB_NPC;

static void create() {
  ::create();
  SetRace("human");
  SetGender("male");
  SetClass("fighter");
  SetLevel(random(12)+50);
  SetKeyName("skeleton");
  SetId( ({ "skeleton", "warrior","undead_wander"}) );
  SetShort("a skeleton warrior");
  SetAdjectives( ({ "warrior", "undead" }) );
  SetLong("This undead has the build of what used to be a human. White bleached "
          "bones make up his entire body. His skull displays numerous cracks and "
          "dents in it which follow along his bones. His entire body is covered "
          "in brown dust and small cracks from his previous life.");
  SetUndead(1);
  SetInventory( ([
    TOWER_OBJ + "shield1"      : "wear shield on right arm",
    TOWER_OBJ + "shortsword"   : "wield sword"
    ]) );
  SetMorality(-25);
  SetWander(10);
  SetDie("The skeleton crumbles into dust.");
  SetNoCorpse(1);
  SetResistance(POISON, "high");  
  SetResistance(ACID, "high");
  SetResistance(GAS, "high");
  SetResistance(HUNGER, "high");
  SetResistance(DISEASE, "high");
}
