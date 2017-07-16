// Mahkefel 20101117
// pirate eyepatch
#include <lib.h>
#include <damage_types.h>
#include <armour_types.h>
#include <armour_class.h>
#include <vendor_types.h>
#include <size.h>

inherit LIB_ARMOUR;

static void create()
{
  armour::create();
  SetKeyName("leather eyepatch");
  SetId( ({ "eyepatch" }) );
  SetAdjectives( ({ "leather" }) );
  SetShort("a leather eyepatch");
  SetLong(
    "This crude leather eyepatch would keep the bugs from crawling into "
    "your eyesocket. A simple loop of twine attaches it to the face."
  );
  SetMass(20);
  SetValue(2000);
  SetSize(SIZE_MEDIUM);
  SetArmourClass(ARMOUR_LEATHER);
  SetDamagePoints(1500);
  SetArmourType(A_VISOR);
  SetVendorType(VT_TREASURE | VT_ARMOUR);
  SetMaterial( ({ "leather" }) );
  SetWarmth(0);
  //SetWear("You miss your depth perception.");
  //SetWear("You look a bit scurvish.");
  SetRepairDifficulty(20);
}

