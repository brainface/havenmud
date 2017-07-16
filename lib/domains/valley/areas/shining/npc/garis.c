/* Garis
*  CREATER: Ohtar
*/
#include <lib.h>
#include "../sf.h"

inherit LIB_NPC;
#include "greeter.h"
static void create() {
   ::create();
   SetKeyName("garis");
   SetShort("Garis, guardian of the prince");
   SetId( ({ "garis", "guardian"}) );
   SetMorality(0);
   SetClass("mystic");
   SetLevel(100+random(20));
   SetGender("male");
   SetRace("sprite");
   SetLong("Garis, the elite guardian of the prince stands before you "
           "with an intense look on his face. He is covered from head to toe "
           "with body armour. His hair appears to be very long and braided. "
           "It is rapped gently around his neck. His eyes are pure red with "
           "small green beads inside them. They almost seem to be moving "
           "constantly although they never seem to look away.  ");
   SetCurrency("rupies", random(20000)+5000);
   SetLanguage("Sprith", 100, 1);
   SetReligion("Magildan");
   SetStat("intelligence", 250);
   SetStat("wisdom", 250);
   SetStat("charisma", 250);
   SetSkill("enchantment", 269 ,1);
   SetSkill("evokation", 269 ,1);
   SetSkill("natural magic", 269 ,1);
   SetSkill("projectile combat", 269 ,1);
   SetSkill("conjuring", 269 ,1);
   SetInvis(1);
   SetInventory( ([ 
      SF_OBJ + "/helm/gwolf_mask" : "wear mask",
      SF_OBJ + "/clothing/color_cloak" : "wear cloak",
      SF_OBJ + "/armour/bbone_armour" : "wear breastplate",
      SF_OBJ + "/armour/bbone_boots" : "wear boots",
      SF_OBJ + "/weapon/ivory_bow" : "wield bow",
      SF_OBJ + "/armour/bbone_greaves" : "wear greaves",
      ]) );
   SetSpellBook( ([
                "enhanced energy wall" : 100,
                "temperature shield" : 100,              
                "summon animal" : 100,
                "flamestrike" : 100,
                "death" : 100,
               ]) );
   SetFirstCommands(({
                "cast enhanced energy wall",
                "cast enhanced energy wall",
                "cast enhanced energy wall",
                "cast temperature shield",
                "cast temperature shield", 
                "guard prince",
                   }));
   SetCombatAction(15, ({
          "!cast flamestrike",
          "!cast death",
                }) );
   SetFriends(({"prince"} ));
}
