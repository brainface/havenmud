/* ----------------------------------------------------------------------- */
// Area Title: City of Jidoor
// Filename: kothus.c
// Author: Derek Noble
// Creator: dylanthalus@haven
// Creation Date: February 2nd, 1998
// Abstract: Kothus Deathknight Leader
// Revision History:
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include <std.h>
#include "../jidoor.h"

inherit LIB_LEADER;

static void create() {
   leader::create();
   SetKeyName("Kothus");
   SetShort("Kothus, the Fallen Knight");
   SetLong("Kothus is a great warrior whose face depicts a man of honour.  "
           "Dressed in the robes of an necromancer "
           "and wielding the weapons of a cavalier, it is obvious that "
           "Kothus is a Deathknight.  He is dark and solemn looking but "
           "he seems willing to help young people learn about his career. "
           "Judging by the look in his eyes, it would be a fatal mistake "
           "to test his combat ability.");
   SetId( ({ "kothus", "mage", "necromancer","cavalier","knight",
             "fallen knight","deathknight","jidoor_npc",}) );
   SetRace("lamrani");
   RemoveLanguage("Dasinri");
   SetLanguage("Sprith", 100, 1);
   SetClass("cavalier");
   SetGender("male");
   SetTown("Jidoor");
   SetStat("durability", 50);
   SetStat("strength", 35);
   SetSkill("necromancy", 135, 1);
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
                "energy field" : 100,
      "hunger"       : 100,
      "bolt"         : 100,
      ]) );
   SetInventory( ([
      JID_OBJ + "/clothing/necro_robe" : "wear robe",
      JID_OBJ + "/clothing/sandals" : "wear sandals",
      STD_SLASH + "shortsword" : "wield shortsword",
      STD_PIERCE + "fencing_sword" : "wield fencing sword",
                ]) );
   SetAction(1, ({
      "!cast energy field",
      "!speak The glorious profession of the Deathknight is not as "
      "as you likely think.  Those who practice the dark art are barely "
      "accepted as having honour and prestige that being a Cavalier "
      "normally would suggest.  The dark knights are honourable but our "
      "sense of prestige tends to be misinterpreted.",
      "!speak I could teach you about Cavaliers if you're already "
      "versed in the ways of the Necromancer.",
   }) );
   SetCombatAction(5, ({
      "!cast hunger",
      "!cast bolt",
      "!cast energy field",
      "!disarm",
                  }) );
}

void eventJoin(object who, string args) {
  if (!(who->GetClass()=="necromancer")) {
          eventForce("speak I only teach the ways of the Cavalier "
            "to those who have already begun their careers as "
            "Necromancers.  Go see Hima first if you are interested "
            "in becoming a Necromancer and then return to me "
            "if you wish to become a Deathknight.");
  return;
  }
  return leader::eventJoin(who, args);
}

