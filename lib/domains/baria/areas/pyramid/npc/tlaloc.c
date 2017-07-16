/*                                                                  
//
// Creator: Angel Cazares - Rhakz
// Date: 09/18/98
// File Name: tlaloc.c
// Area: the dark pyramid
// Modified: Added SetResistances - Zalbar 12/2007

 */

#include <lib.h>
#include <damage_types.h>
#include "../pyramid.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("tlaloc");
  SetShort("Tlaloc the second guardian");
  SetId( ({ "guard","tlaloc","guardian","second guardian","tlaloc "
            "the second guardian" }) );
  SetRace("golem");
  SetGender("neuter"); 
  SetLong("Standing ten feet tall, the enormous statue watches "
          "over the place. It can easily destroy anyone who dares "
          "to confront it, only the strongest attackers stand a "
          "chance."  );
  SetClass("cavalier");
  SetLevel(20 + random(5));
  SetCombatAction(5, ({
     "Pieces of rock fall from the statue!",
     }) );
  SetInventory( ([
     P_OBJ + "/stone_axe" : "wield axe",
     ]) );
  SetFriends( ({"mazatl"}) );
  SetEncounter(300);
  SetStat("charisma", 350, 1);
  SetNoCorpse(1);
  SetDie("The stone guardian collapses into a pile of pebbles.");
  SetResistance(HUNGER,"immune");
  SetResistance(DISEASE,"immune");
  SetResistance(POISON,"immune");
  SetResistance(GAS,"immune");
  SetResistance(BLUNT,"high");
  SetResistance(SLASH,"high");
  SetResistance(PIERCE,"high");
  
}
