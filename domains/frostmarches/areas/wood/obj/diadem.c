/* amber diadem
    Ela 12/6/98
*/

#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("diadem");
  SetId( ({ "diadem", "circlet" }) );
  SetAdjectives( ({ "amber" }) );
  SetShort("an amber diadem");
  SetLong("This exquisite diadem shimmers incandescently. "
         "The circlet is made of a narrow band of the purest "
         "gold, coming to a graceful vee at the front. A " 
        "teardrop of glowing amber is suspended there, "
         "crafted to drape the forehead of the wearer.");
  SetMass(15);
  SetSize(SIZE_MEDIUM);
  SetValue(4000);
  SetArmourClass(ARMOUR_PLATE);
  SetProperty("laoise_flag", 1);
  SetArmourType(A_HELMET);
  SetVendorType(VT_TREASURE|VT_GEM);
  SetDamagePoints(250);
  // SetProtection(MAGIC, 10);
  // SetProtection(SLASH, 2);
  // SetProtection(BLUNT, 1);
  SetMaterial( ({"natural"}) );
  SetWarmth(0);
  SetProperties( ([
                 "magic" : "The diadem radiates the "
                            "brilliant incandescence of "
                            "magic.",
               ]) );
  }
