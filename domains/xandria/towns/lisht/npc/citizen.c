//Selket@Haven
//2006
#include <lib.h>
#include "../lisht.h"
inherit LIB_SENTIENT;

static void create() {
   sentient::create();
   SetTown("Lisht");
   SetKeyName("citizen");
   SetShort("a citizen of Lisht");
   SetId( ({ "citizen","of lisht" }) );
   SetAdjectives( ({ "citizen" }) );
   SetLong("This citizen is a suspicious person obviously "
           "looking out only for themself. ");
   SetRace("gnoll");
  SetBaseLanguage("Rehshai");
   SetClass("fighter");
  SetLevel(random(4) + 1);
   if(random(2)) { SetGender("male"); }
   else  { SetGender("female"); }
   SetAction(5, ({ "!emote ignores you.","!emote mutters.",
                   "!emote minds their own business." }) );
   SetCombatAction(20, ({ "!say Guards!","!shout Help!",
                          "!say Selket help me!","!say Get out "
                          "of Lisht!" }) );
   SetInventory( ([
                    LISHT_OBJ + "knife" : "wield knife",
                    LISHT_OBJ + "shenti" : "wear shenti",
               ]) );
   SetWander(10);
   SetCurrency("deben",5000);
   SetFriends( ({"citizen","guard","neferu","hathor","thoth"}) );
   SetMorality(-350);
}
