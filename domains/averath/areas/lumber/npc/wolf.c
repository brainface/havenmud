#include <lib.h>
inherit LIB_NPC;

static void create() {
  npc::create();
  SetKeyName("grey wolf");
  SetShort("a cunning grey wolf");
SetId( ({ "wolf"}) );
 SetAdjectives( ({ "grey" ,"cunning" }) );
  SetRace("dog");
  SetClass("animal");
  SetLong(
    "This animal seems to have no fear of you. "
    "His cold eyes track your movement and "
    "his mangy fur and skinny build suggests  "
    "he has not fed in a while.  You may make an "
    "excellent meal. "
  );
  SetGender("male");
  SetLevel(5);
}
