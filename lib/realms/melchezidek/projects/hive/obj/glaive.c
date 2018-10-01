#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("glaive");
   SetShort("a heavy glaive");
   SetId( ({ "glaive" }) );
   SetAdjectives( ({ "heavy" }) );
   SetLong("This is a long pole-arm with a stone shaft that has"
           " a small single-edged blade affixed to one end. The blade"
           " is made of metal and looks to be very sharp.");
   SetMass(250);
   SetValue(1200);
   SetDamagePoints(1500);
   SetVendorType(VT_WEAPON);
   SetWeaponType("pole");
   SetDamageType(SLASH|BLUNT);
   SetClass(25);
   SetMaterial( ({ "metal", "natural" }) );
   SetRepairDifficulty(30);
   SetHands(2);
   SetRepairSkills( ([
                       "weapon smithing" : 8,
                       "metal working" : 8,
                       "natural working" : 8,
                  ]) );
}
