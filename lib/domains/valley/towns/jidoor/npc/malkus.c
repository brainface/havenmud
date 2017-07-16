/* ----------------------------------------------------------------------- */
// Area Title: City of Jidoor
// Filename: malkus.c
// Author: Derek Noble
// Creator: dylanthalus@haven
// Creation Date: Oct 21st, 1998
// Abstract: Malkus the Trainer for Mystics
// Revision History:
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include "../jidoor.h"

inherit LIB_TRAINER;

static void create()
{
 trainer::create();
 SetKeyName("malkus");
 SetShort("Malkus Sye, the Mystical Guide");
 SetLimit(1);
 SetId( ({ "malkus", "sye", "malkus sye", "guide","jidoor_npc",}) );
 SetAdjectives( ({ "mystical" }) );

 SetClass("mystic");
 SetSkill("natural magic",1,1);
 SetSkill("conjuring",1,1);
 SetSkill("evokation",1,1);
 SetReligion("Magildan","Magildan");
 SetLevel(45);
 SetMorality(80);
 SetGender("male");
 SetRace("sprite");
 SetLong("Malkus Sye is a stout and stern looking sprite.  He is here to "
         "help train the Magildan mystics in the ways of their profession. "
         "He looks entirely capable of defending himself.");
 SetTown("Jidoor");
 SetAction(1, ({
     "!emote mutters a little prayer.",
     "!smile nervala",
                }) );
  SetInventory( ([
     JID_OBJ + "/clothing/vs_mystic_robe" : "wear robe",
     JID_OBJ + "/clothing/vs_sandals" : "wear sandals",
     ]) );
  SetSpellBook( ([
                "heat"       : 100,
                "freeze"     : 100,
                "misty bolt" : 100,
                "vine wall"  : 100,
          ]) );
  SetCombatAction(50, ({
          "!cast vine wall",
          "!cast heat",
          "!cast freeze",
          "!cast misty bolt",
                }) );

  // mahkefel
  AddTrainingSkill("pole combat");
  AddTrainingSkill("natural working");
  AddTrainingSkill("stealth");
  AddTrainingSkill("farming");
  AddTrainingSkill("fishing");
  AddTrainingSkill("skinning");
}

