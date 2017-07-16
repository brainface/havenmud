//Jacked up the addencounter due to the fact is the apprentice 
//is not in nature aggressive. When he is attacked he will 
//summon these nasty skeletons to help out. They will be aggresive
//which is my goal, and guard their masters who summon them.

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
  SetLevel(random(10)+60);
  SetKeyName("skeleton");
  SetId( ({ "skeleton"}) );
  SetShort("a summoned skeleton");
  SetAdjectives( ({ "summoned", "undead" }) );
  SetLong("This is a generic humanoid skeleton with bleached white bones. "
          "He is missing most of his teeth and the remaining are split or "
          "have been broken off. His body has some dents and scratches on "
          "the surface which is sparkling slightly.");
  SetUndead(1);
  SetDie("The skeleton crumbles into dust.");
  SetMorality(-25);
  SetEncounter(20);
  SetCombatAction(5, ({ 
    "!guard apprentice" 
    "!emote attempts to bite at your neck!"}) );
  SetStat("charisma", 201, 1);
  SetFriends(({
               TOWER_NPC+"apprentice"
  }));
  SetResistance(POISON, "high");  
  SetResistance(ACID, "high");
  SetResistance(GAS, "high");
  SetResistance(HUNGER, "high");
  SetResistance(DISEASE, "high");
  SetNoCorpse(1);  
}
