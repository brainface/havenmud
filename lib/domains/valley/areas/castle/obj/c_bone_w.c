#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("white bone");
   SetShort("a white bone");
   SetId( ({ "bone" }) );
   SetAdjectives( ({ "white" }) );
   SetLong("The bone is a shiny clean, free of dust and flesh both.  "
           "Its surface is rough and full of tiny little holes.");
   SetMass(7);
   SetValue(5);
   SetVendorType(VT_WEAPON|VT_TREASURE);
   SetDamagePoints(10);
   SetClass(3);
   SetDamageType(BLUNT);
   SetWeaponType("blunt");
   SetMaterial( ({ "natural" }) );
   SetRepairDifficulty(1);
   SetRepairSkills( ([
                       "natural working" : 1,
                       "weapon smithing" : 1,
                  ]) );
}