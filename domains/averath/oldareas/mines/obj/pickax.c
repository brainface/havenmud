// amelia
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;

static void create() {
   ::create();
   SetKeyName("pick-axe");
   SetShort("a dirty pick-axe");
   SetId( ({ "axe","ax","pick-axe" }) );
   SetAdjectives( ({ "dirty","pick" }) );
   SetLong("A wooden handle is tightly tied to a hunk of stone, "
           "shaped into a point at the end.  It is highly functional, "
           "though it lacks in grace and beauty.  A thin coat of "
           "grime covers it.  It is unwieldy enough to require "
           "two hands to wield it.");
   SetMass(200);
   SetValue(20); 
   SetVendorType(VT_WEAPON);
   SetDamagePoints(400);
   SetWeaponType("blunt");
   SetDamageType(BLUNT);
   SetClass(20);
   SetHands(2);
}
