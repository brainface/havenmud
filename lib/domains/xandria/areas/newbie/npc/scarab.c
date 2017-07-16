//Selket@Haven
//2006
#include <lib.h>
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("scarab");
  SetId( ({"scarab", "beatle"}) );
  SetShort("a scarab");

  SetRace("insect");
  SetClass("animal");
  SetLevel(1);
  SetLong(
    "This little bug looks almost like a jewel. Its wings "
    "glint purple and emerald in the sunlight.");
  SetAction(6, ({ 
     "!emote flicks its wings at you.",
     "!emote flies around.",
  }) );
}
