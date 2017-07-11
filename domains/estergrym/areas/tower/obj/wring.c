#include <lib.h>
#include <damage_types.h>
#include <armour_class.h>
#include <size.h>
#include <armour_types.h>
#include <vendor_types.h>

inherit LIB_ARMOUR;

static void create()
{
  ::create();
  SetKeyName("wooden ring");
  SetId(( { "ring","wooden ring"} ));
  SetShort("a wooden ring");
  SetLong("Its round shape is composed of polished wood. Its appearance "
          "looks as though is was carved by an amateur. Its round by ring "
          "standards but has an octagon shape on the outside.");
  SetMass(1);
  SetValue(400);
  SetDamagePoints(750);
  SetArmourClass(ARMOUR_NATURAL);
  SetSize(SIZE_LARGE);
    
  SetArmourType(A_RING);
  SetVendorType(VT_TREASURE | VT_ARMOUR);
  
  SetWear("The wooden ring slips on your finger.");
}
