/* jewelled armlet
   Ela 12/6/98
*/

#include <lib.h>
#include <armour_types.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <size.h>
#include <armour_class.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("armlet");
  SetId( ({ "armlet" }) );
  SetAdjectives( ({ "amber" }) );
  SetShort("an amber armlet");
  SetLong("This intricately designed armlet glitters "
          "with bright flashes of inner light. Amber beads "
          "in muted golden tones glow warmly.");
  SetMass(80);
  SetSize(SIZE_MEDIUM);
  SetValue(3000);
  SetArmourClass(ARMOUR_PLATE);
  SetProperty("laoise_flag", 1);
  SetDamagePoints(200);
  // SetProtection(MAGIC, 10);
  // SetProtection(SLASH, 4);
  // SetProtection(BLUNT, 5);
  // SetProtection(PIERCE, 6);
  SetArmourType(A_LONG_GLOVE);
  SetVendorType(VT_TREASURE|VT_GEM|VT_ARMOUR);
  SetMaterial( ({"natural"}) );
  SetWarmth(3);
  SetProperties( ([
                 "magic" : "The armlet is illuminated "
                          "by an inner magical brilliance.",
               ]) );
}
