/* Lockpicks for the more advanced picker */
#include <lib.h>
inherit LIB_LOCKPICK;

static void create() {
  ::create();
  SetShort("a set of gleaming lockpicks");
  SetPickBonus(75);
  SetId( ({ "picks", "lockpicks" }) );
  SetAdjectives( ({ "set of", "gleaming" }) );
  SetKeyName("lockpicks");
  SetValue(1500);
  SetLong("This set of lockpicks shimmers to the touch. They appear to be almost ethereal "
          "in nature yet your eyes can't quite seem to hold onto them long enough to tell. "
          "These are most likely the best lockpicks available to anyone.");
  SetMass(60);
  SetDamagePoints(400);
  SetClass(15);
 }
