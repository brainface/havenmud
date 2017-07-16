//
// Dalnainr Total Recode
// Torak@Haven 2014-2017
// Kobold Tentacle Outfit
//

#include <lib.h>
#include <armour_types.h>
#include <size.h>

#include <armour_class.h>
#include <damage_types.h>
inherit LIB_ARMOUR;

static void create() {
  ::create();
  SetKeyName("outfit");
  SetShort("a floppy tentacle outfit");
  SetId( ({ "outfit", "tentacle" }) );
  SetAdjectives( ({ "tentacle", "floppy" }) );
  SetLong(
  "This is a small floppy tentacle outfit. "  
  "Made from a paper mache of sticks, sinew and hide, "
  "this outfit is painted with a purple top blending "
  "into a light pink underbelly speckled with yellow "
  "dots. "
  );
  SetArmourType(A_BODY_ARMOUR);
  SetMass(175);
  SetSize(SIZE_SMALL);
  SetValue(300);
  SetArmourClass(ARMOUR_NATURAL);
  SetDamagePoints(3000);
  SetMaterial( ({ "natural" }) );
  SetWarmth(10);
}
