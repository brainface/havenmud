/*  A simple location spell */
#include <lib.h>
#include <domains.h>
#define DESERT  YOZRATH_VIRTUAL "desert/"
#include <magic.h>
inherit LIB_SPELL;

static void create() {
  ::create();
  SetSpell("desert divining");
  SetReligions("Kylin");
  SetRules("");
  SetSpellType(SPELL_OTHER);
  SetSkills( ([
     "faith"       : 1,
     "evokation" : 1,
    ]) );
  SetDifficulty(5);
  SetMagicCost(10, 5);
  SetHelp(
          "This spell will assist the desert traveller by pointing "
          "out the direction to the Oasis at Yozrath from anywhere in the desert."
          );
 }

varargs int eventCast(object who, int level, mixed q, object *t) {
  int x, y;
  string loc = base_name(environment(who));
  string *nums = ({ });
  if (strsrch(loc, "/domains/yozrath/towns/yozrath") != -1) {
    message("system", "You are in Yozrath City!", who);
    return 1;
    }
  if (strsrch(loc, DESERT) == -1) {
     message("system", "But you are not in the desert!", who);
     return 0;
    }
  loc = loc[strlen(DESERT)..strlen(loc)-1];
  nums = explode(loc, ",");
  x = to_int(nums[0]);
  y = to_int(nums[1]);
  if (y < 0) loc = "south";
  if (y > 0) loc = "north";
  if (y == 0) loc = "";
  if (x < 0) loc += "west";
  if (x > 0) loc += "east";
  if (x == 0 && y == 0) {
    message("system", "You are at the center of the Yozrath Desert!",
            who);
    return 1;
  }
  message("system",
   "You are " + loc + " of the Oasis at Yozrath.", who);
  return 1;
  }

