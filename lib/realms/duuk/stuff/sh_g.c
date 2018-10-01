/* A shozoku (cloth armour */
#include <lib.h>
#include <size.h>
#include <armour_types.h>
#include <damage_types.h>
#include <armour_class.h>
inherit LIB_ARMOUR;

static void create() {
  ::create();
  SetKeyName("shinobi shozoku");
  SetShort("a small suit of black cloth armour");
  SetId( ({ "shozoku", "armour", "suit" }) );
  SetAdjectives( ({ "shinobi", "black", "cloth", "small", "suit", "of" }) );
  SetLong("This black cloth is hardened to protect the wearer "
          "as much as cloth armour can be expected to. Its ability "
          "to hide the trained wearer from prying eyes make this "
           "armour prized among ninja.");
  SetArmourType(A_BODY_ARMOUR);
  SetSize(SIZE_SMALL);
  SetMass(120);
  SetValue(500);
  SetDamagePoints(2500);
  SetArmourClass(ARMOUR_LEATHER);
  SetMaterial( ({ "textile" }) );
   SetWarmth(30);
}
