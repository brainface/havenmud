/* a goat
   kyla 11-97
*/
#include <lib.h>
#include "../mansion.h"
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("goat");
  SetId( ({"goat"}) );
  SetAdjectives( ({"horned", "short", "hairy"}) );
  SetShort("a hairy goat");
  SetLong("Though short, this hairy goat looks quite powerfull. "
         "His horns are quite impressive for an animal his size."); 
  SetGender("male");
  SetFriends( ({"goat", "shepherd"}) );
  SetRace("goat",1);
  AddLimb("torso",0,1);
  AddLimb("head","torso",1);
  AddLimb("right front leg","torso",2);
  AddLimb("left front leg","torso",2);
  AddLimb("left back leg","torso",2);
  AddLimb("right back leg","torso",2);
  AddLimb("right back hoof","right back leg",3);
  AddLimb("left back hoof","left back leg",3);
  AddLimb("left front hoof","left front leg",3);
  AddLimb("right front hoof","right front leg",3);
  AddLimb("tail","torso",4);
  SetClass("animal");
  SetLevel(8);
  }
