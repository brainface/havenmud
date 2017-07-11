/*                                                                   */
//
// Creator: Angel Cazares - Rhakz
// Date: 09/18/98
// File Name: spider.c
// Area: the dark pyramid
//
#include <lib.h>
#include "../pyramid.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("giant spider");
  SetShort("a giant spider");
  SetId( ({ "spider","giant spider" }) );
  SetRace("arachnid");
  SetGender("female");
  SetClass("animal");
  SetMorality(-50);
  SetLevel(1);
  SetLong("The spider is too big for being a measly arachnid, it's "
          "almost the size of a human's head. She likes to show off "
          "her dangerous fangs."
         );

  SetCombatAction(5, ({
                       "The spider tears into your flesh with her fangs!"
                  }) );
  SetCurrency("crystals", 1 + random(6));

}
