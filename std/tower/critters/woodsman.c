#include <mudlib.h>
#include "../rooms.h"
#include <race.h>
inherit MONSTER;

void reset(int arg) {
  if (!is_clone(this_object())) return;
  ::reset(arg);
  if (arg) return;
  set_name("woodsman");
  set_race("human");
  set_gender(1);
  set_level(18);
  set_con(14);
  set_short("a middle aged man");
  set_alias("man");
  set_long("\
The woodsman is an older gentleman that looks kindly\n\
upon wayfarers in his home.\n");
  set_al(200,50);
  add_money(100+random(100));
  add_clone(WPNS+"/axe");
  command("wield axe");
  replace_program(MONSTER);
}
