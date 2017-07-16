//Selket@Haven
//2006
#include <lib.h>
#include "../lake.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("papyrusmaker");
  SetShort("a papyrus maker");
  SetId( ({ "maker" }) );
  SetAdjectives( ({ "papyrus" }) );
  SetLong(
    "This crochety fellow spends each day beating the pulp from "
    "the papyrus stems gathered on the riverbanks and plaiting "
    "them together. His hands are gnarled from the work, and his "
    "dark eyes attend to each task with alacrity. "
  );
  SetClass("fighter");
  SetLevel(20);
  SetGender("male");
  SetRace("gnoll");
  SetBaseLanguage("Rehshai");
  SetCurrency("deben",random(1000));
  SetInventory( ([
       LAKE_OBJ + "glove" : "wear glove on left hand",
       LAKE_OBJ + "shenti" : "wear shenti",
         ]) );
  SetAction(6, ({
    "!say Don't give me no manure. Get to work.",
    "!cough sagely",
    "!say What're you eyeballing me for?",
  }) );
}
