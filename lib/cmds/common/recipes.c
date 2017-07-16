#include <lib.h>
#include <daemons.h>
inherit LIB_DAEMON;

mixed cmd(string args) {
	object who    = this_player();
	object target = 0;
	mapping allrecipes;
	
	if (creatorp(who)) 
		if (args) target = find_player(args);
	
	if (playerp(who)) target = who;
	
	if (!target) {
		who->eventPrint("Full Crafting Recipe List");
		allrecipes = RECIPES_D->GetRecipeFiles();
		foreach(string recipe in keys(allrecipes)) {
			message("system", sprintf("%-30s %-30s", recipe, allrecipes[recipe]), who);
		}
		return 1;
	}
	who->eventPrint("Crafting Recipe List for " + target->GetCapName());
	who->eventPrint(implode(target->GetCraftingRecipes(), ", "));
	return 1;
}

string GetHelp(string h) {
	return "Syntax:  recipes\n\n"
	       "Use this command to display a list of crafting recipes known.";
}	       