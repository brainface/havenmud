#include <mudlib.h>
#include <types.h>
#include <material.h>
inherit GEN_ARMOUR;
int count;

void reset(int arg) {
  count = 0;
  ::reset(arg);
  if (arg) return;
  set_name("amulet");
  set_short("a glittering amulet");
  set_new_type(AMULET);
  set_material(MAT_SILVER);
  set_ac(0);
  set_info("\
You feel that you should focus on the amulet more.\n");
set_long("\
This is the amulet of rank that Rath-Khan wears as a symbol\n\
of his power.  You are in awe of the power it represents.\n");
  set_value(-1);
}

void init() {
  ::init();
  add_action("focus","focus");
}

int focus(string str) {
  if (!str) {
    write("What?\n");
    return 1; 
  }

  if (str != "on amulet") {
    write("What?");
    return 1;
  }

  if (count <= 2) {
    write("You focus on the evil of Rath Khan.\n");
    this_player()->add_alignment(-300);
    say(this_player()->query_name()+" seems horrendously evil.\n");
    this_player()->restore_spell_points(-20);
    count++;
    return 1;
  }
  write("Nothing happens.\n");
  return 1;
}


