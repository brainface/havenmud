#include <mudlib.h>
#include "../rooms.h"
inherit MONSTER;

void reset(int arg) {
  if (!is_clone(this_object())) return;
  ::reset(arg);
  if (arg) return;
  set_name("king");
  set_alias("draconian");
  set_alt_name("lord");
  set_race("draconian");
  set_level(17+random(6));
  add_money(50+random(200));
  add_clone(TRSR + "/diamond");
  add_clone(WPNS + "/draco_sword");
  add_clone(ARMR + "/dr_arm");
  command("wield scimitar");
  command("wear mail");
  set_gender(1);
  set_short("a draconian lord");
  set_long("\
This is the king of the draconians that reside here.\n");
  set_friends("draconian");
  replace_program(MONSTER);
}
