
//Selket@Haven
//2006
#include <lib.h>
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("jackal");
  SetId( ({"jackal", "dog"}) );
  SetAdjectives( ({"wild"}) );
  SetShort("a jackal");
  SetRace("dog");
  SetClass("animal");
  SetLevel(4);
  SetGender("male");
  SetLong("This is a black jackal. His fangs are sharp.");
  SetAction(6, ({ 
     "!bark",
     "!emote capers about.",
  }) );
}
