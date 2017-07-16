#include <lib.h>
#include <magic.h>
#include <daemons.h>
#define SPACE "/domains/innersea/virtual/ocean/"
inherit LIB_SPELL;

static void create() {
  ::create();
  SetSpell("marine beacon");
  SetRules("");
  SetSkills( ([
    "faith"      : 1,
    "navigation" : 1,
    ]) );
  SetMagicCost(50, 50);
  SetReligions("Damhair");
  SetSpellType(SPELL_OTHER);
  SetHelp(
    "Use of this spell by the Damhair cleric allows a more accurate and less "
    "random reading of current location on the ocean."
    );
  SetDifficulty(40);
}
int CanCast(object who, int level, mixed *b, object *t) {
  object env = environment(who);
  if (!vehiclep(env)) {
	  who->eventPrint("You must be on a ship to use this magic.");
	  return 0;
	}
	return ::CanCast(who, level, b, t);
}

int eventCast(object who, int level, mixed *b, object *t) {
	object env = environment(environment(who));
	int x, y, *z;
	int success;
	object *ob;
	string xPos = "", yPos = "", str = "";
	string what = who->GetProperty("homedock");
	if (!what) {
	  who->SetPermanentProperty("homedock", "parva");
	  what = "parva";
	}
	if (!env) {
		who->eventPrint("This would be the least of your worries.");
	  return 1;
	}
	if (sscanf(base_name(env), SPACE "%d,%d", x, y) != 2) {
		who->eventPrint("You are unable to determine your location from this point.");
		return 1;
	}
  z = SAILING_D->GetCoordinates(SAILING_D->GetTownDock(what));
  if (!sizeof(z)) debug("Bad what of " + what);
  x = x - z[0]; y = y - z[1];
  if (x > 0) xPos = "east"; else xPos = "west";
  if (y > 0) yPos = "north"; else yPos = "south";
  str = "Our position is";
  if (x != 0) str += (" " + absolute_value(x) + " leagues " + xPos + " of " + capitalize(what));
  if (y != 0) str += (" " + absolute_value(y) + " leagues " + yPos + " of " + capitalize(what));
  who->eventPrint(str + ".");
  return 1;
}
  