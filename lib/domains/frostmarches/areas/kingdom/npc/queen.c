
/* the queen
   Elasandria 4/16/98
*/

#include <lib.h>
#include "../kingdom.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("faerie queen");
  SetShort("Rhiannon, Queen of Faeries");
  SetId( ({ "faerie", "woman", "queen", "rhiannon" }) );
  SetAdjectives( ({ "powerful", "regal", "elegant", "untamed", "golden"
    "beautiful" }) );
  SetLong("The Queen of Faeries is strikingly beautiful and untamed. She "
     "projects a regal, elegant image. Her gilded tresses are piled high "
     "and secured with a stunning jeweled tiara. Her gown is a vision in the "
    "purest shade of gold, almost glittering in its paleness. Her skin looks " 
    "to have a warm golden cast and her eyes gleam darkly, wetly green. She "
    "looks utterly secure of the knowledge of her formidable power.");
  SetGender("female");
  SetRace("faerie"); 
  SetClass("enchanter");
  SetSkill("shock magic", 1, 2);
  SetLevel(40);
  SetMorality(500);
  SetAction(5, ({
  		"!emote raises an eyebrow imperiously at you.", 
      "Rhiannon raises an eyebrow imperiously at you."})
      );
  SetInventory( ([
      KINGDOM_OBJ + "tiara" : "wear tiara",
      KINGDOM_OBJ + "gown" : "wear gown",
      ]) );
  SetSpellBook( ([
      "sphere"          : 100,
      "chain lightning" : 50,
      "fireball"        : 100,
      ]) );
  SetCombatAction(70, ({
  		 "!cast sphere",
       "!cast chain lightning",
       "!cast fireball"}) 
       );
}
