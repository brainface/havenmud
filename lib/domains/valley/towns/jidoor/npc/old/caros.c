#include <lib.h>
#include <daemons.h>
#include "../jidoor.h"

inherit LIB_LEADER;
static void create() {
 leader::create();
  SetKeyName("caros");
  SetShort("Caros, the Magildan Spiritual Guide");
  SetId( ({ "caros", "guide" }) );
  SetAdjectives( ({ "magildan","spiritual" }) );
  SetRace("sprite");
  SetNoMulti(1);
  SetNoJoin(1);
  SetClass("priest");
  SetGender("male");
  SetLong("Caros is an artifact from a time long before Mystics ever "
          "existed. He is an ancient sprite, versed in the ways of the "
          "cleric.  He stands here as a resource for the remaining "
          "clerics of the Magildan faith, ready to teach them spells.");
  SetMorality(0);
  SetLevel(100);
  SetReligion("Magildan","Magildan");
  SetSkill("melee combat", 70, 1);
  SetAction(1, ({
                  "!emote mutters a little prayer.",
                  "!emote mutters a little prayer.",
                  }) );
  SetReligion("Magildan","Magildan");
  SetTown("Jidoor");
  SetTaughtSpheres( ({"clerical","clerical healing","clerical evokation",
                      "clerical necromancy", "clerical enchantment", 
                      "clerical divination", "clerical planar magic" }) );
  SetInventory( ([ 
      JID_OBJ + "/clothing/mystic_robe" : "wear robe",
      JID_OBJ + "/clothing/sandals" : "wear sandals",
   ]) );
  }
