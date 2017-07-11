#include <lib.h>
#include <domains.h>
inherit LIB_ROOM;

void SetRoom(int, int);
void SetMinaret(int, int);
int PreFire();
int *GetCoordinates();
int X, Y, counter;

static void create(int x, int y) {
  string n, e, s, w;
  ::create();
  counter = 0;
  SetShort("in the barren Yozrath Desert");
  if (x <= 2 && x >= -2 && y >= -2 && y <= 2) SetShort("near the City of Yozrath");
  if (x > -100) w = YOZRATH_VIRTUAL "desert/" + (x - 1) + "," + y;
  if (x <  100) e = YOZRATH_VIRTUAL "desert/" + (x + 1) + "," + y;
  if (y > -100) s = YOZRATH_VIRTUAL "desert/" + (x) + "," + (y - 1);
  if (y <  100) n = YOZRATH_VIRTUAL "desert/" + (x) + "," + (y + 1);
  if (n) AddExit("north", n);
  if (s) AddExit("south", s);
  if (e) AddExit("east", e);
  if (w) AddExit("west", w);
  if (x == 100 && y == -100) { 
    AddExit("southeast", HAVENWOOD_VIRTUAL "havenwoodroad/155,155");
    AddInventory(YOZRATH_VIRTUAL "merchant/merchant", 1);
    }
  SetClimate("arid");
  SetLong(
    "The Yozrath Desert is a massive expanse of sand and barren waste "
    "that seems to go off into the horizon without end. Far off in the "
    "distance to the east, the faint outlines of the Estergrym mountains "
    "stand against the sky, while far off to the west the FrostMarches "
    "taint the horizon. To the southwest lie the Crystal Reaches."
    );
  if (x == -100) 
    SetLong(GetLong() + 

      " The desert ends here at the base of the FrostMarches. Further travel "
      "west is impossible."
      );
  if (y == 100 && x != 40) {
    AddLong( 
      " To the north is the River Bjorn "
      "which marks the boundries of the Yozrath Desert to the south and the "
      "Principality of Gurov to the north. From here, the river is too swift "
      "and deep to ford to the north."
      );
    AddItem("river", "The River Bjorn is too deep and swiftly moving to cross.");
  }
  if (y == 100 && x == 40) {
    AddLong( 
      " To the north is the River Bjorn "
      "which marks the boundries of the Yozrath Desert to the south and the "
      "Principality of Gurov to the north. There is a small ford here to cross "
      "the river into the Plains of Gurthlad. To the northwest lies a small path "
      "that seems to lead to a monastery of some kind."
      );
    AddExit("north", GUROV_AREAS "gurthlad/rooms/room45");
    AddExit("northwest", YOZRATH_AREAS "monastery/room/gates");
    }
  if (y == -100 && x < 0) 
    SetLong(GetLong() + 
      " The desert ends here at the base of the Crystal Reaches. Further "
      "travel south is impossible."
      );
  if (y == -100 && x >= 0) 
    SetLong(GetLong() + 
      " The desert ends here and seems to trail off into the plains that "
      "comprise the HavenWood and Southern Coast. There are no paths leading "
      "further south."
      );
  if (x == 100 && y >50) 
    SetLong(GetLong() + 
      " The desert ends
 here at the base of the Estergrym Mountains. "
      "Further travel east is impossible."
      );
  if (x == 100 && y <= 50)
    SetLong(GetLong() + 
      " The desert seems to end here, trailing off into the plains that "
      "make up the Southern Coast and the HavenWood. Further travel east "
      "is limited by the lack of paths over the land."
      );
  if (x == 2 && y ==2 ) {
     SetLong(GetLong() +
       " To the southwest lies the City of Yozrath. The high stone walls of "
       "the city have a smooth, sand-worn face that blocks the view into the "
       "streets."
       );
     }
  if (x == 1 && y ==2 ) {
     SetLong(GetLong() +
       " To the south lies the City of Yozrath. The high stone walls of "
       "the city have a smooth, sand-worn face that blocks the view into the "
       "streets."
       );
     RemoveExit("south");
     }
  if (x == 0 && y ==2 ) {
     SetLong(GetLong() +
       " To the south lies the City of Yozrath. The high stone walls of "
       "the city have a smooth, sand-worn face that blocks the view into the "
       "streets."
       );
     RemoveExit("south");
     }
  if (x == -1 && y ==2 ) {
     SetLong(GetLong() +
       " To the south lies the City of Yozrath. The high stone walls of "
       "the city have a smooth, sand-worn face that blocks the view into the "
       "streets."
       );
     RemoveExit("south");
     }
  if (x == -2 && y ==2 ) {
     SetLong(GetLong() +
       " To the southeast lies the City of Yozrath. The high stone walls of "
       "the city have a smooth, sand-worn face that blocks the view into the "
       "streets."
       );
     }
  if (x == -2 && y < 2 && y > -2) {
     SetLong(GetLong() +
       " To the east lies the City of Yozrath. The high stone walls of "
       "the city have a smooth, sand-worn face that blocks the view into the "
       "streets."
      );
      RemoveExit("east");
    }
  if (x == 2 && y < 2 && y > -2) {
     SetLong(GetLong() +
       " To the west lies the City of Yozrath. The high stone walls of "
       "the city have a smooth, sand-worn face that blocks the view into the "
       "streets."
      );
      RemoveExit("west");
    }
  if (x == -2 && y == -2 ) {
     SetLong(GetLong() +
       " To the northeast lies the City of Yozrath. The high stone walls of "
       "the city have a smooth, sand-worn face that blocks the view into the "
       "streets."
       );
     }
  if (x == 2 && y == -2 ) {
     SetLong(GetLong() +
       " To the northwest lies the City of Yozrath. The high stone walls of "
       "the city have a smooth, sand-worn face that blocks the view into the "
       "streets."
       );
     }
  if (y == -2 && x < 2 && x > -2) {
     SetLong(GetLong() +
       " To the north lies the City of Yozrath. The high stone walls of "
       "the city have a smooth, sand-worn face that blocks the view into the "
       "streets."
      );
      RemoveExit("north");
    }
  SetSmell( ([
    "default" : "The desert air is remarkably clean and crisp.",
    ]) );
  SetListen( ([
    "default" : "Sand shifts and occasionally a deep rumble comes from the desert sands.",
    ]) );

  SetMinaret(x, y);

  SetRoom(x, y);
}

