#include <lib.h>
#include "../path.h"

inherit LIB_SENTIENT;

static void create()
{
  ::create();
  SetKeyName("roach");
  SetId( ({ "a roach", "roach", "cockroach" }) );
  SetAdjectives( ({ "mutant", "giant" }) );
  SetShort("a mutant roach");
  SetLong("This insect looks more like a giant centipede than roach. "
          "Its years in Teras' lab have caused it to grow two giant "
          "antennaes, a new third segment, and a pair of extra legs. "
          "As if this weren't enough, it is almost twice the size of "
          "its unmutated relatives.");
  SetRace("insect");
  SetClass("animal");
  SetGender("neuter");
  SetLevel(4);
  SetMorality(0);
  AddLimb("third segment","torso",2, ({ }) );
  AddLimb("right antenna","head",5, ({ }) );
  AddLimb("left antenna","head",5, ({ }) );
  AddLimb("7th leg","third segment",3, ({ }) );
  AddLimb("8th leg","third segment",3, ({ }) );
  SetAction(3, ({"A roach scurries about looking for a place to hide."}) );
  SetWander(20);
  SetProperty("lab_wander", 1);
}
