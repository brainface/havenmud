#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("knife");
   SetShort("a plain little knife");
   SetId( ({ "knife" }) );
   SetAdjectives( ({ "plain","little" }) );
   SetLong("There is nothing exceptional about this knife.  "
           "Its quality is fair, and its design normal.");
   SetMass(10);
   SetValue(35);
   SetClass(7);
   SetVendorType(VT_WEAPON);
   SetWeaponType("knife");
   SetDamageType(SLASH);
   SetDamagePoints(150);
   SetMaterial( ({ "metal" }) );
   SetRepairDifficulty(15);
   SetRepairSkills( ([
                       "weapon smithing" : 1,
                       "metal working" : 1,
                  ]) );
   SetProperty("history","This knife used to be the property of "
               "Pons, a storekeeper in Parva.  His suspicious "
               "instincts caused him to carry it at all times, "
               "even though it made some of his customers nervous.");
}
