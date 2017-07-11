/*                                                                   */
//
// Creator: Angel Cazares - Rhakz
// Date: 09/18/98
// File Name: lizardman_nw.c
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
  SetGender("male");   
  SetClass("fighter");
  SetLevel(14 + random(4));
  SetMorality(-200);
  SetLong("Holding a heavy mace, this lizardman is ready to take on "
          "anyone who profanes the pyramid. The lizardman is "
          "the size of a human and holds an odd grin."  );

  SetAction(5, ({ 
     "The lizardman looks around and grins demonically."
     }) );
  SetCombatAction(5, ({
     "!emote loses a few scales!",
     }) );
  SetCurrency("crystals", 10 + random(11));
  SetInventory( ([
     P_OBJ + "/necklace" : "wear necklace",
     P_OBJ + "/mace" : "wield mace"
     ]) );
}