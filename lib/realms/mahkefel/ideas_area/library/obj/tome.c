/* Tome for nifty warlock spell
 *   for kicks, it also hits for bricks when used as a weapon
 *
 *
 */
#include <lib.h>
#include <damage_types.h>
inherit LIB_SCROLL;

static void create() {
  ::create();
  SetKeyName("sulfurous tome");
  SetShort("a sulfurous tome");
  SetId( ({ "tome" }) );
  SetAdjectives( ({ "sulfurous" }) );
  SetLong(
    "This leather-bound book is weathered and worn. Deep sulfur stains mar "
    "the surface and seep through the pages. A silver pentagram inscribed on "
    "cover shows no signs of wear, but alternates quickly between emitting a "
    "biting cold and searing heat. It is unlikely anything good could come "
    "from reading this book."
  );
  SetClass(30);
  SetDamagePoints(500);
  SetWeaponType("blunt");
  SetDamageType(COLD|HEAT);
  SetSpell("banefire");
  SetMass(20);
  SetValue(2000);
}

