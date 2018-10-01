//Illura@Haven
//Sept 2009
//gnollworkerf
#include <lib.h>
#include "../fields.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("worker");
  SetShort("a gnollish field worker");
  SetId( ({ "worker", "gnoll" }) );
  SetAdjectives( ({ "field", "gnollish" }) );
  SetLong(
    "This is an unskilled gnollish laborer. She prides herself "
    "on being strong and gifted with green thumbs, and is "
    "fond of telling others about the crops she sows into "
    "the ground. "
   );
  SetClass("fighter");
  SetLevel(25);
  SetGender("female");
  SetRace("gnoll");
  SetBaseLanguage("Rehshai");
  SetCurrency("deben",random(1000));
  SetInventory( ([
       FIELDS_OBJ "plow" : "wield plow"
         ]) );
  SetAction(6, ({
    "!say i hear barley helps those who are agrieved.",
    "!say i'm told hops will help you sleep.",
    "!say did you know pomegranates appease the dead?",
    "!say chickpeas give you stronger limbs.",
    "!say henna makes your coat so shiny!",
    "!emote plows a careful furrow into the ground.",
  }) );
}
