/* Lockpicks for the more advanced picker */
#include <lib.h>
inherit LIB_LOCKPICK;

static void create() {
  ::create();
  SetShort("a set of sharp lockpicks");
  SetPickBonus(20);
  SetId( ({ "picks", "lockpicks" }) );
  SetAdjectives( ({ "set of", "sharp" }) );
  SetKeyName("lockpicks");
  SetValue(250);
  SetLong("This set of sharp and clean lockpicks look "
          "unused and able to aid in opening some locks.");
  SetMass(60);
  SetDamagePoints(400);
  SetClass(10);
 }
