#include <lib.h>
#include <vendor_types.h>
#include <size.h>
#include <armour_class.h>
#include <armour_types.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("helm");
  SetId(( {"helm" } ));
  SetShort("a mithril platemail helm");
  SetAdjectives( ({"mithril", "chainmail"}) );
  SetLong(
    "This platemail helm is made of the finest mithril plating. "
    "The face is almost completely closed except for slits designed "
    "to give the wearer a wide field of vision while still protecting "
    "as much of the face as possible."
  );     
  SetMass(75);
  SetVendorType(VT_ARMOUR);
  SetArmourClass(ARMOUR_CHAIN);
  SetSize(SIZE_SMALL);
  SetMaterial("mithril");
  SetWarmth(0);
  SetRepairDifficulty(100);
  SetValue(4500);
  SetDamagePoints(35000);
  SetArmourType(A_HELMET);  
  SetWear("The chainmail helm feels very comfortable.");
}
