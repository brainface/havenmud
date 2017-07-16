#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;

static void create() {
  meal::create();
  SetKeyName("rat on a stick");
  SetId( ({ "rat", "stick", "food" }) );
  SetAdjectives( ({ "rat", "on", "a", "tasty", }) );
  SetShort("a tasty rat on a stick");
  SetLong("Battered by tasty looking, seasoned bread crumbs, the rat "
          "doesn't look so bad.  If only the tail weren't dangling "
          "out the bottom.");
  SetMass(10);
  SetMealType(MEAL_FOOD);
  SetStrength(35);
}

int eventEat(object who) {
  if (who->GetRace() != "dwarf") {
  	send_messages( ({ "bite" }),
  	  "$agent_name $agent_verb into a rat skewered onto a stick.",
      who, this_object(), environment(who) );
    send_messages("look",
  	  "$agent_name $agent_verb %^GREEN%^ill%^RESET%^.",
      who, this_object(), environment(who) );
    send_messages("vomit",  
       "$agent_name%^BOLD%^GREEN%^ $agent_verb%^RESET%^ all over $agent_reflexive!",
       who, this_object(), environment(who) );
  	who->AddFood(-50);
  	who->AddRecoveryTime(5);
  	who->AddStaminaPoints(-50);
  	eventDestruct();
  	return 1;
  }
  send_messages( ({ "bite", "get", }),
    "$agent_name $agent_verb into a tasty looking rat on a stick and $agent_verb "
    "a look of utter contentment on $agent_possessive face.",
    who, this_object(), environment(who) );
    who->AddFood(GetStrength());
    eventDestruct();
    return 1;
}
