#include <lib.h>
#include "../sf.h"

inherit LIB_NPC;
#include "greeter.h"
static void create() {
   ::create();
   SetKeyName("lorian");
   SetShort("Lorian, prince of the Shining forest");
   SetId( ({ "lorian", "prince"}) );
   SetMorality(0);
   SetClass("mystic");
   SetLevel(75);
   SetGender("male");
   SetRace("sprite");
   SetLong("Lorian the prince stands before you humbly. His "
           "face is covered with a scruffy beard. His eyes are blood "
           "shot and his hair is very messy. He is wearing a "
           "green robe and a crown made of wood and gems. He "
           "is holding a small wooden scepter that has many "
           "jewels in it. ");
   SetCurrency("rupies", random(1000)+500);
   SetLanguage("Sprith", 100, 1);
   SetAction(1, ({"!speak Welcome to my wonderful home!",
                  "!speak Long live Princess Laria!",
                  "!speak Know that my guards will not allow "
                  "anyone to harm me!",
                  "Please move along!", 
                }) );
   SetReligion("mystic");
   SetStat("intelligence", 250);
   SetStat("wisdom", 250);
   SetStat("charisma", 250);
   SetSkill("enchantment", 400 ,1);
   SetSkill("natural magic", 400 ,1);
   SetSkill("evokation", 400 ,1);
   SetSkill("pole combat", 100 ,1);
   SetSkill("conjuring", 400,1);
   SetInventory( ([ 
      SF_OBJ + "/helm/prince_crown" : "wear crown",
      SF_OBJ + "/clothing/prince_robe" : "wear robe",
      SF_OBJ + "/clothing/prince_shirt" : "wear shirt",
      SF_OBJ + "/clothing/prince_pants" : "wear pants",
      SF_OBJ + "/clothing/prince_shoes" : "wear shoes",
      SF_OBJ + "/weapon/scepter" : "wield scepter",
      ]) );
   SetSpellBook( ([
                "temporal barrier" : 100,
                "temperature shield" : 100,
                "soothe" : 100,
               ]) );
   SetFirstCommands(({
                "cast temporal barrier",
                "cast temporal barrier",
                "cast temporal barrier",
                "cast temporal barrier",
                "cast temperature shield", 
                   }));
   SetCombatAction(20, ({
                "!yell HELP! Garis HELP!",
                "!yell Prince in distress!",
                "!cast soothe",
                }) );
   SetGreet("Greetings and welcome to the Shining Forest!");
   SetFriends(({"garis" }));
}