void SetMinaret(int x, int y) {
  int towerMin = 33;
  int towerMax = 47;
  int margin = 43;
  int viewMin = towerMin - margin;
  int viewMax = towerMax + margin;

  // maybe save some cpu or whatev.
  if ( (x < viewMin || x > viewMax) && (y < viewMin || y > viewMin) ) return;

  // torak's minaret distant view
  // arglebarg numbers
  // NW
  if ( (x >= viewMin && x < towerMin && y > towerMax && y <= viewMax)
    || (x == towerMin && y == towerMax)) {
    AddLong(" To the southeast the horizon is broken by the peak of a towering minaret.");    
  // W
  } else if (x >= viewMin && x < towerMin && y >= towerMin && y <= towerMax) {
    AddLong(" To the east the horizon is broken by the peak of a towering minaret.");

  // SW
  } else if ((x >= viewMin && x < towerMin && y >= viewMin && y < towerMin)
    || (x == towerMin && y == towerMin) ) {
    AddLong(" To the northeast the horizon is broken by the peak of a towering minaret.");

  // S
  } else if (x >= towerMin && x <= towerMax && y >= viewMin && y < towerMin) {
    AddLong(" To the north the horizon is broken by the peak of a towering minaret.");

  // SE
  } else if ( (x > towerMax && x <= viewMax && y >= viewMin && y < towerMin)
    || (x == towerMax && y == towerMin) ) {
    AddLong(" To the northwest the horizon is broken by the peak of a towering minaret.");

  // E
  } else if (x > towerMax && x <= viewMax && y >= towerMin && y <= towerMax) {
    AddLong(" To the west the horizon is broken by the peak of a towering minaret.");

  // NE
  } else if ( (x > towerMax && x <= viewMax && y > towerMax && y <= viewMax) 
    || (x == towerMax && y == towerMax) ) {
    AddLong(" To the southwest the horizon is broken by the peak of a towering minaret.");

  // N
  } else if (x >= towerMin && x <= towerMax && y > towerMax && y <= viewMax) {
    AddLong(" To the south the horizon is broken by the peak of a towering minaret.");
  }

  if (x <= towerMax && x >= towerMin && y <= towerMax && y >= towerMin
    // omit ne,se,nw,sw corners
    &&  ((x == towerMax) + (y == towerMax) + (x == towerMin) + (y == towerMin)) < 2 ) {
    SetShort("At the base of an immense white minaret.");
    AddLong(" The towering minaret blocks further progress ");
    AddItem("minaret","The brilliant white structure looms overhead, peak "
      "obscured by the clouds.");
  }

  // torak's minaret 'hole'
  if (x == towerMin && y > towerMin && y < towerMax) {
    AddLong("to the east. It looks like ramp spirals up nearby to the north.");

    RemoveExit("east");
    AddItem("ramp","A ramp seems to spiral upwards, providing a path up the "
      "tower. Unaccessible here, it seems to reach the ground somewhere northward.");
  } else if ( x == towerMax && y > towerMin && y < towerMax ) {
    AddLong("to the west. ");
    RemoveExit("west");
  } else if ( y == towerMin && x > towerMin && x < towerMax ) {
    AddLong("to the north. ");
    RemoveExit("north");
  } else if ( y == towerMax && x > towerMin && x < towerMax ) {
    AddLong("to the south. It looks like a ramp spirals up nearby to the west.");
    RemoveExit("south");
    AddItem("ramp","A ramp seems to spiral upwards, providing a path up the "
      "tower. Unaccessible here, it seems to reach the ground somewhere westward.");
  }
}
  
