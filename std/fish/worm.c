#include <lib.h>
#include <vendor_types.h>
inherit LIB_BAIT_WITH;
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("worm");
   SetShort("a wriggling worm");
   SetId( ({ "worm" }) );
   SetAdjectives( ({ "wriggling" }) );
   SetLong("This worm wriggles some, and is small in size.");
   SetMass(1);
   SetValue(3);
   SetVendorType(VT_FISHING);
   SetBaitStrength(1);
   SetMaterial( ({ "natural" }) );
   SetDamagePoints(1);
}

static mixed AddSave(mixed *vars) {
   return item::AddSave(vars);
}
