#include <lib.h>
#include <domains.h>
inherit LIB_SENTIENT;

static void create() {
  ::create();
  SetKeyName("fedgwig");
  SetShort("Duke Fedgwig of Averath");
  SetProperty("no bump", 1);
  SetId( ({ "fedgwig", "duke" }) );
  SetAdjectives( ({ "duke", "averath", }) );
  SetGender("male");
  SetRace("human");
  SetClass("fighter");
  SetLevel(25);
  SetStat("durability", 10, 5);
  SetLong("The old Duke is obviously past his prime. "
          "His disheveled hair and glazed eyes make him "
          "appear to be senile. There is a frail and "
          "pitiful look about him.");
  SetMorality(1500);
  SetInventory( ([
    ]) );
  SetAction(5, ({
    "The Duke wanders about aimlessly.",
    "!emote stops, looks intently at nothing, and continues on his way.",
    "!say Have you seen my son?",
    "!say My boy has wandered off playing with his friends again.",
    "!yell Oh sonny!  Where are you?",
    "!emote stops and drools a bit.",
    }) );
}

  
