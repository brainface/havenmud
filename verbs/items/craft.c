#include <lib.h>
#include <daemons.h>
inherit LIB_VERB;

static void create() {
	::create();
	SetVerb("craft");
	SetRules("STR");
	SetErrorMessage("Craft what?");
	SetHelp("Syntax:  craft <thing>\n"
	        "Use this in combination with the \"recipes\" command to craft things."
	        );
}

mixed can_craft_str() {
	 if (this_player()->GetSleeping()  ) return "You cannot do that while sleeping!";
   if (this_player()->GetParalyzed() ) return "You cannot do anything.";
   return 1;
}

int do_craft_str(string what) {
	string recipefile;
	object recipe;
	object who = this_player();
	
	recipefile = RECIPES_D->GetRecipeFile(what);
	if (!recipefile) {
		who->eventPrint("Craft what? (Check your recipes!)");
		return 1;
	}
	recipe = load_object(recipefile);
	if (recipe->CanCraft(who)) { recipe->eventCraft(who); }
	return 1;
}