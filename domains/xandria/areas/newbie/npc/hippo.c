//Selket@Haven
//2006
#include <lib.h>
#include "../newbie.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("hippo");
  SetId( ({ "hippo", "hippopotamus" }) );
  SetAdjectives( ({ "dangerous" }) );
  SetShort("a dangerous hippopotamus");
  SetRace("mammal");
  SetClass("animal");
  SetLevel(8);
  SetGender("female");
  SetLong(
    "This is a huge hippopotamus, known for her big teeth"
    "and vicious mood swings.");
  SetAction(6, ({ 
    "!roar.",
    "!emote rolls happily in the mud.",
  }) );
  SetInventory( ([
    NEWBIE_OBJ "tusk" : 1,
  ]) );
}
