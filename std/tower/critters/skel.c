#include <mudlib.h>
#include <race.h>
#include "../rooms.h"
inherit MONSTER;

void reset(int arg) {
  if (!is_clone(this_object())) return;
  ::reset(arg);
  if (arg) return;
  set_name("skeleton");
  set_level(15);
  set_alias("skeleton");
  set_short("a skeleton");
  set_long("\
  This is one of Rath-Khan's followers from long ago.\n\
  His bones are rotted and he seems ready to collapse.\n");
  set_race("undead");
  set_aggressive(5);
  set_gender(1);
  set_al(-50,-30);
  make_object("sword", KAHN + "/weapons/shortsw",1);
  command("wield sword");
  add_money(random(200)+50);
  replace_program(MONSTER);
}

