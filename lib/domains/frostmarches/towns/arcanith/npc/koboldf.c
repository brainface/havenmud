/* An average kobold warrior - female */

#include <lib.h>
#include "../ruins.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("kobold");
  SetId( ({ "warrior" }) );
  SetAdjectives( ({ "kobold", "female", "woman" }) );
  SetShort("a kobold warrior");
  SetLong("This short squat humanoid looks like the cross between a dog and "
          "a lizard.  The dog-like head has too large eyes that seem to glow "
          "red.  Scales cover her body and are a dirty brown.  She appears "
          "to be starving.");

  
  SetRace("kobold");
  SetClass("rogue");
  SetGender("female");
  SetLevel(2);
  SetMorality(-25);

  SetAction(5, ({ "!growl", "!snarl",
                  "The kobold looks for food to take to the children." }) );
  SetInventory( ([ OBJ "/spear" : "wield spear" ]) );
  SetDie("The kobold lets out a yelp as she is hit with the deathblow.");
  SetFriends( ({ "kobold warrior", "kobold child" }) );

}
