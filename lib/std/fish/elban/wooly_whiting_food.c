#include <lib.h>
#include <meal_types.h>

inherit LIB_MEAL;

int eventEndWoolyWhiting(object);

static void create() {
    meal::create();
    SetKeyName("wooly whiting");
    SetId( ({ "whiting" }) );
    SetAdjectives( ({ "wooly" }) );
    SetShort("a wooly whiting");
    SetLong(
      "This whiting's opalescent scales are oddly lumpy, giving it a woolen "
      "appearance. Mostly gristle, sailors still prize this fish for its "
      "supposed invigorating properties."
    );
    SetMass(FISH_SIZE_SMALL);
    SetMealType(MEAL_FOOD);
    SetStrength(FISH_FOOD_SMALL);
    SetPortions(1);
    SetValue(100);
    SetMealMessages("More than usually stringy.",
      "$N gnaws with difficulty on a wooly whiting.");
    SetProperty("history","Caught off Elban Isle, south of Haventown");
    SetProperty("magic","Magically corrupted, consuming this fish yields a "
      "temporary improvement in durability.");
}

mixed eventEat(object who) {
  int duration=600;
  int amount=10;
  if(who->GetProperty("wooly_whiting")) {
    who->eventPrint("That other whiting is still rolling around in your belly.");   
  } else {
    who->eventPrint("%^BOLD%^GREEN%^You feel tougher!%^RESET%^");
    who->SetProperty("wooly_whiting",1);
    who->AddStatBonus("durability", amount, duration);
    call_out( (: eventEndWoolyWhiting, who :), duration );
  }
  return meal::eventEat(who);
}

int eventEndWoolyWhiting(object who) {

  if (!who) return 1;
  who->RemoveProperty("wooly_whiting");
  who->RemoveStatBonus("durability");
  who->eventPrint("%^RED%^Your toughness passes.%^RESET%^");
  return 1;
}
