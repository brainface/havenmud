/* A shozoku (cloth armour */
#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <size.h>
#include <damage_types.h>
inherit LIB_ARMOUR;

static void create() {
  ::create();
  SetKeyName("shinobi shozoku");
  SetShort("a suit of black cloth armour");
  SetId( ({ "shozoku", "armour", "suit" }) );
  SetAdjectives( ({ "shinobi", "black", "cloth", "suit of" }) );
  SetLong("This black cloth is hardened to protect the wearer "
          "as much as cloth armour can be expected to. Its ability "
          "to hide the trained wearer from prying eyes make this "
           "armour prized among ninja.");
  SetArmourType(A_BODY_ARMOUR);
  SetMass(120);
  SetArmourClass(ARMOUR_CLOTH);
  SetSize(SIZE_MEDIUM);
  SetValue(500);
  // SetProtection(SLASH, 5);
  SetDamagePoints(2500);
  // SetProtection(PIERCE, 5);
  // SetProtection(BLUNT, 2);
  SetMaterial( ({ "textile" }) );
   SetWarmth(30);
}
