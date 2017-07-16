#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("sword");
   SetShort("a dull sword");
   SetId( ({ "sword" }) );
   SetAdjectives( ({ "dull" }) );
   SetLong("The sword is designed for a slashing motion, to cut up one's opponent and "
           "hopefully defeat it.  It is fairly dull, but that seems to be a design "
           "flaw rather than a sign of needed maitenance.");
   SetClass(10);
   SetValue(0);
   SetMass(40);
   SetVendorType(VT_WEAPON);
   SetDamageType(SLASH);
   SetWeaponType("slash");
   SetMaterial( ({ "metal" }) );
   SetDamagePoints(800);
   SetProperty("history","This dull sword was given out by a leader "
               "in Ditmar.");
}