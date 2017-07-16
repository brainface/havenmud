#include <lib.h>
#include <vendor_types.h>
#include <size.h>
#include <armour_class.h>
#include <armour_types.h>
#include <damage_types.h>

inherit LIB_ARMOUR;

static void create() {
  armour::create();
  SetKeyName("glove");
  SetId(( {"glove" } ));
  SetShort("a mithril chainmail glove");
  SetAdjectives( ({"mithril"}) );
  SetLong(
    "This chainmail glove is completely made of mithril. It offers a very large "
    "amount of protection to the wearer's hand, while allowing a tremendous "
    "range of motion for each finger. The glove is lined with soft cotton material, providing "
    "a decent amount of warmth." );     
  SetMass(35);
  SetArmourClass(ARMOUR_CHAIN);
  SetSize(SIZE_LARGE);
  SetMaterial("mithril");
  SetWarmth(2);
  SetRepairDifficulty(70);
  SetValue(7500);
  SetDamagePoints(1800);
  SetProtectionBonus(MAGIC, 2);
  SetProperty("magic", "Once these gloves were completely forged in the dwarf "
                       "mines they were placed with the chainmail armour they "
                       "were forged with. Word has it that they were all stolen "
                       "and delivered to an Aberach priest. Once he gained "
                       "possession of the items he cast a spell upon them to "
                       "protect the wearer of magical damage. It was said that "
                       "he left it to his eventual heir to help protect his kin. ");
  SetArmourType(A_GLOVE);  
  SetVendorType(VT_ARMOUR);
}

