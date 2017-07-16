#include <lib.h>
#include <armour_types.h>
#include <size.h>
#include <armour_class.h>
#include <damage_types.h>
#include <vendor_types.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("armour");
  SetId( ({"chainmail", "suit"}) );
  SetAdjectives( ({"mithril", "chain", "mail"}) );
  SetShort("a suit of mithril chainmail armour");
  SetLong("The beautiful hand crafted chainmail suit covers nearly the "
          "entire body. Each link looks to be made with such care that "
          "it makes it hard to imagine wearing it in combat. The inner lining "
          "of this mail is made of a very soft silk and is filled with a fair "
          "amount of cotton. These two materials are a perfect combination of "
          "comfort and warmth. This chainmail armour looks to have been forged "
          "by the best of the best. ");
  SetMass(1200);
  SetMaterial( ({ "mithril", }) );
  SetRepairDifficulty(90);
  SetArmourClass(ARMOUR_CHAIN);
  SetWarmth(8);
  SetSize(SIZE_LARGE);
  SetValue(10000);
  SetDamagePoints(5000);
  SetProtectionBonus(MAGIC, 25);
  SetProperty("magic", "Once this armour was completely forged in the dwarf "
                       "mines it was secured by the mightiest priest of Aberach "
                       "in a very uncertain way. Once he gained possession of the "
                       "item he cast a spell upon it to protect the wearer of magical "
                       "damage. It was said that he left it to his eventual heir to "
                       "help protect his kin. ");
  SetArmourType(A_BODY_ARMOUR);
  SetVendorType(VT_ARMOUR); 
}

