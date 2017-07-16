/* free equip for hunters and shamans
    kyla 11-2-97
*/
#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <armour_class.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("leather vest");
  SetId( ({"vest"}) );
  SetAdjectives( ({ "cured", "leather" }) );
  SetShort("a cured leather vest");
  SetLong(
     "This vest has been made out of a durable leather material. "
     "It appears to have been cured with a honey mixture to protect "
     "the vest from wear. "
  );
  SetVendorType(VT_ARMOUR);
  SetArmourType(A_VEST);
  SetArmourClass(ARMOUR_LEATHER);
  SetMass(200);
  SetValue(250);
  SetDamagePoints(1200);
  SetSize(SIZE_MEDIUM);
  SetMaterial( ({ "leather"}) );
  SetWarmth(2);
  SetRepairSkills( ([
     "leather working" : 5,
  ]) );
  SetRepairDifficulty(10);
  }
