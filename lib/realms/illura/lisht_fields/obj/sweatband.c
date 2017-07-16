//Illura@Haven
//Sept 2009
//sweatband
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
  SetKeyName("sweatband");
  SetId(( { "sweatband", "band"} ));
  SetAdjectives( ({ "linen" }) );
  SetShort("linen sweatband");
  SetLong(
    "This thin strip of linen is wound around the head, "
    "offering slight protection but mostly serving to "
    "keep sweat and hair out of one's eyes.");
  SetMass(30);
  SetMaterial("textile");
  SetArmourClass(ARMOUR_CLOTH);
  SetSize(SIZE_MEDIUM);
  SetWarmth(20);
  SetValue(80);
  SetDamagePoints(700);
  SetArmourType(A_HELMET);
}
