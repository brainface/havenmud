/* a flamberge - Duhoc jan. 99 */
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("flamberge");
  SetId( ({"flamberge", "blade", "sword"}) );
  SetShort("a two-hand flamberge");
	SetAdjectives( ({ "two-hand" }) );
  SetLong("The flamberge is a large, two-hand sword with a wavy, curved blade "
    "made to resemble a flame.  It looks quite flamboyant, yet very functional "
    "when used by skilled hands.");
  SetClass(15);
  SetHands(2);
  SetDamagePoints(1500);
  SetValue(300);
  SetWeaponType("hack");
  SetDamageType(SLASH);
	SetMass(350);
	SetVendorType(VT_WEAPON);
}

