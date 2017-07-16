//
//  Sardaukar the draconian shaman
//  Created by Rhakz@Haven -- Angel Cazares
//  For Baria
//  Date: 14/02/99
//
#include <lib.h>
#include "../jungle.h"
inherit LIB_LEADER;

static void create() {
  leader::create();
  SetKeyName("Sardaukar");
  SetShort("Sardaukar the High Priest of Kuthar");
  SetId( ({"sardaukar", "draconian", "priest","high priest"}) );
  SetAdjectives( ({ "old", "wise", }) );
  SetLong("This young draconian is the chosen one to spread the "
          "teachings of Kuthar. His red scales shine brightly, "
          "making him look rather impressive. He has the wisdom "
          "of his ancestors, which makes him one of the most "
          "powerful inhabitants of Baria."
  				);
  SetRace("draconian");
  SetMorality(-300);
  SetGender("male");
  SetClass("shaman");
  SetSkill("fire magic",1,2);
  SetCombatAction(80, ({ 
     "!cast will of old",
     "!cast crush",
     "!cast umbral shield",
  	 }) );
  SetAction(15, ({
  	 "!cast umbral shield",
  	 }) );
  SetLevel(85);
  SetLanguage("Dragonish", 100, 0);
  SetLanguage("Barian", 100, 1);
  SetTown("Baria");
  SetReligion("Kuthar");
  SetFriends( ({"creb","barian kid","native","guard"}) );
  SetFreeEquip( ([
     BARIA_OBJ + "club" : 2,
     BARIA_OBJ + "vest" : 1,
  	 ]) );
  SetUniqueSkills( ([
     ]) );
  SetSpellBook( ([
     "will of old" : 100,
     "barrier of faith" : 100,
     "crush" : 100,
  	 ]) );
  SetTaughtSpheres( ({
     "magical",
     "magical evokation",
     "magical necromancy",
     "clerical",
     "clerical evokation",
     "clerical necromancy",
     "religion kuthar",
  	 }) );
  SetPlayerTitles( ([
     "newbie" 		 : "the Apprentice Dragon Priest of Kuthar",
     "mortal"      : "the Wise Dragon Priest of Kuthar",
     "high mortal" : "the Sacred Dragon Priest of Kuthar",
     "legend"      : "the Ancient Guardian of Souls",
     "avatar"      : "the Powerful Hand of the Dragon Lord",
  	 ]) );
}
