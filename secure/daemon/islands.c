#include <lib.h>
#include <daemons.h>
#include <island.h>

inherit LIB_DAEMON;

class VirtualIsland *Islands;

void SaveIslands() {
  unguarded( (: save_object, "/save/islands.o" :) );
}

void LoadIslands() {
  unguarded( (: restore_object, "/save/islands.o" :) );
}

static void create() {
  ::create();
  Islands = ({ });
  LoadIslands();  
}

void AddIsland(class VirtualIsland x) {
  Islands += ({ x });
  SaveIslands();
}

void RemoveIsland(string name) {
  foreach(class VirtualIsland vi in Islands) {
    if (vi->name == name) Islands -= ({ vi });
    }
  SaveIslands();
}  

void SetIsland(string name, string center, int size, string description, string exit, string exit_dir, string bay) {
  class VirtualIsland vi;
  
  vi = new(class VirtualIsland);
  
  vi->name          = name;
  vi->center        = center;
  vi->size          = size;
  vi->appearance    = description;
  vi->bay_exit      = exit;
  vi->bay_exit_direction = exit_dir;
  vi->bay_exit_file = bay;
  AddIsland(vi); 
  return;
}

string GetNearbyIsland(int x, int y) {
  foreach(class VirtualIsland vi in Islands) {
    string c;
    int iX, iY;
    c = vi->center;
    iX = to_int((explode(c, ",")[0]));
    iY = to_int((explode(c, ",")[1]));
    if ((x < (iX + 10 + vi->size)) && (x > (iX - 10 - vi->size)) && (y < (iY + 10 + vi->size)) && (y > (iY - 10 - vi->size))) return vi->name;
  }
  return 0;
}

string GetIslandDescription(string name) {
  foreach(class VirtualIsland vi in Islands) {
    if (vi->name == name) return vi->appearance;
  }
  return "";
}

string GetIslandCenter(string name) {
  foreach(class VirtualIsland vi in Islands) {
    if (vi->name == name) return vi->center;
  }
  return "";
}

int GetIslandSize(string name) {
  foreach(class VirtualIsland vi in Islands) {
    if (vi->name == name) return vi->size;
  }
  return 0;
}

string GetIslandExit(string name) {
  foreach(class VirtualIsland vi in Islands) {
    if (vi->name == name) return vi->bay_exit;
  }
  return "";
}

int *GetIslandCoordinates(string name) {
  int *tmp = ({});
  string exit;
  foreach(class VirtualIsland vi in Islands) {
    if (vi->name == name) exit = vi->bay_exit;
  }
  if (!exit) return ({ });
  foreach(string i in explode(exit, ",")) tmp += ({ to_int(i) });
  return tmp;
}

string GetIslandExitDirection(string name) {
  foreach(class VirtualIsland vi in Islands) {
    if (vi->name == name) return vi->bay_exit_direction;
  }
  return "";
}

string GetBay(string name) {
  foreach(class VirtualIsland vi in Islands) {
    if (vi->name == name) return vi->bay_exit_file;
  }
  return "";
}

void RemoveExit(string dir) {
//  debug("Removing exit: " + dir);
}

void ProcessIsland(object room, int x, int y) {
  int left_x, top_y, right_x, bottom_y;
  mixed *center;
  string tmp;
  class VirtualIsland vi;
  string island;
  
  island = GetNearbyIsland(x, y);
  if (!island) { debug("no island @ " + x + "," + y); return; }
  room->SetProperty("shallows", 1);
  room->RemoveProperty("ocean");
  
  foreach(class VirtualIsland isl in Islands) {
    if (isl->name == island) vi = isl;
  }
  
  center = explode(vi->center, ",");
  foreach(mixed item in center) {
    center -= ({ item }); center += ({ to_int(item) });
  }
//  debug("center = " + center[0] + " " + center[1]);
  left_x   = center[0] - vi->size;
  right_x  = center[0] + vi->size;
  top_y    = center[1] + vi->size;
  bottom_y = center[1] - vi->size;
//  debug("left_x = " + left_x + " right_x = " + right_x + " top_y = " + top_y + " bottom_y = " + bottom_y);
  if (x > left_x && x < right_x) {
    if (y == top_y)    { RemoveExit("s"); room->RemoveExit("south"); }
    if (y == bottom_y) { RemoveExit("n"); room->RemoveExit("north"); }
  }
  if (y < top_y && y > bottom_y) {
    if (x == left_x)   { RemoveExit("e"); room->RemoveExit("east"); }
    if (x == right_x)  { RemoveExit("w"); room->RemoveExit("west"); }
  }
  if (x == left_x) {
    if (y >= bottom_y && y != top_y) { RemoveExit("ne1"); room->RemoveExit("northeast"); }
    if (y <= top_y && y != bottom_y) { RemoveExit("se1"); room->RemoveExit("southeast"); }
  }                                 
  if (x == right_x ) {               
    if (y >= bottom_y && y != top_y) { RemoveExit("nw1"); room->RemoveExit("northwest"); }
    if (y <= top_y && y != bottom_y) { RemoveExit("sw1"); room->RemoveExit("southwest"); }
  }
  if (y == top_y) {
    if (x >= left_x && x < right_x) { RemoveExit("se2"); room->RemoveExit("southeast"); }
    if (x <= right_x && x > left_x) { RemoveExit("sw2"); room->RemoveExit("southwest"); }
    }  
  if (y == bottom_y) {
    if (x >= left_x && x < right_x) { RemoveExit("ne2"); room->RemoveExit("northeast"); }
    if (x <= right_x && x > left_x) { RemoveExit("nw2"); room->RemoveExit("northwest"); }
    }  
  if (y != center[1]) {
    if (y > center[1]) tmp = "south";
      else tmp = "north";
    } else tmp = "";
  if (x != center[0]) {
    if (x > center[0]) tmp += "west";
     else tmp += "east";
  }
  if (tmp != "") {
    room->AddLong(capitalize(vi->appearance) + " lies to the " + tmp + ".");
    room->SetShort("near " + vi->appearance);
  }
  if ((x + "," + y) == vi->bay_exit) {
//    debug("bay_exit");
    room->AddExit(vi->bay_exit_direction, vi->bay_exit_file);
    room->AddLong(" A small bay opens to the " + vi->bay_exit_direction + ".");
  }
}

mapping GetIslands() {
  mapping m = ([ ]);
  
  foreach(class VirtualIsland vi in Islands) {
    m += ([ vi->name : ({ vi->center, vi->size }) ]);
  }
  return m;
}