#include <lib.h>
inherit LIB_NPC;
#include "../rook.h"

static void create() {
  npc::create();
  SetKeyName("rat");
  SetShort("an ugly rat");
  SetId( ({ "rat" }) );
  SetAdjectives( ({ "ugly" }) );
  SetRace("rodent");
  SetGender("male");
  SetClass("animal");
  SetLevel(1);
  SetLong("This is an ugly rat.  After the ages it has spent in this cave, "
    "it is just a bag of bones.  Its eyes are white as though they no "
    "longer function and its whiskers seem longer than most normal rats.");
  
  SetCombatAction(30, ({ 
     "!emote gnashes about in an attack.",
     "!emote blindly strikes out.",
     "!emote snaps its teeth in an attack.",
    }) );
  SetAction(10, ({
    "!emote feet pad about the room.",
    "!emote runs in small circles.",
    "!emote nibbles on something.",
  }) );
  SetFriends("rat");
  }
