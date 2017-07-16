#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <size.h>
#include <armour_class.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
   armour::create();
   SetKeyName("pants");
   SetShort("a pair of striped pants");
   SetId( ({ "pants" }) );
   SetAdjectives( ({ "pair of","striped" }) );
   SetLong("These pants are not much to look at, and would hurt "
           "the eyes of most races.  They are striped orange and "
           "red in color, with the marks of having been sweated "
           "in often.  They were made for a short and fat "
           "individual.");
   SetMass(20);
   SetValue(10);
   SetArmourClass(ARMOUR_CLOTH);
   SetSize(SIZE_MEDIUM);
   SetVendorType(VT_CLOTHING);
   SetArmourType(A_PANTS);
   SetDamagePoints(25);
   // SetProtection(BLUNT,1);
   // SetProtection(SLASH,1);
   // SetProtection(PIERCE,1);
   // SetProtection(COLD,2);
   // SetProtection(HEAT,1);
   SetWear("The pants are slightly damp.");
   SetMaterial( ({ "textile" }) );
   SetWarmth(15);
   SetRepairDifficulty(10);
   SetRepairSkills( ([
                       "textile working" : 1,
                  ]) );
   SetProperty("history","These pants used to be the property "
               "of Pons, a Parva storekeeper, or Snop, his twin brother.");
}
