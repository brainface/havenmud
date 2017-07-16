#include <lib.h>
#include <domains.h>
inherit LIB_FISHING;

static void create(int x, int y) {
  string n, s, e, w;
  ::create();
  SetSpeed(5);
  SetChance(20);
  SetMaxFishing(10);
  SetFish( ([
    XANDRIA_TOWNS "lisht/obj/fish_perch" : 20,
    XANDRIA_TOWNS "lisht/obj/fish_catfish" : 10,
    ]) );
  SetShort("along the River Itro");
  SetClimate("arid");
  
  SetLong(
    "The River Itro is the heart of the Xandrian culture. Its deep waters "
    "run from the coast of the Southern Sea to the north all the way to "
    "Lake Rantera to the far south."
    );
  
  n = XANDRIA_VIRTUAL + "river/" + (x) + "," + (y + 1);
  s = XANDRIA_VIRTUAL + "river/" + (x) + "," + (y - 1);
  w = XANDRIA_VIRTUAL + "river/" + (x - 1) + "," + (y);
  e = XANDRIA_VIRTUAL + "river/" + (x + 1) + "," + (y);
  
  if (x ==  1) e = XANDRIA_VIRTUAL + "desert/2," + y;
  if (x == -1) w = XANDRIA_VIRTUAL + "desert/-2," + y;
  
  if (x == 1 && (y >= -1 || y <= -7)) {
    SetProperty("coastal", 1);
    if (y < -10) e = 0;
    AddLong(" To the east sprawls the Xandrian Desert, leading away from the river "
            "and into the depths of the open dunes.");
    }            
  if (x == -1 && (y >= -1 || y <= -7)) {
    SetProperty("coastal", 1);
    if (y < -10) w = 0;
    AddLong(" To the west sprawls the Xandrian Desert, leading away from the river "
            "and into the depths of the open dunes.");
    }
  if (x == 0) {
    SetProperty("shallows", 1);
    AddLong(" The River Itro is surprisingly deep here.");
    }
  if (y == 0) {
    AddLong(" To the north, the river spills out into the Southern Sea.");
    n = INNERSEA_VIRTUAL "ocean/" + x + ",-500";
  }
  if (y == -50) {
    s = 0; /* Area Exit for the Lake */
    AddLong(" To the south lies Lake Rantera.");
    switch(x) {
      case -1: s = XANDRIA_AREAS "lake/room/1d"; break;
      case  0: s = XANDRIA_AREAS "lake/room/1e"; break;
      case  1: s = XANDRIA_AREAS "lake/room/1f"; break;
    }
  }
  if (y >= -10 && y < -1) {
    AddLong(" The river runs near the city of Lisht, the capital of the Xandrian Dynasty. "
            "Lisht lies along the western bank of the river.");
    if (y == -10) AddLong(" The city wall is to the northwest, protecting the city. The "
                          "wall is open to the riverside however and does not restrict "
                          "entry to the city.");
    if (y == -1)  AddLong(" The city wall is to the southwest, protecting the city. The "
                          "wall is open to the riverside however and does not restrict "
                          "entry to the city.");
  }                    
  if (y >= -1) {
    AddLong(" To the southwest lies the city of Lisht. Further sailing south would provide "
            "access to the city.");
    }    
  if (y >= -6 && y <= -2) {
    AddLong(" To the west lie the floodplains that serve to feed the city of Lisht.");
    SetProperty("coastal",1);
    if (x == -1) {
      switch(y) {
        case -6:
          w = XANDRIA_TOWNS "lisht/room/elf/fp5";
          break;
        case -5:
          w = XANDRIA_TOWNS "lisht/room/elf/fp4";
          break;  
        case -4:
          w = XANDRIA_TOWNS "lisht/room/elf/fp3";
          break;
        case -3:
          w = XANDRIA_TOWNS "lisht/room/elf/fp2";
          break;
        case -2:
          w = XANDRIA_TOWNS "lisht/room/elf/fp1";
          break;
        }
      }
    }  
  SetSmell("The river smells of mud and fish.");
  SetListen("The waves of the river are gentle and calm.");
  if (n) AddExit("north", n);
  if (s) AddExit("south", s);
  if (e) AddExit("east", e);
  if (w) AddExit("west", w);           
  
}
