/*  A valkyr leader. */
#include <lib.h>
#include "../goblins.h"
inherit LIB_LEADER;

static void create() {
  ::create();
  SetKeyName("Jormal");
  SetTown("Kresh");
  SetFriends( ({ "goblin" }) );
  SetId( ({"goblin", "jormal"}) );  
  SetShort("Jormal the Silent Warrior");
  SetRace("goblin");
  SetClass("rogue");
  SetLevel(45);
  SetMorality(-250);
  SetCurrency( ([
     "rounds" : random(200),
      ]) );
  SetCombatAction(25, ({
  	 "!disorient",
  	 }) );
  SetGender("male");
  SetLong("Jormal is a quick and small goblin that is covered in "
          "various scars which make him look intimidating and dangerous. "
          "His quick reflexes and intensive knowledge of battle and scouting "
          "makes him the ideal leader of the valkyr of the Horde.");
  SetFreeEquipment( ([
    GOBLIN_OBJ "knifer" : 2,
    ]) );
  SetPlayerTitles( ([
    "newbie" : "the Apprentice Night Stalker",
    "mortal" : "the Twilight Walker of the Horde",
    "hm"     : "the Night Shadow of the Horde",
    "legend" : "the Hidden Whisper of the Horde",
    "avatar" : "the Silent Death of the Horde",
    ]) );
}
