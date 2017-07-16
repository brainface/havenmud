#include <mudlib.h>
#include <race.h>
inherit MONSTER;

void reset(int arg) {
  if (!is_clone(this_object())) return;
  ::reset(arg);
  if (arg) return;
  set_name("dwarf");
  set_level(random(4)+1);
  set_al(random(200),-random(200));
  set_random_pick(33);
  set_race("dwarf");
  set_whimpy();
  set_wander(20,20);
  set_move_at_reset();
  set_short("a gully dwarf");
  set_alias("gully");
  set_alt_name("gdwarf");
  enable_player_commands(1);
  set_str(4);
  add_money(random(20));
  set_gender(random(2)+1);
  set_long("\
This is a gully dwarf, a slave to the draconians.\n");
  load_cmd(2, ({
    "hide",
    "rsay One and one and one and one, two!",
    "cry",
    "whine",
    "beg $N",
    "whimper",
    "fkiss $N",
    "worship $N",
    "grovel $N",
    "rsay I hate the draconians!",
    "rsay We love the draconians!",
    "rsay This way to the High Bulp!" }));
  replace_program(MONSTER);
}
