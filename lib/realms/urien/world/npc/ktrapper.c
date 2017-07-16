// Something to contribute to a road in the 
// world. Frostmarch intended. 

#include <lib.h>
#include <std.h>
#include <damage_types.h>
#include "../world.h"

inherit LIB_NPC;

static void create() {
  ::create();
  SetRace("kobold");
  SetGender("female");
  SetClass("rogue");
  SetLevel(random(9) + 15); // Lowered to fit Mahkefel needs
  SetKeyName("kobold trapper");
  SetId( ({ "kobold" , "trapper" }) );
  SetAdjectives( ({ "kobold" }) );
  SetShort("a kobold trapper");
  SetLong("This particular kobold seems to be slightly "
          "dehydrated from traversing the Frostmarches "
          "in search of nourishment. Her demeanor appears as "
          "a being with excellent knowledge on how to "
          "survive in the rugged terrain despite nefarious "
          "odds. Her overall physique is hardened and the "
          "thick fur skin is matted smelling of decaying "
          "trash.");
  SetMorality(random(100) - 50); //Good or Evil as Kobolds 
                                 //are, naturally
  SetCurrency("senones", random(5) + 10);
  SetInventory( ([
    WORLD_OBJ + "kdagger" : "wield shiv",
    ]) );
  SetFirstCommands( ({ 
    "emote watches you cautiously.",
  }) );
  SetDie("The kobold trapper whimpers before her death.");
}