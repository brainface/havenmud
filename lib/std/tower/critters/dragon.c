#include <mudlib.h>
#include <types.h>
#include "../rooms.h"
inherit MONSTER;

void reset(int arg) {
  if (!is_clone(this_object())) return;
  ::reset(arg);
  if (arg) return;
  set_name("Kysanth");
  set_alias("dragon");
  set_race("dragon");
  set_short("a huge black dragon");
  set_long("\
This is Kysanth, the dragon that the draconians worship \n\
as a god.  You are afraid.\n");
  set_level(25 + random(10));
  set_chance(45);
  set_spell_mess1("The dragon breathes a stream of acid!");
  set_spell_mess2("The dragon spits acid at you!");
  set_spell_dam(50);
  set_spell_type(DAM_ACID);
  add_money(2000 + random(1000));
  set_switch_chance(50);
  add_dodge_bonus(-10);
  add_clone(TRSR+"/gem",random(3));
  add_resistance(DAM_ACID);
  set_al(-400,100);
  set_friends("draconian");
  add_attack(6,30,0,35,DAM_FIRE|WEAPON_SLASH,0, ({
({ "from groin to chin","from groin to chin","ripping","ripping" }),
({ "practically gutting them","practically gutting you","tears at","tears at" }) }) );
  replace_program(MONSTER);
}
