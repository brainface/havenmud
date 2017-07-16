/* ----------------------------------------------------------------------- */
// Area Title: City of Jidoor
// Filename: lyuin.c
// Author: Derek Noble
// Creator: dylanthalus@haven
// Creation Date: Feb 4th, 1999
// Abstract: Lyuin, Merchant Training :)
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include "../jidoor.h"

inherit LIB_TRAINER;

static void create() {
   trainer::create();
   SetKeyName("Lyuin");
   SetShort("Lyuin, the Merchant's Aide");
   SetLong("Lyuin is a great teacher of merchants skills.  She "
           "is friendly and seems willing to help people who need her."
           "She is not quite as pale as most lamrani, but her skin is "
           "very white.  She looks pretty capable of defending herself "
           "if someone attacked her.");
   SetId( ({ "lyuin","merchant","merchant's aide","aide","jidoor_npc", }) );
   SetGender("female");
   SetRace("lamrani");
   RemoveLanguage("Dasinri");
   SetLanguage("Sprith", 100, 1);
   SetReligion("Magildan","Magildan");
   SetClass("merchant");
   SetSkill("blunt combat",1,2);
   SetSkill("conjuring",1,1);
   SetSkill("enchantment",1,1);
   SetMorality(-35);
   SetTown("Jidoor");
   SetLevel(30);
   AddTrainingSkills("bargaining");
   AddTrainingSkills("fishing");
   AddTrainingSkills("farming");
   AddTrainingSkills("mining");
   AddTrainingSkills("armour smithing");
   AddTrainingSkills("metal working");
   AddTrainingSkills("mithril working");
   AddTrainingSkills("weapon smithing");
   AddTrainingSkills("textile working");
   AddTrainingSkills("wood working");
   AddTrainingSkills("leather working");
   AddTrainingSkills("natural working");
   SetInventory( ([
      JID_OBJ + "/clothing/diviner_robe" : "wear robe",
      JID_OBJ + "/clothing/sandals" : "wear sandals",
      "/std/weapon/blunt/mace" : "wield mace",
      ]) );
   SetSpellBook( ([
     "paralysis" : 100,
     "blindness" : 100,
   ]) );
   SetCombatAction(40, ({
     "!cast paralysis",
     "!cast blindness",
   }) );
}

