//coded by Syra 12/97
#include <lib.h>
#include <damage_types.h>
#include <armour_types.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("coat");
  SetWarmth(40);
  SetId(( { "coat" } ));
  SetAdjectives( ({"beaver","winter","heavy","warm" }) );
  SetShort("a winter coat");
  SetLong("The heavy coat is furnished with several "
          "beaver pelts, which are "
          "certain to keep the wearer warm.");
  SetMass(100);
  SetValue(60);
  SetDamagePoints(250);
  SetProtection(PIERCE,1);
  SetProtection(SLASH,1);
  SetProtection(COLD,8);
  SetProtection(MAGIC,2);
  SetProtection(ACID,2);
  SetArmourType(A_CLOAK);
  SetVendorType(VT_TREASURE | VT_ARMOUR);
  SetWear("You feel protected from the cold as you put the coat on.");

}
