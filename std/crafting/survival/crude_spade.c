/* Mahkefel 2017
 * crude crafted shovel
 */
#include <lib.h>
inherit LIB_LOCKPICK;

static void create() {
  ::create();
  SetShort("a crude spade");
  SetPickBonus(5);
  SetId( ({ "shade" }) );
  SetAdjectives( ({ "crude" }) );
  SetKeyName("spade");
  SetValue(15);
  SetLong("A spade-shaped piece of rusty metal attached to a short wooden "
    "pole by way of a few leather straps.");
  SetMass(10);
  SetDamagePoints(500);
  SetMaterials( ({ "metal", "wood" }) );
  SetProperty("farming item", 1);
  SetClass(2);
 }

