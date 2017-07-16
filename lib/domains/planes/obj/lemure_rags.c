/*
 *  filthy rags, for lemures
 */
#include <lib.h>
#include <damage_types.h>
#include <armour_types.h>
#include <armour_class.h>
#include <size.h>
#include <std.h>
#include <vendor_types.h>

#include "../planes.h"

inherit LIB_ARMOUR;

int infectWearer();
 
static void create()
{
  armour::create();
  SetKeyName("filthy rags");
  SetId( ({ "rag", "rags", "set" }) );
  SetAdjectives( ({ "filthy", "set", "of" }) );
  SetShort("a set of filthy rags");
  SetLong(
    "This appears to have once been a suit of formal clothing, as a"
    " nobleman or prosperous merchant might have worn. However, now"
    " a thick patina of blood and grime cover what part of the rags"
    " aren't worn threadbare."
  );
  SetMass(50);
  SetMaterial( ({ "textile" }) );
  SetRepairDifficulty(15);
  SetWarmth(25);
  SetValue(10);
  SetDamagePoints(200);
  SetArmourClass(ARMOUR_CLOTH);
  SetSize(SIZE_MEDIUM);
  SetArmourType(A_BODY_ARMOUR);
  SetVendorType(VT_TREASURE | VT_ARMOUR);
  SetWear(
    (: infectWearer :)
  );
  SetProperty(
    "history",
    "This set of clothing was taken from a lemure, a vile demonic spirit "
    "cursed to wander the lower planes."
 );
 SetProperty(
    "magic",
    "The rags seem to be infected with a disease. "
  );
}

/*
 * Infects wearer with a disease
 */
int infectWearer() {
  write(
    "The stench of dried blood fills your nostrils as you wear the filthy rags."
  );
  // Do not infect lemures (prevents npcs from being plaguebearers)
  if( (string)this_player()->GetRace() != "lemure" ) {
    if ( random(100) > random(this_player()->GetStatLevel("durability")) ) {
      new(STD_GERMS "wither")->eventInfect(this_player());
    }
  }
  return 1;
}

