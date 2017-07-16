#include <lib.h>
inherit LIB_LEADER;
#include "../monastery.h"

static void create() {
   leader::create();
   SetProperty("monasterynoleave",1);
   SetKeyName("Payat");
   SetShort("Payat, a divinely joyous druid of Eclat");
   SetId( ({ "payat","druid","druid of eclat" }) );
   SetAdjectives( ({ "divine","divinely joyous","eclat","eclatish" }) );
   SetLong("Payat smiles with a joyous face, looking up at everything "
           "in the world.  He shines with an inner light of joy and "
           "happiness, perking up all believers around him.");
   SetReligion("Eclat","Eclatish");
   SetClass("druid");
   SetSkill("melee attack",50);
   SetSkill("melee defense",50);
   SetUniqueSkills( ([
                       "evokation" : 0,
                       "melee attack" : 1,
                       "bargaining" : 2,
                       "melee defense" : 2,
                                "pole defense" : 4,
                       "farming" : 4,
                  ]) );
   SetLevel(65);
   SetGender("male");
   SetRace("muezzin");
   SetInventory( ([
                    M_OBJ + "circlet" : "wear circlet on head",
               ]) );
   SetSpellBook( ([
                    "sanctify" : 100,
                    "sphere of joy" : 100,
                    "resurrect" : 100,
                    "harmony hand" : 100,
                    "divine religion" : 100,
                    "remove paralysis" : 100,
                    "harm evil" : 100,
                    "harmony wind" : 100,
                    "mend heavy" : 100,
                  "empower" : 100,
               "pious obstructions" : 100,
                "guardian angel" : 100,
                    "regenerate limb" : 100,
               ]) );
   SetAction(1,({ "!speak in oiseau Joy to all!","!smile",
                  "!laugh","!giggle","!emote chuckles merrily.",
                  "!emote starts laughing spontaneously." }) );
   SetCombatAction(50,({ "!cast sanctify","!cast harm evil" }) );
   SetMorality(1000);
}
