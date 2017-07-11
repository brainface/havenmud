
#include <lib.h>
#include <armour_types.h>
#include <vendor_types.h>
#include <armour_class.h>
#include <size.h>
#include <damage_types.h>

inherit LIB_ARMOUR;

static void create() {
  ::create();
  SetKeyName("jika-tabi");
  SetShort("a black jika-tabi");
  SetId( ({ "tabi", "jika-tabi", "jika tabi" }) );
  SetAdjectives( ({ "black" }) );
  SetLong("This jika-tabi is a black sock that is mid"
          " calf in length and has a separator between"
          " the big toe and the other toes. It has been"
          " treated with a thick sole to insulate the feet"
          " and provide some cushion.");
  SetValue(200);
  SetMass(20);
  SetSize(SIZE_MEDIUM);
  SetWarmth(2);
  SetMaterial( ({ "textile" }) );
  SetArmourClass(ARMOUR_CLOTH);
  SetArmourType(A_LONG_SOCK);
  SetDamagePoints(450);
  SetVendorType(VT_ARMOUR);
  SetRepairSkills( ([
          "armour smithing" : 10,
          "textile working" : 10,
         ]) );   
  SetRepairDifficulty(15);
}
