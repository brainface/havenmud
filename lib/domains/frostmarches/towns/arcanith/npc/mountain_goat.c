/* a mountain goat */

#include <lib.h>
#include "../ruins.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("goat");
  SetId( ({ "goat" }) );
  SetAdjectives( ({ "mountain" }) );
  SetShort("a mountain goat");
  SetLong("The mountain goat is a large animal.  His sharp hoves are suited "
          "to the rough terrain.  He has a long think coat which protects him "
          "from the cold of the mountain.");

  
  SetRace("sheep");
  SetClass("animal");
  SetGender("male");
  SetLevel(2);
  SetMorality(0);

  SetAction(5, ({ "The goat bleats loudly." }) );
SetTown("all");
}
