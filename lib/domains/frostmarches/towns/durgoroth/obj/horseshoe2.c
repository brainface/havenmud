
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
  SetKeyName("horshoe");
  SetArmourType(A_SOCK);
  SetShort("a daemon horseshoe");
  SetLong("This is a steel horseshoe made"
          " for a daemon hoof.");
  SetValue(500);
  SetMass(30);
  SetWarmth(0);
  SetSize(SIZE_LARGE);
  SetDamagePoints(2000);
  SetId( ({ "horseshoe", "horse shoe", "shoe" }) );
  SetAdjectives( ({ "daemonic", "daemon" }) );
  SetMaterials( ({ "metal" }) );
  SetRepairDifficulty(40);
  SetArmourClass(ARMOUR_PLATE);
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

