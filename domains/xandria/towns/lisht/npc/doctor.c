//Selket@Haven
//2006
#include <lib.h>
#include "../lisht.h"
inherit LIB_NPC;

static void create() {
   npc::create();
   SetKeyName("doctor");
   SetShort("an aged doctor");
   SetId( ({ "doctor" }) );
   SetAdjectives( ({ "aged" }) );
   SetLong("This doctor has spent long years training and working "
           "his remedies and is now revered through the land as a "
           "most astute physician. It is sad that Selket herself "
           "guides his healing hands, endowing him with greater "
           "powers than those of his fellows."
   );
   SetMorality(-500);
   SetRace("gnoll");
   SetGender("male");
   SetReligion("Enniae");
   SetBaseLanguage("Rehshai");
   SetClass("priest");
   SetSkill("healing",1,1);
   SetSkill("enchantment",1,1);
   SetSkill("melee combat",1,1);
   SetSkill("melee combat",1,1);
   SetLevel(40+random(5));
   SetSpellBook( ([
                    "mend" : 100,
                    "dispel poison" : 100,
                    "mend heavy" : 100,
                    "cure disease" : 100,
               ]) );
   SetAction(5, ({
  "!cast mend on first patient",
  "!cast mend on second patient",
  "!cast mend on third patient",
  "!cast mend on fourth patient",
  "!cast dispel poison on first patient",
  "!cast dispel poison on second patient",
  "!cast dispel poison on third patient",
  "!cast dispel poison on fourth patient",
  "!cast cure disease on first patient",
  "!cast cure disease on second patient",
  "!cast cure disease on third patient",
  "!cast cure disease on fourth patient",
  "!say Are you in need of healing?",
  }) );
   SetInventory( ([
                    LISHT_OBJ "shenti" : "wear shenti",
               ]) );
   SetFriends( ({ "patient" }) );
}
