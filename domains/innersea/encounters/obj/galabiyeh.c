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
  SetKeyName("galabiyeh");
  SetId(( { "galabiyeh"} ));
  SetAdjectives( ({ "linen" }) );
  SetShort("linen galabiyeh");
  SetLong(
    "This squarely cut robe of fine linen drapes around the "
    "shoulders and hangs below the knee. The loose fabric "
    "keeps the wearer comfortable in the fickle ocean weather, "
    "and may provide some obstruction to daggers and clubs."
  );
  SetMass(30);
  SetMaterial("textile");
  SetArmourClass(ARMOUR_CLOTH);
  SetSize(SIZE_MEDIUM);
  SetWarmth(20);
  SetValue(80);
  SetDamagePoints(2000);
  SetArmourType(A_BODY_ARMOUR);
}

