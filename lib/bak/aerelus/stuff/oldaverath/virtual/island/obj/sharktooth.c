// Amelia
#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   ::create();
   SetKeyName("tooth");
   SetShort("a dog shark's tooth");
   SetId(({ "tooth" }) );
   SetAdjectives( ({ "dog","shark's","shark" }) );
   SetLong("Light yet durable, the dog shark employs its teeth "
           "to gnash through the slick, scaley surfaces of "
           "salmon.  About 7 centimeters in length, the only "
           "safe surface is a small 2-centimeter base.  The "
           "remainder is sharp on three edges, giving it a "
           "triangular shape.");
   SetMass(1);
   SetValue(150);
   SetVendorType(VT_WEAPON);
   SetDamagePoints(350);
   SetWeaponType("knife");
   SetDamageType(SLASH);
//   SetMaterial( ({ "natural" }) );
//   SetRepairDifficulty(9);
//   SetRepairSkills( ([
//                       "natural working" : 0,
//                       "weapon smithing" : 0,
//                  ]) );
   SetClass(15);
}
