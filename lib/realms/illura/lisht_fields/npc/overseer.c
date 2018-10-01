//Illura@Haven
//Sept 2009
//overseer
#include <lib.h>
#include "../fields.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("worker");
  SetShort("a hawk-eyed overseer");
  SetId( ({ "overseer", "gnoll" }) );
  SetAdjectives( ({ "hawk-eyed", "hawk", "eyed" }) );
  SetLong(
    "The overseer keeps a watchful eye on his charges. "
    "Entrusted with getting the crops grown and harvested, "
    "he has no problem whatsoever with using whatever "
    "tools available to him to achieve that goal. "
   );
  SetClass("fighter");
  SetLevel(30);
  SetGender("male");
  SetRace("gnoll");
  SetBaseLanguage("Rehshai");
  SetCurrency("deben",random(1000));
  SetInventory( ([
       FIELDS_OBJ "whip" : "wield whip"
         ]) );
  SetAction(6, ({
    "!say Get to work, you.",
    "!say I mean it. Get plowin'.",
    "!say Praise Pharaoh!",
    "!say Just look at those weeds!",
    "!say Those vegetables aren't going to pick themselves!",
    "!emote cracks his whip threateningly.",
  }) );
}
