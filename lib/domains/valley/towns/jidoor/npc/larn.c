/* ----------------------------------------------------------------------- */
// Area Title: City of Jidoor
// Filename: larn.c
// Author: Derek Noble
// Creator: dylanthalus@haven
// Creation Date: February 2nd, 1998
// Abstract: Larn Noble Mage Leader
// Revision History:  
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include <std.h>
#include "../jidoor.h"

inherit LIB_LEADER;

static void create() {
   leader::create();
   SetKeyName("Larn");
   SetShort("Larn, the Militant Wizard");
   SetLong("Larn is obviously a great warrior.  His face depicts one of "
           "honour and great prestige.  Dressed in the robes of an evoker "
           "and wielding the weapons of a cavalier, it is obvious that "
           "Larn is a Noble Mage.  Althought stern and solemnly looking, "
           "he seems willing to help young people learn about his career. "
           "He is quite dangerous looking and shows no fear in his eye "
           "as you look him over.");
   SetId( ({ "larn", "mage", "evoker","cavalier","wizard",
             "militant wizard","jidoor_npc",}) );
   SetRace("sprite");
   SetClass("cavalier");
   SetGender("male");
   SetTown("Jidoor");
   SetStat("durability", 65);
   SetStat("strength", 55);
   SetSkill("evokation", 135, 1);
   SetSkill("conjuring", 135, 1);
   SetFreeEquip( ([ 
      STD_PIERCE + "fencing_sword" : 1, 
      STD_SLASH + "shortsword" : 1, 
   ]) );
   SetPlayerTitles( ([ 
      "cavalier" : "the Militant Wizard",
   ]) );
   SetLevel(45);
   SetMorality(25);
   SetSpellBook( ([
  		"energy field"    : 100,
  		"chain lightning" : 100,
                ]) );
   SetInventory( ([ 
      JID_OBJ + "/clothing/vs_evoker_robe" : "wear robe",
      JID_OBJ + "/clothing/vs_sandals" : "wear sandals",
      STD_SLASH + "shortsword" : "wield shortsword",
      STD_PIERCE + "fencing_sword" : "wield fencing sword",
   ]) );
   SetAction(1, ({
      "!cast energy wall",
      "!speak A Noble Mage is a honourable lifestyle.  We are the "
      "heros of our world.  By accepting great code of honour that "
      "is the cavalier lifestyle, an evoker learns the art of war "
      "and becomes a Noble Mage.",
      "!speak I can teach you about Cavaliers if you're already "
      "versed in the ways of the Evoker.",
   }) );
   SetCombatAction(25, ({
      "!cast energy wall",
      "!cast chain lightning",
      "!disarm",
   		}) );
   SetNoJoin(1);
}

void eventJoin(object who, string args) {
  if (!(who->GetClass("evoker"))) { 
          eventForce("speak I only teach the ways of the Cavalier "
            "to those who have already begun their careers as "
            "Evokers.  Go see Warlad or Ryl first if you are interested "
            "in becoming a Evoker and then return to me "
            "if you wish to become a Noble Mage.");
  return;
  }
  return leader::eventJoin(who, args);
}
