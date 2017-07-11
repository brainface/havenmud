/*                                                                   */
//
// Creator: Angel Cazares - Rhakz
// Date: 09/18/98
// File Name: lizardman_ne.c
// Area: the dark pyramid
//
#include <lib.h>
#include "../pyramid.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("lizardman");
  SetShort("a lizardman guard");
  SetId( ({ "guard","lizardman","lizardman guard" }) );
  SetRace("lizardman");
  SetGender("male"); 
  SetClass("rogue");
  SetLevel(14+random(3));
  SetMorality(-350);
  SetLong("The large lizardman is one of the guardians of the "
          "pyramid. He is very short and his body "
          "looks old and in bad shape. The lizardman wields "
          "a javelin in order to defend itself."
         );
  
  SetAction(5, ({ 
     "The lizardman looks at itself and moans sadly."
     }) );
  SetCombatAction(5, ({
     "!emote loses a few scales!",
     }) );
  SetCurrency("crystals", 10 + random(11));
  SetInventory( ([
     P_OBJ + "/necklace" : "wear necklace",
     P_OBJ + "/javelin" : "wield javelin"
     ]) );
}
