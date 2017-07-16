#include <lib.h>
inherit LIB_INVADER;
#define pirdir "/domains/westwood/invasions/ogre_soleil"

static void create() {
   invader::create();
   SetKeyName("shaman");
   SetShort("an Urgesh shaman");
   SetId( ({ "shaman" }) );
   SetAdjectives( ({ "urgesh" }) );
   SetStat("intelligence",30,4);
   SetLong("Many strange holy symbols adorn the shaman of Urgesh.  "
           "He is dumb looking, but apparently had high enough "
           "intelligence to master the Urgesh way of life and "
           "become a shaman.  He is large and fat, and looks "
           "rather imposing.");
   SetRace("ogre");
   SetGender("male");
   SetClass("shaman");
   SetLevel(38);
   SetInventory( ([
                    pirdir + "/tunic" : "wear tunic_leader",
                    pirdir + "/pants" : "wear pants_leader",
               ]) );
   SetAction(6, ({ "!attack first citizen","!attack first muezzin",
                   "!say Kill fuzzies!","!say Urgesh shaman say "
                   "kill fuzzies.  Kill fuzzies!","!growl",
                   "!burp","!snarl","!cast holy shield", }));
   SetSpellBook( ([
                    "holy shield" : 100,
                    "smash"       : 100,
                    "bolt"        : 100,
                    "mangle"      : 100,
                    "hurt"        : 100,
                    "thrash"      : 100,
                    "crush"       : 100,
               ]) );
   SetCombatAction(10, ({ "!cast holy shield","!cast smash",
                          "!cast smash","!cast bolt","!cast mangle",
                          "!cast hurt","!cast hurt","!cast thrash",
                          "!cast crush","!cast thrash",
                          "!cast mangle","!growl","!emote spits on "
                          "the ground.","!shout Help ogre shaman!",
                          "!thump","!thump" }) );
   SetCurrency("skins",125+random(25));
   SetWanderSpeed(15);
   SetWanderPath("go up");
   SetMorality(-3000);
   SetReligion("Urgesh","Urgesh");
   SetInventory( ([
                    pirdir + "/club_leader" : "wear club in right hand",
               ]) );
}
