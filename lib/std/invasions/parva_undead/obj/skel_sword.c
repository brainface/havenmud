/*  A worthless sword for the skeletons
 *  Coded for the undead invasion.
 *  Duuk
 */

#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("shortsword");
  SetShort("a rusted shortsword");
  SetId( ({ "sword", "shortsword" }) );
  SetAdjectives( ({ "rusted" }) );
  SetLong(
    "This shortsword has obviously been in use for a long time. "
    "The blade is rusted and the handle is loose."
  );
  SetClass(13);
  SetMass(120);
  SetValue(30);
  SetDamageType(SLASH);
  SetWeaponType("slash");
  SetMaterial( ({ "metal" }) );
  SetDamagePoints(500);
}
