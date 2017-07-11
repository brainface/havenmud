#include <lib.h>
#include <std.h>
#include <damage_types.h>
#include "../defs.h"

inherit LIB_NPC;

static void create() {
  ::create();
  SetRace("gelfling");
  SetGender("male");
  SetClass("cavalier");
  SetSkill("blade combat", 100);
  SetLevel(random(10)+50);
  SetKeyName("skeleton");
  SetId( ({ "skeleton", "warrior","undead_wander"}) );
  SetShort("a skeleton warrior");
  SetAdjectives( ({ "warrior", "undead" }) );
  SetLong("The undead warrior is a slightly smaller than a normal human "
          "skeleton. Large and jagged bones make up his large bone "
          "structure, especially in what used to be his arms. The "
          "entire jaw portion of his face is missing, just displaying "
          "the top portion of his skull.");
  SetUndead(1);
  SetInventory( ([
    TOWER_OBJ + "shortsword"   : "wield sword",
	TOWER_OBJ + "mring" : "wear my first ring on right hand",
    ]) );
  SetMorality(-25);
  SetStat("charisma", 201, 1);
  SetDie("The skeleton crumbles into dust.");
  SetNoCorpse(1);
  SetResistance(POISON, "high");  
  SetResistance(ACID, "high");
  SetResistance(GAS, "high");
  SetResistance(HUNGER, "high");
  SetResistance(DISEASE, "high");
}