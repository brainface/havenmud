#include <lib.h>
#include <domains.h>
inherit LIB_CHAPEL;

static void create() {
  ::create();
  SetShort("the Church of Saryth");
  SetAmbientLight(35);
  SetClimate("indoors");
  SetTown("Averath");
  SetReligion("Kylin");
  SetExits( ([
    "out" : AVERATH_ISLAND "-1,-1,0",
/*
    "up"  : AVERATH_CITY "cleric_retreat",
*/
    ]) );
  SetLong("The Church of Saryth is a small but tidy place, home "
          "to the Kylin order of clerics and center of "
          "worship for the citizens of Averath. Wooden pews line "
          "the room, all focused on a small altar which humbly "
          "occupies the center of attention.");
  SetItems( ([
    "altar" : "The altar is a small wooden affair of humble design.",
    ({ "pew", "pews" }) : "The pews are wooden and worn smooth "
                          "from use.",
    ]) );
  SetItemAdjectives( ([
    "altar" : ({ "small", "wooden", "humble" }),
    "pew"   : ({ "small", "wooden", }),
    ]) );
  SetInventory( ([
    AVERATH_NPC "cleric" : 1,
    AVERATH_NPC "healer" : 1,
    ]) );
  SetSmell( ([
    "default" : "The scent of incense lightly taints the air.",
    ]) );
  SetListen( ([
    "default" : "The church seems quiet and subdued.",
    ]) );
}

