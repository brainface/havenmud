
#include <lib.h>
#include <damage_types.h>
#include <domains.h>
#include <vendor_types.h>

inherit LIB_ITEM;

static void create() {
    item::create();
    SetKeyName("shortsword");
   SetId( ({ "shortsword","sword" }) );
    SetAdjectives("rusty");
    SetShort("a rusty shortsword");
    SetLong("This short, hard slab of metal is attached to a makeshift handle "
            "wrapped with a course leather hide.  The dull blade shows many "
      "knicks and scars, showing its heavy use in battles past.  It looks "
       "too worn down to be of any real use.");
    SetMass(50);
    SetValue(40);
    SetVendorType(VT_WEAPON);
    SetClass(12);
    SetDamageType(SLASH);
   SetWeaponType("slash");
}
