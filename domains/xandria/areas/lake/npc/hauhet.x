//Selket@Haven
//2006
#include <lib.h>
#include "../lake.h"
inherit LIB_NPC;

static void create() {
  npc::create();
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
}
