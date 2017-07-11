#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <size.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
  ::create();
  SetKeyName("shinobi shozoku");
  SetShort("a black shozoku");
  SetId( ({ "shozoku", "armour", }) );
  SetAdjectives( ({ "shinobi", "black" }) );
  SetLong("This is a black cloth armour made especially for the"
          " Shinobi Masters of Tairi. It has been crafted"
          " with much care. It is light weight and extremely"
          " durable and the black color provides extra"
          " cover at night time.");
  SetArmourType(A_BODY_ARMOUR);
  SetMass(120);
  SetArmourClass(ARMOUR_CLOTH);
  SetSize(SIZE_MEDIUM);
  SetValue(1000);
  SetDamagePoints(4500);
  SetMaterial( ({ "textile" }) );
  SetWarmth(30);
  SetVendorType(VT_ARMOUR);
  SetRepairSkills( ([
          "armour smithing" : 10,
          "textile working" : 10,
         ]) );   
  SetRepairDifficulty(15);
}
