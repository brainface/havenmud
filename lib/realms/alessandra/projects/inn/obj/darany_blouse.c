//   by Alessandra 9/04    //

#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
#include <armour_types.h>
#include <size.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("blouse");
  SetShort("a ruffled blouse");
  SetId( ({ "blouse" }) );
  SetAdjectives( ({ "ruffled", "thin", "white" }) );
  SetLong(
     "This blouse is made of a thin white material. The neckline "
     "is rather low and ruffles lead from there down. The sleeves are "
     "long and end in ruffled cuffs."
     );
  SetMass(10);
  SetWarmth(15);
  SetValue(30);
  SetSize(SIZE_MEDIUM);
  SetDamagePoints(150);
  SetMaterial( ({"textile"}) );
  SetRepairSkills( ([
     "textile working" : 1,
     ]) );
  SetRepairDifficulty(5);
  SetVendorType(VT_CLOTHING);
  SetArmourType(A_SHIRT);
  }
