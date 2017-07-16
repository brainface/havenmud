//Alex@Haven
//2006
#include <lib.h>
#include <std.h>
inherit LIB_SENTIENT;

static void create(){
  sentient::create();
  SetKeyName("abu");
  SetId( ({"monkey", "animal"}) );
  SetAdjectives ( ({"tame", "abu", "monkey"}) );
  SetShort("Abu the Tame Monkey");
  SetLong(
    "This is Abu. He is a wild little monkey given to defecating on "
    "things and being loud for no reason. He doesn't look very strong or "
    "friendly.");
  SetGender("male");
  SetRace("primate");
  SetClass("animal");
  SetLevel(5);
  SetWander(1);
  SetAction(10, ({
    "!oo"
    "!ah",
    "Abu bares his teeth at you.",
    "Abu defecates into his hand and smears it on the wall.",
  }) );
  SetMorality(-50);
  SetLimit(1);
  SetSmell("He smells like a little poop machine.");
}

