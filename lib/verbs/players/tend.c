#include <lib.h>
inherit LIB_VERB;
mixed can_tend_str_on_liv(string);
mixed do_tend_str_on_liv(string, object);
int eventTend(object, object);

static void create() {
  ::create();
  SetVerb("tend");
  SetRules("STR on LIV");
  SetErrorMessage("Tend wounds on whom?");
  SetHelp("Syntax:   tend STR on LIV  \n\n\n"
          "Specifically, tend wounds on LIV. \n"
          "Use of this action is a first-aid to assist with basics.");
}

mixed can_tend() {
	return can_tend_str_on_liv("");
}

mixed can_tend_str_on_liv(string what) {
	object who = this_player();
	if (what != "wounds") {
		return "Tend wounds?";
	}
	
	if (who->GetSleeping()) { 
		return "You dream about helping.";
	}
	if (who->GetParalyzed()) {
		return "You are unable to move.";
	}
	if (who->GetStaminaPoints() < 20) {
		return "You are too tired.";
	}
	if (who->GetInCombat()) {
		return "You're a bit busy.";
	}
	return 1;
}

mixed do_tend_str_on_liv(string what, object tendee) {	
	return eventTend(this_player(), tendee);
}

int eventTend(object who, object target) {
	who->eventMoralAct(query_sign(target->GetMorality()));
	return who->eventTend(who, target);
}
