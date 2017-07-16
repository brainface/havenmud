#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <armour_class.h>
#include <vendor_types.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
   armour::create();
   SetKeyName("boots");
   SetShort("a set of two boots");
   SetId( ({ "boot","boots" }) );
   SetAdjectives( ({ "set of","two","brown","light" }) );
   SetLong("The light brown boots come in a set of two, one for "
           "each foot.  The boots are in a pull on style; there "
           "are no laces or bindings to hold them on.  "
           "They are made of leather.");
   SetMass(25);
   SetValue(55);
   SetSize(SIZE_MEDIUM);
   SetArmourClass(ARMOUR_LEATHER);
   SetVendorType(VT_CLOTHING);
   SetArmourType(A_BOOT);
   SetProperty("multiples",1);
   SetDamagePoints(140);
   // SetProtection(BLUNT,5);
   // SetProtection(SLASH,4);
   // SetProtection(PIERCE,2);
   // SetProtection(COLD,5);
   // SetProtection(HEAT,2);
   SetWear("The boots resist being pulled on.");
   SetMaterial( ({ "leather" }) );
   SetWarmth(6);
   SetRepairDifficulty(11);
   SetRepairSkills( ([
                       "leather working" : 1,
                  ]) );
   SetProperty("history","It used to be the property of Magnum, Parva Banker.");
}
