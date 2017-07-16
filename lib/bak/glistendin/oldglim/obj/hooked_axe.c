/* an axe - Duhoc jan. 99 */
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("hooked battle axe");
  SetId( ({ "axe", }) );
  SetShort("a hooked battle axe");
	SetAdjectives( ({ "hooked", "battle" }) );
  SetLong("The hooked battle axe is a large, impressive axe with a hook "
    "at the top of the head.  When swung, the hook will add extra damage "
    "by ripping through the flesh of a enemy.");
  SetClass(17);
  SetHands(2);
  SetDamagePoints(1600);
  SetValue(250);
  SetWeaponType("hack");
  SetDamageType(SLASH);
	SetMass(460);
	SetVendorType(VT_WEAPON);
}
