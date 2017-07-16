/* Javelin
 * Ranquest@Haven
 * 02/13/99
 */
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
        item::create();
        SetShort("a javelin");
        SetLong(
          "This javelin is quite versatile, as it can be used"
          " for either throwing or as a light spear.");
        SetId( ({"javelin","weapon"}) );
        SetClass(8);
        SetDamagePoints(250);
        SetValue(150);
        SetWeaponType("projectile");
        SetDamageType(PIERCE);
        SetKeyName("javelin");
        SetMass(150);
        SetVendorType(VT_WEAPON);
    }