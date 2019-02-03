
#include <lib.h>
#include <std.h>
inherit LIB_ROOM;

static void create() {
  room::create();
  SetShort("Davantalus' Modified Portal Room");
  SetClimate("indoors");
  SetAmbientLight(40);
  SetObviousExits("west, or \"enter <desintation>\"");
  SetItems( ([
     "arcanith"   : "/domains/frostmarches/towns/arcanith/room/ruins1",
     "baria"      : "/domains/baria/towns/baria/room/path9",
     "durgoroth"  : "/domains/frostmarches/towns/durgoroth/room/road01",
     "glimmerdin" : "/domains/crystal_reaches/towns/glimmerdin/room/gh_central",
     "heaven"     : "/domains/heaven/immheaven/olympus",
     "haven"      : "/domains/southern_coast/towns/haven/room/imperial_road/ir2",
     "jidoor"     : "/domains/valley/towns/jidoor/room/twnsquare",
     "karak"      : "/domains/crystal_reaches/towns/karak/room/rd4",
     "keryth"     : "/domains/frostmarches/towns/keryth/room/road2",
     "lloryk"     : "/domains/crystal_reaches/towns/lloryk/room/hb4",
     "malveillant": "/domains/havenwood/towns/malveillant/rooms/center1",
     "parva"      : "/domains/havenwood/towns/parva/room/path2",
     "sanctum"    : "/domains/peninsula/towns/sanctum/room/vi05",
     "soleil"     : "/domains/westwood/towns/soleil/room/tree_b",
     "staffroom"  : "/domains/staff/staffroom",
     "tairi"      : "/domains/tairi/towns/tairi/room/p2",
     "ungkh"      : "/domains/crystal_reaches/towns/ungkh/room/road03",
     "vacazar"    : "/domains/estergrym/towns/vacazar/room/main_road/mr4",
     "void"       : "/domains/staff/adm/void",
     "averath"    : "/domains/averath/towns/averath/room/road2",
     "first"      : "/domains/planes/virtual/first/0,0",
     "fire"       : "/domains/planes/virtual/fire/0,0",
     "forest"     : "/domains/planes/virtual/forest/0,0",
     "yozrath"    : "/domains/yozrath/towns/yozrath/room/gate3",
     "lisht"      : "/domains/xandria/towns/lisht/room/gnoll/gate",
     "gurov"      : "/domains/gurov/towns/gurov/room/gate",
     "dalnairn"   : "/domains/averath/towns/dalnairn/room/road2",


   ]) );

  SetExits( ([
     "west" : "/domains/staff/staffroom",
  ]) );

  SetEnters( ([
     "arcanith"   : "/domains/frostmarches/towns/arcanith/room/ruins1",
     "baria"      : "/domains/baria/towns/baria/room/path9",
     "durgoroth"  : "/domains/frostmarches/towns/durgoroth/room/road07",
     "glimmerdin" : "/domains/crystal_reaches/towns/glimmerdin/room/gh_central",
     "heaven"     : "/domains/heaven/immheaven/olympus",
     "haven"      : "/domains/southern_coast/towns/haven/room/imperial_road/ir2",
     "jidoor"     : "/domains/valley/towns/jidoor/room/twnsquare",
     "karak"      : "/domains/crystal_reaches/towns/karak/room/rd4",
     "keryth"     : "/domains/frostmarches/towns/keryth/room/road2",
     "lloryk"     : "/domains/crystal_reaches/towns/lloryk/room/hb4",
     "malveillant": "/domains/havenwood/towns/malveillant/rooms/center1",
     "parva"      : "/domains/havenwood/towns/parva/room/path2",
     "sanctum"    : "/domains/peninsula/towns/sanctum/room/vi05",
     "soleil"     : "/domains/westwood/towns/soleil/room/tree_b",
     "staffroom"  : "/domains/staff/staffroom",
     "tairi"      : "/domains/tairi/towns/tairi/room/p2",
     "ungkh"      : "/domains/crystal_reaches/towns/ungkh/room/road03",
     "vacazar"    : "/domains/estergrym/towns/vacazar/room/main_road/mr4",
     "void"       : "/domains/staff/adm/void",
     "averath"    : "/domains/averath/towns/averath/room/road2",
     "first"      : "/domains/planes/virtual/first/0,0",
     "fire"       : "/domains/planes/virtual/fire/0,0",
     "forest"     : "/domains/planes/virtual/forest/0,0",
     "yozrath"    : "/domains/yozrath/towns/yozrath/room/gate3",
     "lisht"      : "/domains/xandria/towns/lisht/room/gnoll/gate",
     "gurov"      : "/domains/gurov/towns/gurov/room/gate",
     "dalnairn"   : "/domains/averath/towns/dalnairn/room/road2",

     
  ]) );
  SetLong("Use this room to get around the world. \n"
    "Enters are " + conjunction(GetEnters(), "and") + ".");
}
