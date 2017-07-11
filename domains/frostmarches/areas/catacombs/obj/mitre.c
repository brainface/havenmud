#include <lib.h>
#include <damage_types.h>
#include <armour_class.h>
#include <size.h>
#include <armour_types.h>
#include <vendor_types.h>

inherit LIB_ARMOUR;

static void create()
{
  armour::create();
  SetKeyName("mitre");
  SetId(( { "mitre" } ));
  SetShort("a mitre");
  SetLong("This beautifully crafted mitre is made of"
          " a rich golden cloth. Two folds, one in the"
          " front and one in the back, are bent upwards"
          " forming an obtuse point high above the base"
          " of the mitre. The front fold has a thick black"
          " vertical line running from the base to the very"
          " point of the fold.");
  SetMass(60);
  SetMaterial( ({ "textile" }) );
  SetRepairDifficulty(15);
  SetWarmth(20);
  SetValue(100);
  SetDamagePoints(400);
  SetArmourClass(ARMOUR_CLOTH);
  SetSize(SIZE_MEDIUM);
  SetArmourType(A_HELMET);
  SetVendorType(VT_TREASURE | VT_ARMOUR);
}
