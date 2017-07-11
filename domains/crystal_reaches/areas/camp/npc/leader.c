
#include <lib.h>
#include <std.h>
#include "../camp.h"
inherit LIB_SENTIENT;

static void create() {
  sentient::create();
  SetKeyName("leader");
  SetShort("the gypsy leader");
  SetId( ({ "leader" }) );
  SetAdjectives( ({ "gypsy" }) );
  SetLong(
    "The leader of the gypsies is an imposing figure. "
    "He is rather young for a leader but seems to be very "
    "capable. His dark brown eyes hold a knowledge "
    "beyond his years."
  );  
  SetGender("male");
  SetRace("human");
  SetClass("rogue");
  SetLevel(30);
  
  SetCurrency( ([ 
    "rupies" : random(200)
  ]) );
  SetInventory( ([
    C_OBJ + "knife2" : "wield knife",
    C_OBJ + "pants2" : "wear pants",
    C_OBJ + "shirt2" : "wear shirt",
  ]) );
  SetAction(3, ({
    "!emote looks troubled.",
  }) );
  SetFriends( ({ "bodyguard" }) );
}
