#include <mudlib.h>
#include <types.h>
#include "../rooms.h"
inherit MONSTER;

void reset(int arg) {
  if (!is_clone(this_object())) return;
  ::reset(arg);
  if (arg) return;
  set_name("shaman");
  set_level(random(6)+10);
  set_alias("draconian");
  set_short("a draconian shaman");
  set_race("draconian");
  enable_player_commands(1);
  set_gender(random(2)+1);
  set_long("\
This is a shaman of the Draconians.  The shaman's powers are \n\
steeped in mystery and the power of the dragon that it serves.\n");
  add_money(random(75)+20);
  add_clone(TRSR+"/diamond");
  load_cmd(2, ({
    "snarl",
    "swear",
    "threaten $N" }));
  set_al(-200,-100);
  set_chance(15);
  set_spell_mess1("The shaman summons a hideous cloud!");
  set_spell_mess2("The shaman sends a billowing cloud at you!");
  set_spell_dam(30 + random(10));
  set_spell_type(DAM_POISON);
  set_friends("draconian");
  set_switch_chance(30);
  replace_program(MONSTER);
}
