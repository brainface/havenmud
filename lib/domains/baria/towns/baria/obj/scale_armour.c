// Artanis@Haven (July 18, 2004)

#include <lib.h>
#include <armour_class.h>
#include <armour_types.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <size.h>
inherit LIB_ARMOUR;

int DoWear();

static void create() {
  armour::create();
  SetProperty("laoise_flag", 1);
  SetKeyName("dragon scale armour");
  SetId( ({ "armour", "armor" }) );
  SetAdjectives( ({ "sparkling", "dragon", "scale" }) );
  SetShort("a sparkling suit of dragon scale armour");
  SetLong(
     "This piece of armour looks to have been forged out of mighty dragon scales. "
     "It is rumored the Kysanth many years ago allowed a smith to take a "
     "few of her scales and create a piece of armour. It was entrusted to "
     "the guardian of the jungle to ensure that the peoples of Baria "
     "would be kept safe. "
  );
  SetVendorType(VT_ARMOUR);
  SetArmourType(A_ARMOUR);
  SetArmourClass(ARMOUR_PLATE);
  SetMass(500);
  SetValue(1250);
  SetDamagePoints(3200);
  SetSize(SIZE_MEDIUM);
  SetWear( (: DoWear :) );
  SetMaterial( ({ "natural" }) );
  SetWarmth(1);
  SetRepairSkills( ([
     "natural working" : 20,
  ]) );
  SetRepairDifficulty(40);

  SetDestroyOnSell(1);
}

int DoWear() {
  if ( (this_player()->GetReligion() == "Kuthar") && (this_player()->GetLevel() >= 25) ) {
     send_messages( ({"feel","wear"}), "$agent_name $agent_verb the power of "
                                  "Kysanth as $agent_nominative $agent_verb "
                                  "the armour.", 
                                  this_player(), 0, environment(this_player()) );
     return 1;
     }
     else
     {
     this_player()->eventPrint("You are not worthy of the power of Kysanth.");
     return 0;
     }
}
