#include <lib.h>
#include "../ungkh.h"
#include <damage_types.h>

inherit LIB_NPC;

static void create() {
  npc::create();

  SetKeyName("piggy");
  SetAdjectives( ({
    "dirty"
  }) );
  SetId( ({
    "pig","livestock",
    }) );

  SetShort("a pig");
  SetLong("Plump and juicy, this little pig plays tag with the "
          "incompetant goblin farmers.  He runs around and evades "
          "the farmer.  His life is dependant upon that.");

  SetRace("mammal");
  SetLevel(3);
  SetGender("male");

  SetAction(5, ({"!emote squeals.",
                 "!emote runs away from the farmers.",
                 "!emote runs between the farmer's legs.",
                 "!emote evades the farmers.",
                 }) );


  SetDie("The pig squeals like a goblin.");

}
