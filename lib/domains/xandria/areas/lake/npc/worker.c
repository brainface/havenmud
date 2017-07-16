//Selket@Haven
//2006
#include <lib.h>
#include "../lake.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("worker");
  SetShort("a serious faience worker");
  SetId( ({ "worker" }) );
  SetAdjectives( ({ "serious", "faience" }) );
  SetLong(
    "This gnoll works to fashion ceramic and faience objects "
    "each day, which has hardened his muscles and his attitude "
    "toward the finer things in life.");
  SetClass("fighter");
  SetLevel(10);
  SetGender("male");
  SetRace("gnoll");
  SetBaseLanguage("Rehshai");
  SetCurrency("deben",random(1000));
  SetInventory( ([
       LAKE_OBJ + "mallet" : "wield mallet",
       LAKE_OBJ + "tunic" : "wear tunic",
       LAKE_OBJ + "sandals" : "wear sandals",
         ]) );
  SetAction(6, ({
    "!say Stupid cheap faience...",
    "!grumble",
    "!emote bangs something loudly at his workstation.",
  }) );
}
