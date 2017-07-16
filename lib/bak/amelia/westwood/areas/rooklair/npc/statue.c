#include <lib.h>
#include "../rook.h"
inherit LIB_SENTIENT;

static void create() {
  ::create();
  SetKeyName("statue");
  SetRace("golem","statue");
  SetId( ({ "statue","stone statue" }) );
  SetAdjectives( ({ "stone" }) );
  SetClass("fighter");
  SetGender("male");
  SetShort("a stone statue");
  SetLevel(50);
  SetLong("This statue is about seven feet tall and is made of "
    "plain stone.   It is humanoid in appearance and has armour "
    "carved with it.  It appears to be a warrior of an older "
    "age because his armour looks archaic and very decorative.");
  SetMorality(0);
  SetCombatAction(30, ({ 
     "!emote pounds its fist together creating a cloud of dust.",
     "!emote attempts to crush its enemies.",
    }) );
  SetDie( "The statue shakes the ground violently as it falls." );
  SetInventory( ([
    R_OBJ + "weapon" : "wield weapon",
  ]) );
  SetFriends("statue");
 }
