#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <size.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
  ::create();
  SetKeyName("sleeve");
  SetShort("a black cloth sleeve");
  SetId( ({ "sleeve" }) );
  SetProperty("multiples", 1);
  SetAdjectives( ({ "cloth", "black" }) );
  SetLong("This cloth sleeve fits over the hand and"
          " is secured by a loop that goes over the"
          " middle finger. It partially covers the"
          " hand and fully covers the forearm. The"
          " fingers are left uncovered for various"
          " acts requiring greater dexterity.");
  SetArmourType(A_LONG_GLOVE);
  SetMass(20);
  SetArmourClass(ARMOUR_CLOTH);
  SetSize(SIZE_MEDIUM);
  SetValue(250);
  SetDamagePoints(450);
  SetMaterial( ({ "textile" }) );
  SetWarmth(1);
  SetVendorType(VT_ARMOUR);
  SetRepairSkills( ([
          "armour smithing" : 10,
          "textile working" : 10,
         ]) );   
  SetRepairDifficulty(15);
}
