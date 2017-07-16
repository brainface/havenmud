
/* Lockpicks for the more advanced picker */
#include <lib.h>
inherit LIB_LOCKPICK;

static void create() {
  ::create();
  SetShort("a set of excellent lockpicks");
  SetPickBonus(50);
  SetId( ({ "picks", "lockpicks" }) );
  SetAdjectives( ({ "set of", "excellent" }) );
  SetKeyName("lockpicks");
  SetValue(650);
  SetLong("This set of lockpicks looks to be the best that money can buy "
          "and perfect for various situations.");
  SetMass(60);
  SetDamagePoints(400);
  SetClass(15);
 }
