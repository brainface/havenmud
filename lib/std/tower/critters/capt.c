#include <mudlib.h>
#include <types.h>
#include <race.h>
#include "../rooms.h"
inherit MONSTER;

void reset(int arg) {
  if (!is_clone(this_object())) return;
  ::reset(arg);
  if (arg) return;
  set_name("captain");
  set_level(70);
  set_race("undead");
  set_short("the captain of the guard");
  set_alias("guard");
  set_long("\
This is the Captain of Rath Khan's guards. He is a \n\
truly evil being that stands nearly eight feet tall.\n");
  set_gender(1);
  set_al(-1250,1250);
  add_money(random(200)+200);
  add_clone(ARMR+"/chain");
  add_resistance(WEAPON_DAM_MASK);
  command("wield sword");
  command("wear chain");
  load_a_chat(3, ({
    "The Guard Captain says 'Little wyrm, I will crush you!\n",
    "The Captain signals for reinforcements.\n" }));

  add_attack(4,80,30,30,DAM_FIRE|DAM_CHAOS|WEAPON_SLASH,WEAPON_SLASH);

  replace_program(MONSTER);
}
