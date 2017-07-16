#include <mudlib.h>
#include <types.h>
#include <material.h>
inherit WEAPON;

void reset(int arg) {
  ::reset(arg);
  if (arg) return;
  set_name("mystery");
  set_short("a small lump of steel");
  set_long("\
A lump of formless void matter.\n");
  set_info("\
This bizzare piece of magical metal might allow you to determine what\n\
it looks like, both 'short' and 'long'.\n");
  set_new_type(MEDIUM);
  set_material(MAT_STEEL);
  set_weight(1);
  set_class(10 + random(5));
  set_value(1200);
  set_damage_type(DAM_MAGIC);
}

void init() {
  ::init();
  add_action("sdesc","short");
  add_action("ldesc","long");
}

int sdesc(string str) {
  if (!str) {
    write("Set description to what?\n");
    return 1;
  }
  this_object()->set_short(str);
  return 1;
}

int ldesc(string str) {
  if (!str) {
    write("Set description to what?\n");
    return 1;
  }
  this_object()->set_long(str+"\n");
  return 1;
}
