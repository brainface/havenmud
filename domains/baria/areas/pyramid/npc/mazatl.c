/*                                                                   
//
// Creator: Angel Cazares - Rhakz
// Date: 09/18/98
// File Name: mazatl.c
// Area: the dark pyramid
// Modified: Zalbar 12/2007 - Added SetResistance

 */

#include <lib.h>
#include <damage_types.h>
#include "../pyramid.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("mazatl");
  SetShort("Mazatl the first guardian");
  SetId( ({ "guard","mazatl","guardian","first guardian","mazatl "
            "the first guardian" }) );
  SetRace("golem");
  SetGender("neuter"); 
  SetLong("This huge stone statue looks very strong and powerful. "
          "It could easily defend the pyramid against everything "
          "but the strongest enemies."  );
  SetClass("cavalier");
  SetLevel(20 + random(5));
  SetCombatAction(5, ({
     "Pieces of rock fall from the statue!",
     }) );
  SetInventory( ([
     P_OBJ + "/stone_sword" : "wield sword",
     ]) );
  SetFriends( ({"tlaloc"}) );
  SetEncounter(300);
  SetStat("charisma", 350, 1);
  SetNoCorpse(1);
  SetDie("The stone guardian crumbles into piles of useless stone.");
  SetResistance(HUNGER,"immune");
  SetResistance(DISEASE,"immune");
  SetResistance(POISON,"immune");
  SetResistance(GAS,"immune");
  SetResistance(BLUNT,"high");
  SetResistance(SLASH,"high");
  SetResistance(PIERCE,"high");
}
