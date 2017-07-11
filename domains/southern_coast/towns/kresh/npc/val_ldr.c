/*  A valkyr leader. */
#include <lib.h>
#include "../goblins.h"
inherit LIB_LEADER;

static void create() {
  ::create();
  SetKeyName("Morkatal");
  SetTown("Kresh");
  SetId( ({"goblin", "morkatal","warrior"}) );
  SetFriends( ({ "goblin" }) );
  SetShort("Morkatal the Shadow Warrior");
  SetLong("Morkatal is a quick and small goblin with a gleem in "
          "his eye that suggests he is far more dangerous a foe than "
          "he looks.  His quick reflexes and snap responses make him "
          "the ideal leader of the Bratak, the rogues of the Horde.");
  SetRace("goblin");
  SetClass("rogue");
  SetLevel(45);
  SetMorality(-300);
  SetCurrency( ([
     "rounds" : random(200),
      ]) );
  SetCombatAction(25, ({
  	 "!disarm",
  	 "!disorient",
  	 }) );
  SetGender("male");
  
  SetFreeEquipment( ([
    GOBLIN_OBJ "knifer" : 2,
    ]) );
  SetPlayerTitles( ([
    "newbie" : "the Gutless Sneak",
    "mortal" : "the Bratak of the Horde",
    "hm"     : "the News Bringer of the Horde",
    "legend" : "the Knife in the Night",
    "avatar" : "the Fleetfoot Stalker of the Horde",
    ]) );
}
