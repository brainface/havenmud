#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <armour_class.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
   armour::create();
   SetKeyName("boots");
   SetShort("a pair of leather boots");
   SetId( ({ "boots","boot" }) );
   SetAdjectives( ({ "pair of","leather" }) );
   SetLong("The boots are plain and simple.  There is nothing "
           "unordinairy about them.  They are made of leather.");
   SetMass(25);
   SetValue(75);
   SetClass(10,7);
    SetArmourClass(ARMOUR_LEATHER);
   SetArmourType(A_BOOT);
   SetProperty("multiples",1);
   SetVendorType(VT_ARMOUR);
   SetDamagePoints(110);
   SetMaterial( ({ "leather" }) );
   SetRepairDifficulty(3);
   SetRepairSkills( ([
                       "leather working" : 0,
                  ]) );
}
