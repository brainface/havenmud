#include <lib.h>
#include <damage_types.h>
#include <vendor_types.h>
inherit LIB_ITEM;

static void create() {
   item::create();
   SetKeyName("decorated knife");
   SetShort("a decorated knife");
   SetId( ({ "knife" }) );
   SetAdjectives( ({ "decorated","pierce" }) );
   SetLong("The decorate knife is well-crafted from gleaming metal, "
		"with spiraling designs carefully carved on the metal"
		"hilt.  A soaring design of a pine tree travels up "
		"the flat side of the blade.");
   SetClass(10);
   SetMass(150);
   SetVendorType(VT_WEAPON);
   SetValue(450);
   SetWeaponType("knife");
   SetDamageType(PIERCE|MAGIC);
   SetDamagePoints(650);
   SetMaterial( ({ "metal" }) );
   SetRepairDifficulty(15);
   SetRepairSkills( ([
                       "metal working" : 2,
                       "weapon smithing" : 2,
                  ]) );
   SetProperty("magic","The Goddess Amelia has blessed this knife, "
		"giving it magical damage as well as the regular "
		"pierce of the tip.");
   SetProperty("history","Decorated knives like these are often "
		"carried by the bards of the WestWood.  Rumored to have "
		"been blessed by the Goddess Amelia, they were "
		"marked with natural symbols to remind the bards of "
		"their magical powers, as well as the responsibility "
		"of the owners to do good.");
}
