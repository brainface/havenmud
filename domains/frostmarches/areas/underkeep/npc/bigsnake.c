//
// A big mother-snake
// Created by Ranquest@Haven
//
#include <lib.h>
#include "main.h"
#include <damage_types.h>
 inherit LIB_NPC;

static void create () {
  npc::create();
  SetShort("a big snake");
  SetLong("This snake is quite literally the mother of all snakes. Her "
    "body is three feet wide and fifteen feet long, and covered in "
    "iridiscent shimmering scales. Her flickering tongue tastes the"
    " air in a distinctly threatening manner, and her slitted yellow"
    " eyes peer out of her wrinkled lidless sockets.");
  SetKeyName("snake");
  SetAdjectives( ({"big","mother"}) );
  SetId( ({"snake","serpent"}) );
  SetRace("snake");
  SetClass("animal");
  SetLevel(6);
  SetCurrency("crystals",60);
  SetGender("female");
  
  SetAction(5,({
    "!emote hisses in anger.",
    "!emote whips her tail from side to side.",
    "!emote tastes the air with her tongue.",
    }) );
  SetMeleeAttackString("fangs");
  SetMeleeDamageType(PIERCE);
  SetDie("The snake gives a final hiss of anger before collapsing, "
    "limp. The tail continues to twitch for a few minutes.");
  SetCorpseItems( ([
     RNQ_OBJ + "snskin" : 1,
      ]) );
}
