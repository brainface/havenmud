#include <lib.h>
#include "../sf.h"

inherit LIB_NPC;

#include "greeter.h"
static void create() {
   ::create();
   SetKeyName("defender");
   SetShort("a defender of the forest");
   SetId( ({ "defender", "sforest_wander" }) );
   SetMorality(0);
   SetClass("ranger");
   SetLevel(70+random(5));
   SetGender("female");
   SetRace("sprite");
   SetLong("The defender floats before you ready to defend "
           "her forest. Her beauty is almost blinding. Her "
           "small figure is covered with armour to help her "
           "in her efforts. Her big beautiful eyes seem to "
           "observe every inch of the room.");
   SetCurrency("rupies", random(3000)+1000);
   SetLanguage("Sprith", 100, 1);
   SetAction(3, ({"!speak I love the smell of flowers!",
                  "!speak Be sure to stay on the path!",
                  "!speak Please keep your hands to yourself!", 
             }) );
   SetReligion("Magildan");
   SetStat("intelligence", 250 ,1);
   SetStat("wisdom", 250 ,1);
   SetStat("charisma", 250,1);
   SetSkill("enchantment", 200 ,1);
   SetSkill("evokation", 200 ,1);
   SetSkill("projectile", 160 ,1);
   SetSkill("natural magic", 200 ,1);
   SetLimit(20);
   SetInventory( ([ 
      SF_OBJ + "/helm/bear_mask" : "wear mask",
      SF_OBJ + "/clothing/color_cloak" : "wear cloak",
      SF_OBJ + "/armour/bbone_armour" : "wear breastplate",
      SF_OBJ + "/armour/bbone_boots" : "wear boots",
      SF_OBJ + "/weapon/ivory_bow" : "wield bow",
      SF_OBJ + "/armour/bbone_greaves" : "wear greaves",
      ]) );
   SetSpellBook( ([
                "wall of wood" : 100,
                "soothe" : 100,
                "heat" : 100,
                "chameleon" : 100,
          ]) );
   SetFirstCommands(({
                "cast wall of wood",
                "cast wall of wood",
                "cast wall of wood",
                "cast chameleon",
          }));
   SetCombatAction(15, ({
          "!cast heat",
          "!cast soothe",
                }) );
    SetGreet("Welcome to the Shining Forest. Remember, this is a peaceful "
      "place so be sure to keep it that way.");
    SetFriends(({"protector", "defender", "guard", "wolf" }));
}
