//Selket@Haven
//2006
//Mahkefel@Haven '10: made into a skill trainer.
#include <lib.h>
#include "../lake.h"
inherit LIB_TRAINER;

static void create() {
    ::create();
  SetKeyName("hauhet");
  SetShort("Hauhet the Weaver");
  SetId( ({ "hauhet", "weaver" }) );
  SetLong(
    "Hauhet is a youthful weaver with much skill and even more "
    "pride in her work. Her skillful hands add rich embroidery "
    "to cloth articles. "
  );
  SetClass("fighter");
  SetLevel(20);
  SetGender("female");
  SetRace("gnoll");
  SetBaseLanguage("Rehshai");
  SetCurrency("deben",random(1000));
  SetInventory( ([
       LAKE_OBJ + "spindle" : "wield spindle",
       LAKE_OBJ + "em_dress" : "wear dress",
       LAKE_OBJ + "sandals" : "wear sandals",
         ]) );
  SetAction(6, ({
    "!sneer",
    "!emote eyes you haughtily.",
    "!emote tosses her head regally.",
  }) );
  SetTrainingSkills( ({
    "textile working",
  }) );
}
