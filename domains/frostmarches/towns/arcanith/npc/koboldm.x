/* An average kobold warrior - male */

#include <lib.h>
#include "../ruins.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("kobold");
  SetId( ({ "warrior" }) );
  SetAdjectives( ({ "kobold", "male", "man" }) );
  SetShort("a kobold warrior");
  SetLong("This short squat humanoid looks like the cross between a dog and "
          "a lizard.  The dog-like head has too large eyes that seem to glow "
          "red and two short horns.  Scales cover his body and are dirty "
          "brown.  It looks undernourished.");

  
  SetRace("kobold");
  SetClass("fighter");
  SetGender("male");
  SetLevel(2);
  SetMorality(-25);

  SetAction(5, ({ "!growl", "!snarl",
                  "The kobold searches around for anything valuble." }) );
  SetInventory( ([
      OBJ "/small_shield" : "wear shield on right arm",
      OBJ "/shortsword_old" : "wield sword" ]) );
  SetDie("The kobold howls as he falls to the ground.");

}
