/*                                                                   */
//
// Creator: Angel Cazares - Rhakz
// Date: 09/18/98
// File Name: lizardman_center.c
// Area: the dark pyramid
//
#include <lib.h>
#include "../pyramid.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("lizardman");
  SetShort("a large lizardman");
  SetId( ({ "lizardman","large lizardman" }) );
  SetRace("lizardman"); 
  SetClass("rogue");
  SetGender("male");
  SetMorality(-250);
  SetLevel(15+random(4));
  SetLong("This is a large lizardman standing quietly by the "
          "wall. It looks as if it didn't have a life of it's own...but "
          "it is secretly watching everything."  );
 
  SetAction(2, ({
  	 "!say Silence...."
     }) );
  SetCombatAction(5, ({
     "!emote loses a few scales!",
     }) );
  SetCurrency("crystals", 10 + random(11));
  RemoveLanguage("Slith");
  SetLanguage("Archaic",100,1);
  SetInventory( ([
     P_OBJ + "/necklace" : "wear necklace",
     ]) );

}
