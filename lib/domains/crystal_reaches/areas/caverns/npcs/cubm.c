/*  Male Bear Cub - Level #1 Caverns  */

#include <lib.h>
#include "../caves.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("cub");
  SetId( ({ "cub" }) );
  SetAdjectives( ({ "bear", "black", "male" }) );
  SetShort("a male bear cub");

  SetLong("The bear cub is curled up in a ball on the ground.  It looks so "
          "small and innocent lying before you.  Though it's black fur is wet "
          "it still looks very warm and content.");

  SetRace("bear");
  SetClass("animal");
  SetLevel(2);
  SetGender("male");
  SetMorality(0);
  SetDie("The cub cries out for it's mother with it's last breath.");

  SetAction(7, ({ "The cub plays playfully in the corner.",
                  "The cub lovingly nuzzles it's mother.",
                  "The bear gives you the sad cubby bear look.",
  }) );

  SetCombatAction(5, ({ "The cub cries out in alarm.",
                        "The cub scurries around the room.",
                        "The cub cries out for it's mother.",
  }) );
}
