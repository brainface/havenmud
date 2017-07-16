//Illura@Haven
//Sept 2009
//gnollworkerm
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
    "This is an unskilled gnollish laborer. He prides himself "
    "on being better than the elvish slaves doing the same "
    "jobs behind him and tries to act intelligent by passing "
    "on information from others around him. "
   );
  SetClass("fighter");
  SetLevel(25);
  SetGender("male");
  SetRace("gnoll");
  SetBaseLanguage("Rehshai");
  SetCurrency("deben",random(1000));
  SetInventory( ([
       FIELDS_OBJ "rake" : "wield rake"
         ]) );
  SetAction(6, ({
    "!say i hear, um, that lettuce makes you have babies.",
    "!say psst...um, onions? They're an aphrodisiac, you know.",
    "!say one of the girls said figs 'awaken the bowels', so watch out.",
    "!say smelly elves. They're terrible farmers.",
    "!say i can't wait until that emmer is ready to harvest!",
    "!emote rakes the soil, glaring at the weeds.",
  }) );
}
