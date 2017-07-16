/*                                                                   */
//
// Creator: Angel Cazares - Rhakz
// Date: 09/18/98
// File Name: pillar.c
// Area: the dark pyramid
//

#include <lib.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
  item::create();
  SetKeyName("pillar of light");
  SetDamagePoints(100);
  SetShort("%^BLUE%^a pillar of dark blue light%^RESET%^");
  SetLong("This is a pillar of blue light that comes out of the "
          "tile located at the center of this place. It goes "
          "from the ground to the darkness above."
         );
  SetId( ({ "pillar" }) );
  SetAdjectives( ({"of blue light","of dark blue light","of light"}) );
  SetValue(1);
  SetMass(20);
  SetVendorType(VT_TREASURE);
  SetPreventGet("You cannot get that!");
}

