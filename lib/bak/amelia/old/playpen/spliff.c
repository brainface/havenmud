// Severen's Joint (w/help from Amelia :)
#include <lib.h>
#include <meal_types.h>
inherit LIB_MEAL;
inherit LIB_SMELL;
inherit LIB_TOUCH;

static void create() {
    meal::create();
    smell::create();
    SetKeyName("spliff");
    SetId( ({ "joint" }) );
    SetAdjectives( ({ "tightly","rolled" }) );
    SetShort("a tightly rolled spliff");
    SetLong("Wrapped in a thin sheet of papyrus is a green "
      "and purplish herb with red hairs all over it.");
    SetMass(2);
    SetMealType(MEAL_FOOD);
    SetStrength(1);
    SetMealMessages("You puff on a tightly rolled spliff.",
      "$N takes a puff from a spliff and looks "
      "more relaxed.");
    SetSmell("The peculiar aroma of the herb mesmerizes the nose.");
    SetTouch("It feels fresh.");
}


void init() {
    ::init();
    add_action("smoke", "smoke");
}

int smoke(string args) {
    if(args != "spliff") {
	return 0;
    }
    if(!creatorp(this_player())) {
	message("my_action","This is the pot for immortals, not for "
	  "mere beings like you, that live and die!",this_player());
	return 1;
    }
    message("my_action","You take a toke from a tightly rolled spliff.\n"
      "Smoke curls into the air from the spliff.\n"
      "You exhale and feel totally relaxed.",
      this_player());
    message("other_action",this_player()->GetName() + " takes a toke "
      "from a tightly rolled spliff.\n"
      "Smoke drifts lazily from the spliff.\n"
      + capitalize(nominative(this_player())) + " looks completely relaxed now.",
      environment(this_player()),
      this_player());
    return 1;
}

mixed direct_smell_obj() {
    return smell::direct_smell_obj();
}
