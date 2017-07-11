//Selket@Haven
//2006
#include <lib.h>
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("crocodile");
  SetId( ({"crocodile"}) );
  SetShort("a crocodile");
  SetRace("lizard");
  SetClass("animal");
  SetLevel(5);
  SetGender("male");
  SetLong(
    "This green crocodile enjoys his muddy home. He is "
    "also fond of snapping at unsuspecting trespassers.");
  SetAction(6, ({ 
     "!emote makes a chomping noise.",
     "!emote rolls happily in the mud.",
  }) );
}
