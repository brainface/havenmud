#include <lib.h>
#include <armour_types.h>
#include <vendor_types.h>
#include <armour_class.h>
#include <size.h>
#include <damage_types.h>

inherit LIB_ARMOUR;

static void create() {
  ::create();
  SetKeyName("sanjaku-tenugui");
  SetShort("a black sanjaku-tenugui");
  SetId( ({ "sanjaku-tenugui", "sanjaku", "tenugui",
          " sanjaku tenugui", "helmet", "mask" }) );
  SetAdjectives( ({ "black" }) );
  SetLong("This sanjaku-tenugui is made of three equal"
          " length clothes wrapped in such a way as to"
          " cover the entirety of the head, yet fit securely"
          " and be flexible enough to move. A slight slit"
          " is created over the eyes to allow the wearer"
          " the see.");
  SetValue(500);
  SetMass(30);
  SetSize(SIZE_MEDIUM);
  SetWarmth(5);
  SetMaterial( ({ "textile" }) );
  SetArmourClass(ARMOUR_CLOTH);
  SetArmourType(A_HELMET);
  SetDamagePoints(450);
  SetVendorType(VT_ARMOUR);
  SetRepairSkills( ([
          "armour smithing" : 10,
          "textile working" : 10,
         ]) );   
  SetRepairDifficulty(15);
}

