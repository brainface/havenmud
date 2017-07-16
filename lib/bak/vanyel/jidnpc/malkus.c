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
 SetId( ({ "malkus", "sye", "malkus sye", "guide"}) );
 SetAdjectives( ({ "mystical" }) );
 SetClass("mystic");
 SetReligion("Magildan","Magildan");
 SetLevel(45);
 SetMorality(80);
 AddTrainingSkills("healing");
 AddTrainingSkills("conjuring");
 AddTrainingSkills("evokation");
 AddTrainingSkills("faith");
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
      JID_OBJ + "/clothing/mystic_robe" : "wear robe",
      JID_OBJ + "/clothing/sandals" : "wear sandals",
   ]) );
}
