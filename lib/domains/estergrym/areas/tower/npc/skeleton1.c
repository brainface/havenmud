#include <lib.h>
#include <std.h>
#include <damage_types.h>
#include <armour_types.h>
#include "../defs.h"

inherit LIB_NPC;

static void create() {
  ::create();
  SetRace("gelfling");
  SetGender("male");
  SetClass("rogue");
  SetSkill("knife combat", 100);
  SetLevel(random(10)+60);
  SetKeyName("skeleton");
  SetId( ({ "skeleton", "warrior","undead_wander"}) );
  SetShort("a skeleton warrior");
  SetAdjectives( ({ "warrior", "undead" }) );
  SetLong("This undead has the skeleton mass of a gelfling. Slightly smaller "
          "in size than a full grown human and bone structure. His skull "
          "is small with extreme signs of decay and age and some teeth are "
          "missing from his bleached teeth exposing some holes in his "
          "malicious grin.");
  SetUndead(1);
  SetUndeadType("skeleton");
  SetInventory( ([
    TOWER_OBJ + "shield2" : "wear buckler on left hand",
    TOWER_OBJ + "knife"   : "wield stiletto",
    ]) );
  SetMorality(-25);
  SetStat("charisma", 201, 1);
  SetFriends(({TOWER_NPC+"skeleton1"
               TOWER_NPC+"sumskeleton"
               TOWER_NPC+"nsumskeleton"
               TOWER_NPC+"skeleton2"
               TOWER_NPC+"necromancer"
               TOWER_NPC+"mummy"
  }));  
  SetDie("The skeleton collapses to the ground and breaks into dust.");
  SetNoCorpse(1);
  SetResistance(POISON, "high");  
  SetResistance(ACID, "high");
  SetResistance(GAS, "high");
  SetResistance(HUNGER, "high");
  SetResistance(DISEASE, "high");
}
