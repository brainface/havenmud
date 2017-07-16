#include <lib.h>
inherit LIB_NPC;
static void create() {
    npc::create();
    SetShort("a plain grey housecat");
    SetLong(
      "This is a plain, grey, housecat that goes by the name \"Assassin\"."
      );
    SetRace("cat");
    SetGender("male");
    SetClass("animal");
    SetLevel(2);
    SetMorality(0);
    SetKeyName("assassin");
    SetId( ({"housecat",  "cat", "assassin" }) );
    SetAdjectives( ({ "house", "plain", "grey" }) );
    SetLimit(1);
    SetWander(6);
    SetAction(5, ({
    	"!purr",
    	"!say Dwarves rock.",
    	"!say I run this place.  I'll sleep where I want.",
    	"!say It is time to feed me.  Do so!",
    	"!say Cats rule, dogs drool.",
    	"!say This world needs to realize I'm in charge.",
    	}) );
}
