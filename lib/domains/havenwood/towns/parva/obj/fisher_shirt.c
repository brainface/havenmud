#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <size.h>
#include <armour_class.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
   armour::create();
   SetKeyName("shirt");
   SetShort("a green shirt");
   SetId( ({ "shirt" }) );
   SetAdjectives( ({ "shirt" }) );
   SetLong("A plain tough green textile was used to make this "
           "green shirt.  There are matching green buttons up "
           "the front.");
   SetMass(15);
   SetValue(15);
   SetArmourClass(ARMOUR_CLOTH);
   SetSize(SIZE_MEDIUM);
   SetVendorType(VT_CLOTHING);
   SetArmourType(A_SHIRT);
   SetDamagePoints(70);
   // SetProtection(BLUNT,2);
   // SetProtection(SLASH,2);
   // SetProtection(PIERCE,2);
   // SetProtection(COLD,4);
   // SetProtection(HEAT,2);
   SetWear("The material is rough and scratchy.");
   SetMaterial( ({ "textile" }) );
   SetWarmth(10);
   SetRepairDifficulty(5);
   SetRepairSkills( ([
      "textile working" : 1,
      ]) );
   SetProperty("history","This shirt was the property of a fisherman.");
}
