#include <lib.h>
#include "../sf.h"

inherit LIB_NPC;
#include "greeter.h"
static void create() {
   ::create();
   SetKeyName("protector");
   SetShort("a protector of the forest");
   SetId( ({ "protector", "a protector", "sforest_wander" }) );
   SetMorality(0);
   SetClass("mystic");
   SetLevel(85+random(25));
   SetGender("male");
   SetRace("sprite");
   SetLong("The protector floats about ready to protect his forest. He is "
           "covered from head to toe in what appears to be mystic attire. His "
           "eyes seem to be directed towards your every move. However, he does "

           "not seem aggressive.");
   SetCurrency("rupies", random(2000)+500);
   SetLanguage("Sprith", 100, 1);
   SetAction(1, ({"!speak Yet another beautiful day in the forest!",
                  "!speak Please stay on the path!",
                  "!speak Harm no one and you will remain safe!", }) );
   SetReligion("Magildan");
   SetStat("intelligence", 250);
   SetStat("wisdom", 250);
   SetStat("charisma", 250);
   SetSkill("multi-weapon", 175 ,1);
   SetSkill("enchantment", 175 ,1);
   SetLimit(20);
   SetInventory( ([ 
      SF_OBJ + "/helm/bear_mask" : "wear mask",
      SF_OBJ + "/clothing/color_cloak" : "wear cloak",
      SF_OBJ + "/armour/bbone_armour" : "wear breastplate",
      SF_OBJ + "/armour/bbone_boots" : "wear boots",
      SF_OBJ + "/weapon/wood_pole" : "wield first pole",
      SF_OBJ + "/armour/bbone_greaves" : "wear greaves",
      ]) );
   SetSpellBook( ([
                "enhanced energy wall" : 100,
                "disintegrate" : 100,
                "summon animal" : 100,
                "heat" : 100,
                "soothe" : 100,
                "natural charge" : 100,
               ]) );
   SetFirstCommands(({
                "cast enhanced energy wall",
                "cast enhanced energy wall",
                "cast enhanced energy wall",
                "cast summon animal", 
                   }));
   SetCombatAction(3, ({
          "!cast soothe",
          "!cast heat",
          "!cast disintegrate",
                }) );
   SetGreet("Welcome to the Shining Forest. Please behave.");
   SetFriends(({"protector", "defender", "guard", "wolf" }));
}
