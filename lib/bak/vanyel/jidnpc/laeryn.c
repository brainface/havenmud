/* ----------------------------------------------------------------------- */
// Area Title: City of Jidoor
// Filename: laeryn.c
// Author: Derek Noble
// Creator: dylanthalus@haven
// Creation Date: Sept 17th, 1998
// Abstract: Laeryn the Greeter of the Magildan Temple
// Revision History: 
// Last Update: 
/* ----------------------------------------------------------------------- */

#include <lib.h>
#include <daemons.h>
#include "../jidoor.h"

inherit LIB_LEADER;
static void create() {
 leader::create();
  SetKeyName("Laeryn");
  SetShort("laeryn the Magildan Mystic");
  SetId( ({ "Laeryn", "mystic" }) );
  SetAdjectives( ({ "magildan" }) );
  SetRace("lamrani");
  SetNoMulti(1);
  SetNoJoin(1);
  SetClass("mystic");
  SetGender("female");
  SetLong("Laeryn is a young Lamrani who looks eager to help people "
          "interested in the faith of Magildan.  She is tall and pale "
          "but friendly looking.  She doesn't appear to be very "
          "threatening but could likely defend herself if attacked.");
  SetMorality(60);
  SetLevel(25);
  SetReligion("Magildan","Magildan");
  SetAction(1, ({
                  "!speak No one may enter the temple who is not of "
                  "the Magildan faith.  I will convert you if you wish. ",
                  "!speak Glory to the Gods of Energy!",
                  "!emote mutters a little prayer.",
                  "!emote mutters a little prayer.",
                  }) );
  SetReligion("Magildan","Magildan");
  SetTown("Jidoor");
  SetInventory( ([ 
      JID_OBJ + "/clothing/mystic_robe" : "wear robe",
      JID_OBJ + "/clothing/sandals" : "wear sandals",
   ]) );
  }
