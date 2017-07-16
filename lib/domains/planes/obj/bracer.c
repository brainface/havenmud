/* 
about one tick better than snark armlets,
but heavy plate and made of metal.
*/
#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <size.h>
#include <damage_types.h>
inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("bracer");
  SetId( ({ "bracer" }) );
  SetShort("a jeweled bracer");
  SetLong(
    "This bracer is made of several thick interlocking steel plates. Its "
    "gleaming surface is studded with glittering sapphires and emeralds, "
    "and the interior is lined with leather to provide additional padding "
    "against blows."
  );
  SetAdjectives( ({ "jeweled" }) );
  SetArmourClass(ARMOUR_HEAVY_PLATE);
  SetArmourType(A_LONG_GLOVE);
  SetDamagePoints(1000); 
  SetMass(400);
  SetMaterial( ({ "metal" }) );
  SetProperty( "history",
    "This is a type of armour often worn by Maraliths of the lower "
    "and forest planes. Supposedly, such armour was forged in some "
    "fiery furnace, hidden deep within the lower planes."
  );
  SetRepairDifficulty(90);
  SetSize(SIZE_MEDIUM);
  SetValue(8000);

}

