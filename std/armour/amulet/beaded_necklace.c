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
  SetKeyName("necklace");
  SetId(( { "necklace","amulet","bead","beads"} ));
  SetAdjectives( ({ "beaded","glass","tiny" }) );
  SetShort("a beaded necklace");
  SetLong("Tiny glass beads are strung on a thin strip of leather to make "
          "this necklace.");
  SetMass(5);
  SetValue(10);
  SetSize(SIZE_MEDIUM);
  SetDamagePoints(100);
 
  SetArmourClass(ARMOUR_CLOTH);
  SetArmourType(A_AMULET);
  SetVendorType(VT_TREASURE | VT_ARMOUR);
 
  SetWear("The beads rattle a bit when you put them around your neck.");

  SetMaterial( ({ "leather","natural" }) );
  SetRepairDifficulty(7);
  SetRepairSkills( ([
                      "leather working" : 1,
                      "natural working" : 2,
                 ]) );
}
