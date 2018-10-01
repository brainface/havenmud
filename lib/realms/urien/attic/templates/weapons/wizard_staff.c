// Urien at some time
#include <lib.h>
#include <vendor_types.h>
#include <damage_types.h>
inherit LIB_ITEM;


static void create() {
  ::create();
  SetId( ({"staff"}) );
  SetAdjectives( ({ "magical","wooden" }) );
  SetShort("a magical wooden staff");
  SetLong(
        "This staff appears to be very simplistic. It is roughly "
        "the size of an adult human in height and has previously been "
        "carved from pure wood. One end of the staff is circular "
        "and clean cut, while the other end has been crafted in the "
        "shape of a solid ball. The shaft is very simple "
        "and maintains its linear shape. It radiates in a low "
        "magical energy."
  );
  SetClass(15); //Dont know how we're going to change this with spells
  SetDamagePoints(1000);
  SetValue(2); // lame bonus for sell
  SetWeaponType("pole"); // pole focused
  SetDamageType(BLUNT|MAGIC);
  SetKeyName("staff");
  SetMass(20); // more than a potion less than a real wep
  SetMaterial( ({ "wood" }) );
  SetVendorType(VT_WEAPON);
  SetHands(2);
  SetRepairDifficulty(5);
  SetProperty("history",
  "This wooden staff was created by fledgeling mage, one who is "
  "probably starting the ways of magic."
   );
  SetProperty("magic",
  "Waning softly this staff echos in creation. It was created "
  "by an acolyte out of pure magic power. "
   );
}
