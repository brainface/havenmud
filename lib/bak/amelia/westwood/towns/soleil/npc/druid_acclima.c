#include <lib.h>
inherit LIB_LEADER;
#include "../soleil.h"

static void create() {
   leader::create();
   SetProperty("soleilnoleave",1);
   SetKeyName("Acclima");
   SetShort("Acclima, the Soleil Druid Priest");
   SetId( ({ "acclima","druid","priest" }) );
   SetAdjectives( ({ "acclima","druid","priest","soleil","the" }) );
   SetLong("Acclima smiles happily, having retained the joy of her "
           "race while becoming Druidic by faith.  She loves dealing "
           "with nature and the surrounding world, so has worked "
           "hard at improving her skills.  It appears as if she "
           "has succeeded in many ways.");
   SetRace("muezzin");
   SetGender("female");
   SetReligion("Eclat","Eclat");
   SetClass("druid");
   SetLevel(48);
   SetUniqueSkills( ([
                       "evokation" : 0,
                       "melee attack" : 1,
                       "bargaining" : 2,
                       "melee defense" : 2,
				"pole defense" : 4,
                       "farming" : 4,
                  ]) );
   SetTown("Soleil");
   SetPlayerTitles( ([
                       "newbie" : "the Initiate Druid of Eclat",
                       "mortal" : "the Majestic Soleil Druid Priest",
                       "high mortal" : "the Guardian Angel of the WestWood",
                       "legend" : "the Revered and Dreaded Champion of the WestWood",
                       "avatar" : "the Sagacious Master of the WestWood",
                       "chorist" : "the Mellifluous WestWood Chorist",
                       "monk" : "the WestWood Battle-Axe",
                       "paladin" : "the Chivalrous WestWood Paladin",
                       "crusader" : "the Gallant WestWood Crusader",
                       "evangelist" : "the Gentle Trader of the WestWood",
                  ]) );
   SetMorality(50);
  SetTaughtSpheres( ({
    "natural healing", "natural enchantment",
    "natural", "religion eclat",
    }) );
}
