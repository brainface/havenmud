
#include <lib.h>
#include <armour_types.h>
#include <armour_class.h>
#include <damage_types.h>
#include <vendor_types.h>
#include <size.h>
inherit LIB_ARMOUR;

int DoWear();

static void create() {
  ::create();
  SetKeyName("horseshoe");
  SetArmourType(A_SOCK);
  SetShort("a daemon bone horseshoe");
  SetLong("This is a bone horseshoe made"
          " for a daemon hoof.");
  SetValue(0);
  SetMass(30);
  SetWarmth(0);
  SetSize(SIZE_LARGE);
  SetDamagePoints(750);
  SetId( ({ "horseshoe", "horse shoe", "shoe" }) );
  SetAdjectives( ({ "daemonic", "daemon", "bone" }) );
  SetMaterials( ({ "natural" }) );
  SetRepairDifficulty(40);
  SetArmourClass(ARMOUR_NATURAL);
  SetWear( (: DoWear :) );
 }


int DoWear() {
   if ( this_player()->GetRace() == "daemon" ) {
     send_messages( ({ "wear" }),
      "$agent_name $agent_verb $target_name.",
       this_player(), this_object(), environment(this_player()) );

      return 1;
    }
    message("nowear", "You have no hooves.", environment());
     return 0;
}
