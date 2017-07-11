#include <mudlib.h>
#include <types.h>
#include <race.h>
#include "../rooms.h"
inherit MONSTER;

void reset(int arg) {
  if (!is_clone(this_object())) return;
  ::reset(arg);
  if (arg) return;
  set_name("keeper");
  set_alt_name("man");
  set_alias("keeper");
  set_level(60);
  make_object("staff", WPNS + "/cstaff");
  make_object("robe", ARMR + "/crobe");
  command("wield staff");
  command("wear robe");
  set_no_scare(1);
  set_short("a small robed man");
  set_race("undead");
  set_long("\
This robed figure is the guardian of the Crypt.\n\
He will not permit anyone to pass by him while he \n\
guards the path.\n");
  set_gender(1);
  set_aggressive(0);
  load_chat(4, ({
    "The Crypt Keeper bemoans his state.\n",
    "The Crypt Keeper asks 'Where is my ring?'\n",
    "The Crypt Keeper wails meaningless words in a long forgotten tongue.\n",
    "The Crypt Keeper shuffles noislessly through the room.\n",
    "The Crypt Keeper holds still.  Very still.\n" }));
  set_al(1500,1500);
  set_death_messages("The Crypt Keeper passes having failed his duty.\n",
  "The Crypt Keeper falls with your last blow and fails his master.\n");
  add_money(3500);
  replace_program(MONSTER);
}
