#include <mudlib.h>
#include "../rooms.h"
#include <race.h>
inherit MONSTER;

void reset(int arg) {
  if (!is_clone(this_object())) return;
  ::reset(arg);
  if (arg) return;
  set_name("guard");
  set_race("undead");
  set_short("a guard");
  set_long("\
This is one of the guards that stands watch over the Diplomats.\n");
  set_gender(1);
  set_al(-200,200);
  set_level(40);
  add_money(900);
  add_clone(WPNS+"/longsword",1);
  add_clone(WPNS+"/shortsw",1);
  add_clone(ARMR+"/chain",1);
  command("wield longsword");
  command("wield short");
  command("wear chain");
  replace_program(MONSTER);
}
