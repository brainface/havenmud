#include <lib.h>

inherit LIB_LOCKPICK;

static void create() {
  ::create();
  SetShort("a set of decent lockpicks");
  SetLong("This is a small set of tools used to pick locks.");
  SetPickBonus(10);
  SetId( ({ "picks", "lockpicks" }) );
  SetAdjectives( ({ "set", "decent" }) );
  SetMaterials( ({ "wood" }) );
  SetKeyName("lockpicks");
  SetValue(400);
  SetMass(60);
  SetDamagePoints(800);
  SetClass(6);
}
