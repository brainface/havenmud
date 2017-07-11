#include <mudlib.h>
#include <race.h>
#include <types.h>
#include "../rooms.h"
inherit MONSTER;

void reset(int arg) {
  if (!is_clone(this_object())) return;
  ::reset(arg);
  if (arg) return;
  set_name("elite guard");
  set_level(42);
  set_alias("guard");
  set_alt_name("skeleton");
  set_short("an elite guard");
  set_long("\
This is one of the elite skeletal guards of Rath Khan.\n\
The stench coming off the guard is of 1000 years of rot.\n");
  add_weakness(DAM_GOOD|DAM_SILVER);
  set_al(-400,400);
  set_aggressive(0);
  set_race("undead");
  set_gender(random(2)+1);
  add_clone(WPNS + "/longsword", 1);
  add_clone(TRSR + "/gem", 1);
  add_clone(ARMR + "/chain", 1);
  command("wield sword");
  command("wear mail");
  add_money(500 + random(500));
  replace_program(MONSTER);
}
