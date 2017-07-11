/*  A standard set of newbie lockpicks */
#include <lib.h>
inherit LIB_LOCKPICK;

static void create() {
  ::create();
  SetShort("a set of cheap lockpicks");
  SetPickBonus(5);
  SetId( ({ "picks", "lockpicks" }) );
  SetAdjectives( ({ "set of", "cheap" }) );
  SetKeyName("lockpicks");
  SetValue(50);
  SetLong("This set of old and rusty lockpicking tools would "
          "not be used by anyone that could afford better.");
  SetMass(60);
  SetDamagePoints(400);
  SetClass(4);
 }
