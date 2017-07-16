#include <mudlib.h>
#include <types.h>
#include <race.h>
#include "../rooms.h"
inherit MONSTER;

void reset(int arg) {
  if (!is_clone(this_object())) return;
  ::reset(arg);
  if (arg) return;
  set_name("diplomat");
  set_level(40);
  set_str(25);
  set_con(38);
  set_race("undead");
  set_alias("ambassador");
  set_short("a distinguished guest");
  set_alt_name("guest");
  set_long("\
This person was an ambassador to Rath-Khan's\n\
court long ago.\n");
  set_al(400,400);
  add_money(1250);
  add_clone(ARMR+"/vip_ring",random(2));
  load_chat(1,({
    "The diplomat chats about nothing.\n",
    "The ambassador talks uselessly.\n"}));
  set_gender(random(2)+1);
  add_clone(ARMR+"/dip_robe");
  command("wear ring");
  command("wear robe");
  add_clone(TRSR+"/gem");
  replace_program(MONSTER);
}
