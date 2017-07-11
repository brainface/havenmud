
//Selket@Haven
//2006
#include <lib.h>
#include "../newbie.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("falcon");
  SetId( ({ "falcon", "horus", "lisht_newbie" }) );
  SetShort("Horus the Falcon");
  SetRace("bird");
  SetClass("animal");
  SetLevel(2);
  SetGender("male");
  SetLong(
    "Horus is an intelligent, free-spirited falcon. He "
    "seems quite brave.");
  SetAction(6, ({ 
     "!emote lets out a shrill cry.",
     "!emote circles slow arcs above you.",
  }) );
  SetWander(10);
  SetWanderSpeed(1);
  SetLimit(1);
  SetInventory( ([
    NEWBIE_OBJ "feather" : 1,
  ]) );
}
