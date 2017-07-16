#include <mudlib.h>
#include <types.h>
#include <material.h>
inherit WEAPON;

void reset(int arg) {
  ::reset(arg);
  if (arg) return;
  set_name("mace");
  set_short("a black mace");
  set_long("\
This sleek mace seems to be made of the hardest\n\
steel.  You sense a warm sensation eminating from\n\
the shaft of it as you look at it.\n");
  set_weight(2);
  set_steal(1);
  set_new_type(MEDIUM|BLUNT);
  set_info("You sense that the heat of the mace comes from\n\
a source of great evil.\n");
  set_material(MAT_STEEL|MAT_BONE|MAT_SILVER);
  set_class(17);
  set_damage_type(WEAPON_BLUNT|DAM_EVIL|DAM_SILVER);
  set_value(-1);
}

int weapon_hit(object attacker) {
  if (random(2)) {
    write("|RKBThe mace seems intent on destroying it's foe!\n");
    say("|RKB" + this_player()->query_name() + " \
swings the Mace of Rath-Khan in a flurry of motion!\n");
    return (random(10));
  }
  return 0;
}
