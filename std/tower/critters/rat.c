#include <mudlib.h>
#include <race.h>
inherit MONSTER;

void reset(int arg) {
  if (!is_clone(this_object())) return;
  ::reset(arg);
  if (arg) return;
  set_name("rat");
  set_short("a rat");
  set_alias("mouse");
  set_race("rodent");
  set_level(3);
  set_aggressive(10);
  set_wander(20,20);
  load_chat(2, ({
    "The rat scurries about the room.\n",
    "The rat nibbles some old junk.\n" }) );
  set_long("A plain, dirty, nasty crawling rat. \n");
  replace_program(MONSTER);
}
