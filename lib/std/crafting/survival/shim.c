/* Mahkefel 2017 
 * crude crafted lockpicks
 */
#include <lib.h>
inherit LIB_LOCKPICK;

static void create() {
  ::create();
  SetShort("a crude metal shim");
  SetPickBonus(5);
  SetId( ({ "shim" }) );
  SetAdjectives( ({ "crude", "metal" }) );
  SetKeyName("shim");
  SetValue(5);
  SetLong("A wide strip of metal banged into a thin wedge. There's "
    "far better tools to open a lock, but it's better than your fingers.");
  SetMass(10);
  SetDamagePoints(200);
  SetClass(2);
 }

