#include <mudlib.h>
#include <race.h>
#include "../rooms.h"
inherit MONSTER;

void reset(int arg) {
  if (!is_clone(this_object())) return;
  ::reset(arg);
  if (arg) return;
  set_name("draconian");
  set_level(14 + random(3));
  enable_player_commands(1);
  set_short("a draconian soldier");
  set_al(-100,random(201)-200);
  add_money(random(150) + 55);
  set_alias("soldier");
  set_race("draconian");
  set_switch_chance(30);
  set_random_pick(30);
  set_long("\
This is a Draconian soldier from the village of Thrax near the \n\
Tower of Rath-Khan.  His unnerving grin sends a chill down your \n\
spine.\n");
  load_cmd(2, ({
    "rsay I hate this town",
    "grumble",
    "snarl $N",
    "rsay Dwarves are so stupid!",
    "rsay I hate elves!",
    "rsay Orcs smell bad!", 
    "rsay Humans are weak!", }));
  set_gender(1);
  add_clone(ARMR + "/dr_arm");
  command("wear mail");
  add_clone(WPNS + "/draco_sword");
  command("wield scimitar");
  replace_program(MONSTER);
}