void SetRoom(int x, int y) {
  mapping inv = ([ ]);
  X = x;  Y = y;
  if (!random(100)) inv[YOZRATH_VIRTUAL "npc/watermerchant"] = 1;
  if (!random(66))  inv[YOZRATH_VIRTUAL "npc/nomad"]         = 1;
  if (!random(100)) inv[YOZRATH_VIRTUAL "npc/dervish"]       = 1; 
  if (!random(33))  inv[YOZRATH_VIRTUAL "npc/camel"]         = random(3) + 1; 

  if (x == 0 && y == -2) {
    SetLong(GetLong() + " The Southern Gate to Yozrath City lies here, leading into the city "
                        "to the north.");
    AddExit("north", YOZRATH_TOWNS "yozrath/room/gate5");
    }
  if (x == 0 && y == 2) {
    SetLong(GetLong() + " The Northern Gate to Yozrath City lies here, leading into the city "
                        "to the south.");
    AddExit("south", YOZRATH_TOWNS "yozrath/room/gate1");
    }
  
  if (x == 40 && y == 100) inv += ([ YOZRATH_VIRTUAL "obj/river" : 1 ]);
  SetInventory(inv);
  if (!random(100)) {
    AddItem( ({ "pillar", "fire" }), 
      "This swirling pillar of fire appears to be a magical rift "
      "of some kind. Looking into the pillar seems like looking "
      "at another dimension.");
    SetItemAdjectives( ([
      "pillar" : ({ "swirling", "pillar", "of", })
      ]) );
    AddEnter("pillar", DOMAIN_PLANES "virtual/fire/0,0", (: PreFire :) );
    SetLong(GetLong() + 
      "%^RED%^ There is a swirling pillar of fire here.%^RESET%^"
      );
    }
}

int PreFire() {
  object who = this_player(); 
  if (who->GetLevel() < 50) {
    who->eventPrint("That doesn't seem like the best of ideas. You decide not to enter.");
    return 0;
  }
  return 1;
}

int *GetCoordinates() { return ({ X, Y }); }

void heart_beat() {
  ::heart_beat();
  foreach (object o in deep_inventory(this_object())) {
    if (living(o)) return;
    if (o->GetOwner()) return;
  }
  counter++;
  if (counter > 3)
    eventDestruct();
}

