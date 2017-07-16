#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("axe");
   SetShort("a huge two-handed axe");
   SetId( ({ "axe" }) );
   SetAdjectives( ({ "huge", "two-handed", "two handed" }) );
   SetLong("This is a large axe with a grip that is nearly four and a half feet"
           " long. The grip ends in an enormous metal axe head that is nearly"
           " twice the size of an average human head. The shaft is made of"
           " a dark stone with two soft leather grips spaced about"
           " a foot and a half apart.");
   SetMass(350);
   SetValue(1500);
   SetDamagePoints(1500);
   SetVendorType(VT_WEAPON);
   SetWeaponType("hack");
   SetDamageType(SLASH);
   SetClass(32);
   SetMaterial( ({ "metal", "natural" }) );
   SetRepairDifficulty(30);
   SetHands(2);
   SetRepairSkills( ([
                       "weapon smithing" : 8,
                       "metal working" : 8,
                       "natural working" : 8,
                  ]) );
}
