/* Mostly because I wanted to
 * code a hoe and not have it
 * respond to sexual stuff.
 * Duuk
 */
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;
inherit LIB_DIGGING;

static void create() {
  item::create();
  digging::create();
  SetKeyName("hoe");
  SetShort("a medium length hoe");
  SetId( ({ "hoe" }) );
  SetAdjectives( ({ "medium", "length" }) );
  SetProperty("farming item", 1);
  SetMass(100);
  SetValue(50);
  SetLong("This medium length farming tool is of almost no combat "
          "value whatsoever. If used, it could be used as a pole "
          "weapon.");
  SetWeaponType("pole");
  SetVendorType(VT_FISHING);
  SetDamageType(SLASH);
  SetDamagePoints(1100);
  SetClass(10);
  SetMaterial( ({ "metal", "wood" }) );
  SetHands(2);
}