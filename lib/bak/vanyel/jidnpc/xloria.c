/* ----------------------------------------------------------------------- */
// Area Title: City of Jidoor
// Filename: xloria.c
// Author: Derek Noble
// Creator: dylanthalus@haven
// Creation Date: February 2nd, 1998
// Abstract:  Xloria GraverobberLeader
// Revision History:  
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include <std.h>
#include "../jidoor.h"

inherit LIB_LEADER;

static void create() {
   leader::create();
   SetKeyName("Xloria");
   SetShort("Xloria, the Violator of Sacred Ground");
   SetLong("Vile and sickening looking, Xloria is a very pale Lamrani.  "
           "She wears the traditional robe of the necromancer and wields "
           "a weapon used by rogues.  She is only tolerated in the city "
           "because of her magic and her willingness to teach her trade "
           "to those who would learn it.  She is obviously quite "
           "dangerous.");
   SetId( ({ "xloria", "necro","rogue","violator",
             "violater of sacred ground", "graverobber",}) );
   SetRace("lamrani");
   RemoveLanguage("Dasinri");
   SetLanguage("Sprith", 100, 1);
   SetClass("rogue");
   SetGender("female");
   SetTown("Jidoor");
   SetStat("durability", 65);
   SetStat("strength", 55);
   SetSkill("necromancer", 135, 1);
   SetSkill("conjuring", 135, 1);
   SetFreeEquip( ([ 
      STD_KNIFE + "small_knife.c" : 1, 
   ]) );
   SetPlayerTitles( ([ 
      "graverobber" : "the Violator of Sacred Ground",
   ]) );
   SetLevel(45);
   SetMorality(25);
   SetSpellBook( ([
  /*1*/      "mesmer barrier" : 100,
  /*2*/      "reckoning" : 100,
                ]) );
   SetInventory( ([ 
      JID_OBJ + "/clothing/necro_robe" : "wear robe",
      JID_OBJ + "/clothing/sandals" : "wear sandals",
      STD_KNIFE + "stiletto" : "wield stiletto",
   ]) );
   SetAction(1, ({
      "!cast mesmer barrier",
      "!speak They say the profession of the Graverobber is foul and "
       "horribly evil but what they don't realize the is the wealth of "
       "money one can earn just by digging up a few graves.  A "
       "Graverobber is a Necromancer who learned the arts of the Rogue.",
      "!speak I can teach you about Rogues if you're already "
       "versed in the ways of the Necromancer.",
   }) );
   SetCombatAction(5, ({
      "!cast mesmer barrier",
      "!cast mesmer barrier",
      "!cast mesmer barrier",
      "!cast mesmer barrier",
      "!cast reckoning",
      "!cast reckoning",
   }) );
}

void eventJoin(object who, string args) {
  if (!(who->GetClass("necromancer"))) { 
          eventForce("speak I only teach the ways of the Rogue "
            "to those who have already begun their careers as "
            "Necromancers.  Go see Hima first if you are interested "
            "in becoming a Necromancer and then return to me "
            "if you wish to become a Graverobber.");
  return;
  }
  return leader::eventJoin(who, args);
}
