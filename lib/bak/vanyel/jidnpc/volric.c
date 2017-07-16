/* ----------------------------------------------------------------------- */
// Area Title: City of Jidoor
// Filename: volric.c
// Author: Derek Noble
// Creator: dylanthalus@haven
// Creation Date: February 2nd, 1998
// Abstract:  Volric Gypsy Leader
// Revision History:  
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include <std.h>
#include "../jidoor.h"

inherit LIB_LEADER;

static void create() {
   leader::create();
   SetKeyName("Volric");
   SetShort("Volric, the Predator of Dreams");
   SetLong("Although pale skinned, Volric is still dark and ominous "
          "looking.  He doesn't appear friendly in the slightest and "
          "looks incredibly dangerous.  He offers his services to "
          "his help to those interested in becoming gypsies.");
   SetId( ({ "volric", "diviner","rogue","predator",
             "predator of dreams", "gypsy",}) );
   SetRace("lamrani");
   RemoveLanguage("Dasinri");
   SetLanguage("Sprith", 100, 1);
   // SetClass("rogue");
   SetGender("male");
   SetTown("Jidoor");
   SetStat("durability", 65);
   SetStat("strength", 55);
   SetSkill("knife attack", 1, 1);
   SetSkill("knife defense", 1, 1);
   SetSkill("multi-weapon", 1, 2);
   SetSkill("evokation", 135, 1);
   SetSkill("conjuring", 135, 1);
   SetFreeEquip( ([ 
      STD_KNIFE + "small_knife.c" : 1, 
   ]) );
   SetPlayerTitles( ([ 
      "gypsy" : "the Predator of Dreams",
   ]) );
   SetLevel(45);
   SetMorality(25);
   SetSpellBook( ([
  /*1*/      "energy wall" : 100,
  /*2*/      "chain lightning" : 100,
                ]) );
   SetInventory( ([ 
      JID_OBJ + "/clothing/diviner_robe" : "wear robe",
      JID_OBJ + "/clothing/sandals" : "wear sandals",
      STD_KNIFE + "stiletto" : "wield stiletto",
   ]) );
   SetAction(1, ({
      "!cast energy wall",
/*
      "!speak A Gypsy is a Diviner who has learned the trade"
      "of the Rogue.",
      "!speak I can teach you about Rogues if you're already "
      "versed in the ways of the Diviner.",
*/
   }) );
   SetCombatAction(5, ({
      "!cast energy wall",
      "!cast energy wall",
      "!cast energy wall",
      "!cast energy wall",
      "!cast chain lightning",
      "!cast chain lightning",
   }) );
  SetNoJoin(1);
}

   /*
void eventJoin(object who, string args) {
  if (!(who->GetClass("diviner"))) { 
          eventForce("speak I only teach the ways of the Rogue "
            "to those who have already begun their careers as "
            "Diviners.  Go see Valora first if you are interested "
            "in becoming a Diviner and then return to me "
            "if you wish to become a Gypsy.");
  return;
  }
  return leader::eventJoin(who, args);
}
  */
