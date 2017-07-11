/* MASTER PROTECTOR
*  Oiral
*  CREATER: Reno
*/

#include <lib.h>
#include "../sf.h"

inherit LIB_NPC;
#include "greeter.h"
static void create() {
   ::create();
   SetKeyName("Oiral");
   SetShort("Oiral, master protector of the forest");
   SetId( ({ "protector", "oiral", "master protector"}) );
   SetMorality(0);
   SetClass("mystic");
   SetLevel(80+random(20));
   SetGender("male");
   SetRace("sprite");
   SetLong("Oiral the master protector stands before you with a smile on "
           "his face. He is covered from head to toe with a cloak. His "
           "eyes are solid white in color. They are fixed directly on yours "
           "almost as if he is staring right through you. His posture is "
           "amazing. His feet are exactly parallel to his shoulders. His "
           "back is completely straight. He has both hands on top of a "
           "black pole placed directly in front of him. ");
   SetCurrency("rupies", random(20000)+5000);
   SetLanguage("Sprith", 100, 1);
   SetAction(1, ({"!speak Thank you for visiting the forest and please enjoy "
                  "your stay! ",
                  "!speak Please, Refrain from violent actions inside the "
                  "forest. ", }) );
   SetReligion("Magildan");
   SetStat("intelligence", 250);
   SetStat("wisdom", 250);
   SetStat("charisma", 250);
   SetSkill("enchantment", 219 ,1);
   SetSkill("evokation", 219 ,1);
   SetSkill("natural magic", 219 ,1);
   SetSkill("pole pole", 219 ,1);
   SetSkill("conjuring", 219 ,1);
   SetInventory( ([ 
      SF_OBJ + "/helm/bear_mask" : "wear mask",
      SF_OBJ + "/clothing/color_cloak" : "wear cloak",
      SF_OBJ + "/armour/bbone_armour" : "wear breastplate",
      SF_OBJ + "/armour/bbone_boots" : "wear boots",
      SF_OBJ + "/weapon/bbone_pole" : "wield pole",
      SF_OBJ + "/armour/bbone_greaves" : "wear greaves",
      SF_OBJ + "mp_key" : 1,
      ]) );
   SetSpellBook( ([
                "temporal explosion" : 100,
                "enhanced energy wall" : 100,              
                "summon animal" : 100,
                "soothe" : 100,
                "flamestrike" : 100,
               ]) );
   SetFirstCommands(({
                "cast enhanced energy wall",
                "cast enhanced energy wall",
                "cast enhanced energy wall",
                "cast enhanced energy wall",
                "cast enhanced energy wall",
                "cast summon animal", 
                   }));
   SetCombatAction(15, ({
          "!cast temporal explosion",
          "!cast soothe",
          "!cast flamestrike",
                }) );
   SetGreet("Welcome to the Shining Forest. Pleaes behave.");
   SetFriends(({"protector", "defender", "guard", "wolf"} ));
}
