#include <lib.h>
#include <std.h>
#include <meal_types.h>
#include <vendor_types.h>

inherit LIB_MEAL;

static void create() {
::create();
  SetKeyName("elixir");
SetShort("a bottle of elixir");
SetLong("This bottle has filled with an elixir"
        " specifically formulated to cure one of"
        " the horrible disease known as pestilentia."
        " It is a small glass bottle with a cork stopper.");
SetId("bottle", "elixir");
SetAdjectives( ({ "bottle of" }) );
SetMass(5);
SetValue(5000);
SetVendorType(VT_MAGIC|VT_TREASURE);
SetMaterial( ({ "natural" }) );
SetMealType(MEAL_DRINK);
SetStrength(30);
SetDamagePoints(15);
  SetRepairDifficulty(35);
  SetRepairSkills( ([
                    "natural working" : 3,
                  ]) );
}

mixed eventDrink(object who) {
object *pestilence;
pestilence = filter(all_inventory(this_player()), (: $1->GetProperty("pestilentia") :) );
  
  send_messages("shiver", "$agent_name $agent_verb as you drink the elixir.",
                who, 0, environment(who));
  if (!sizeof(pestilence)) {
  who->eventPrint("Nothing seems to happen.");
  return (meal::eventDrink(who));
  }
  pestilence[0]->eventDestruct();
  who->eventPrint("The boils on your body disappear and you feel much"
                  " better.");
  return (meal::eventDrink(who));
}
