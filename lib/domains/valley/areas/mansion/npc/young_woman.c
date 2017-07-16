/* the female component of a cute young couple
  kyla 4-98
*/
#include <lib.h>
#include "../mansion.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("young woman");
  SetShort("a young woman");
  SetId( ({"woman" }) );
  SetAdjectives( ({"young", "gorgeous"}) );
  SetLong("This strikingly gorgeous young lady carries herself with the grace "
          "and confidence of an experienced woman. She appears to be very "
        "strong in spirit, and quite faithful to her god. It is doubtful that "
         "she would allow anyone to harm what she loves.");
  SetGender("female");
  SetRace("human");
  SetClass("priest");
  SetSkill("blunt combat", 1, 1);
  SetSkill("evokation", 1, 1);
  SetFriends("young man");
  SetReligion("Kylin", "Kylin" );
  SetMorality(1000);
  SetLevel(22);
  SetAction(5, ({ "The woman gives you a look that would melt the heart of "
                  "even the toughest fighter." }) );
  SetInventory( ([
              ]) );
  SetCurrency( ([ 
             "imperials" : 200,
             ]) );
  SetSpellBook( ([
          "wrath" : 100,
           "flaming arrow" : 100,
          "holy shield" : 100,
            "fortify" : 100,
            "smite" : 100,
            "wall of force" : 100,
               ]) );
  SetCombatAction(10, ({
         "!cast wrath",
          "!cast flaming arrow",
           "!cast smite",
           "!cast fortify",
           "!cast wall of force",
                 }) );
  }
