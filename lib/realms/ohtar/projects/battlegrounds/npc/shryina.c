/* Shryina the beautiful
* Creater: Ohtar
*
*/

#include <lib.h>
#include "../battlegrounds.h"
#include <damage_types.h>
#include <size.h>
#include <armour_types.h>
inherit LIB_SENTIENT;

static void create() {
   sentient::create();
   SetKeyName("Shryina");
   SetShort("Shryina the beautiful");
   SetId( ({ "Shryina", "beautiful"}) );
   SetRace("dark-elf");
   SetTown("Malveillant");
   SetGender("female");
   SetLong("Shryina the beautiful stands before you. Her long flowing hair "
           "is dark black in color. Her arms are dandling by her side "
           "in a very unthreatening maor. Her body is completely covered "
           "in a very well fit set of material that shows her beautiful form "
           "so well. Her giant green eyes are staring directly into yours. ");
   SetLanguage("uruk", 100, 1);
   SetReligion("soirin");
   SetMorality(-2500);
   SetClass("evoker");
   SetStat("intelligence", 150);
   SetStat("wisdom", 150);
   SetStat("charisma", 150);
   SetSkill("enchantment", 500 ,1);
   SetSkill("evokation", 500 ,1);
   SetSkill("conjuring", 500 ,1);
   SetSkill("knife combat", 500 ,1);
   SetSkill("multi-hand", 500 ,1);
   SetSkill("projectile", 500 ,1);
   SetSkill("conjuring", 500 ,1);
   SetSkill("dodge", 500 ,1);
   SetSkill("parry", 500 ,1);
   SetSkill("natural armour", 500 ,1);
   SetSkill("ice magic", 500 ,1);
   SetLevel(350);
   SetCurrency("roni", random(2000)+2000);
   SetInventory( ([ 
      BAT_OBJ + "/nat_armour" : "wear armour",
      BAT_OBJ + "/nat_helmet" : "wear helmet",
      BAT_OBJ + "/nat_gloves" : 2,
      BAT_OBJ + "/blood_knife" : "wield knife",
      BAT_OBJ + "/nat_boots" : "Wear boots",
      ]) );
   SetSpellBook( ([
                "ice lance" : 100,
                "aetheric rift" : 100, 
                "mage's bane" : 100,
                "planar durability" : 100, 
                "planar intelligence" : 100,
		"planar wisdom" : 100,
                "planar charisma" : 100,
                "planar strength" : 100,
                "planar luck" : 100,
               ]) );
   SetFirstCommands(({
                "wear first glove on right hand",
		"wear first glove on left hand",
                "cast aetheric rift",
                "cast aetheric rift", 
                "cast aetheric rift",
                "cast planar durability",
                "cast planar wisdom",
                "cast planar intelligence",
                "cast planar strength",
                "cast planar luck",
                   }));
   SetCombatAction(15, ({
          "!cast mage's bane",
          "!cast ice lance",
          "!cast ice lance",
                }) );
}
