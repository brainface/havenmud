/* ----------------------------------------------------------------------- */
// Area Title: City of Jidoor
// Filename: yulisa.c
// Author: Derek Noble
// Creator: dylanthalus@haven
// Creation Date: February 2nd, 1998
// Abstract:  Yulisa Oracle Leader
// Revision History:
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include <std.h>
#include "../jidoor.h"

inherit LIB_LEADER;

static void create() {
   leader::create();
   SetKeyName("Yulisa");
   SetShort("Yulisa, the Dream Merchant");
   SetLong("A clever and charming young Sprite, Yulisa is one of Jidoor's "
           "finest Oracles.  Though interested in profit, she seems "
           "willing to teach her trade to those interested for free.");
   SetId( ({ "yulisa", "diviner","merchant","dream merchant",
             "oracle","jidoor_npc"}) );
   SetRace("sprite");
   SetClass("merchant");
   SetGender("female");
   SetTown("Jidoor");
   SetStat("durability", 65);
   SetStat("strength", 55);
   SetSkill("evokation", 1, 1);
   SetSkill("conjuring", 1, 1);
   SetUniqueSkills( ([
      ]) );
   SetFreeEquip( ([
          ]) );
   SetPlayerTitles( ([
      "merchant" : "the Dream Merchant"
      ]) );
   SetLevel(45);
   SetMorality(25);
   SetSpellBook( ([
                "energy field"    : 100,
                "chain lightning" : 100,
      ]) );
   SetInventory( ([
      JID_OBJ + "/clothing/vs_diviner_robe" : "wear robe",
      JID_OBJ + "/clothing/vs_sandals" : "wear sandals",
      STD_BLUNT + "mace" : "wield mace",
      ]) );
   SetAction(1, ({
      "!cast energy field",
      "!speak An Oracle is a Diviner versed in the finer points "
      "of trade and Merchant life.",
      "!speak I can teach you about Merchants if you're already "
      "versed in the ways of the Diviner.",
      }) );
   SetCombatAction(5, ({
      "!cast energy field",
      "!cast chain lightning",
      }) );
}

/*void eventJoin(object who, string args) {
  if (!(who->GetClass()=="diviner")) {
          eventForce("speak I only teach the ways of the Merchant "
            "to those who have already begun their careers as "
            "Diviners.  Go see Valora first if you are interested "
            "in becoming a Diviner and then return to me "
            "if you wish to become a Oracle.");
  return;
  }
  return leader::eventJoin(who, args);
}*/

