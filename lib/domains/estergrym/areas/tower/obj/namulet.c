#include <lib.h>
#include <armour_types.h>
#include <size.h>
#include <damage_types.h>
#include <armour_class.h>
#include <vendor_types.h>
inherit LIB_ARMOUR;

static void create() {
   ::create();
   SetKeyName("amulet");
   SetShort("a dark black diamond amulet");
   SetId( ({ "amulet" }) );
   SetAdjectives( ({ "dark","black","diamond" }) );
   SetLong("The jewel at the end of the white gold chain is a large ruby "
           "in the shape of a diamond. The ruby is encased in a white gold "
           "bracer which holds it in place with human incisor teeth. "
           "Inside the ruby is an eyeball which turns and watches the "
           "environment.");
   SetMass(25);
   SetValue(600);
   SetVendorType(VT_ARMOUR);
   SetSize(SIZE_MEDIUM);
   SetArmourType(A_AMULET);
   SetArmourClass(ARMOUR_CHAIN);
   SetDamagePoints(3000);
   SetProtectionBonus(HUNGER, 5);
   SetRadiantLight(-20);
   SetProperty("history",
    "Forged from the lower planes and brought into the world of "
    "Kailie, this amulet was used as a tool to collect souls "
    "from travellers. Although the skill through mortals to "
    "enhance this power is lost, the physical protection "
    "remains."
   );
   SetProperty("magic",                                             
    "Crafted from the victims of evil magic, this amulet "
    "releases darkness into the world clouding judgement "
    "to those who would wear it. Due to the small collection "
    "of souls trapped inside it ebbs in physical resilience. "
   );                                                               
  SetRepairDifficulty(90);                                         
}