#include <lib.h>
#include <domains.h>
#include "../undead.h"
inherit AVERATH_LIB;

varargs static void create(int x, int y, int z) {
  ::create(-8,-1,-3);
  SetShort("an underground shrine");
  SetDomain("Averath");
  SetClimate("underground");
  SetAmbientLight(30);
  SetProperty("no bump", 1);
  SetLong(
     "The crevice comes to an end here. Small collections of an assortment of "
     "skeletons lay strewn about here, as if they had fallen from above. In the "
     "center resides a small shrine composed of gold, generating enough lite to "
     "brighten the bottom of the cavern. "
  );
  SetItems( ([
     ({ "crevice" }) : (: GetLong :),
     ({ "skeletons" }) : "These skeletons lay strewn about here, as if they had "
     "fallen from above. ",
     ({ "shrine" }) : "This shrine is composed of gold. It generates a great deal "
     "of light, enough to lite the bottom of the cavern. ",
  ]) );
  SetItemAdjectives( ([
     "crevice" : ({ "deep" }),
     "skeletons" : ({ "assorted" }),
     "shrine" : ({ "golden" }),
  ]) );
  SetListen( ([
     "default" : "It is disturbingly quiet and calm. ",
  ]) );
  SetSmell( ([
     "default" : "The air smells old and unclean.",
  ]) );
  SetInventory( ([
     UNDEAD_NPC + "priest" : 1,
  ]) );
  SetExits( ([
     "up" : AVERATH_ISLAND + "-8,-1,-2",
  ]) );
}
