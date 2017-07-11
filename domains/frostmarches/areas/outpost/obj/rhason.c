#include <lib.h>
#include <damage_types.h>
#include <armour_types.h>
#include <armour_class.h>
#include <vendor_types.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
armour::create(); 

  SetKeyName("cassock");
  SetId( ({ "cassock","rhason","coat" }) );
  SetShort("a black cassock");
  SetAdjectives( ({ "black" }) );
  SetLong("This black cassock has long sleeves and fits the body closely. "
          "The front has button closure and is normally worn under the "
          "armour of Orthodox Kylin monks. Sewn in red on right side of the "
          "cassock is the symbol of the Kylin faith, a balance with a "
          "dragon entwined around it. This robe has a thin layer of fur "
          "lining the inside to protect against the cold. ");
  SetWarmth(30);
  SetMaterial( ({ "textile" }) );
  SetRepairDifficulty(10);  
  SetArmourClass(ARMOUR_CLOTH);
  SetVendorType(VT_ARMOUR);
  SetArmourType(A_BODY_ARMOUR);
  SetSize(SIZE_MEDIUM);
  SetMass(80);
  SetValue(75);
  SetDamagePoints(800);
  }