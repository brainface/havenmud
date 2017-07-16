/*  A fighter leader for the goblin village */
#include <lib.h>
#include "../goblins.h"
inherit LIB_LEADER;

static void create() {
  ::create();
  SetKeyName("Gurkan");
  SetTown("Kresh");
  SetGender("male");
  SetId( ({ "gurkan", "orkhan", "fighter","goblin" }) );
  SetShort("Gurkan the Orkhan");
  SetLong("This hulking goblin is an Orkhan in the tribe, which is a "
          "title granted only to those of great power.  His stature and "
          "build suggest he is a formidable warrior and not someone to "
          "be taunted without cause.  He could teach anyone a thing or "
          "two about being a warrior.");
  SetRace("goblin");
  SetClass("fighter");
  SetLevel(150);
  SetFriends( ({ "goblin" }) );
  SetCombatAction(25, ({
  	"!disarm",
  	"!disorient",
    }) );
  SetMorality(-200);
  SetInventory( ([
    GOBLIN_OBJ "slashy_thing" : "wield sword",
  ]) );
  SetPlayerTitles( ([
    "newbie" : "the Mare Milker",
    "mortal" : "the member of the Horde",
    "hm"     : "the Keshak of the Khan",
    "legend" : "Ko $N the Bloodrider of the Goblin Horde",
    "avatar" : "Khan",
    ]) );
  SetFreeEquipment( ([
    GOBLIN_OBJ "newbie_slash" : 1,
    ]) );
}
