#include <lib.h>
#define ACID (1 << 9)
inherit LIB_ROOM;


static void create() 
{
  room::create();

  SetShort("acid pool");
  SetObviousExits("out");
  SetExits( ([ "out" : "/realms/balishae/someroom"]) );
            
  SetLong("A deep and nasty acid pool");
}

void init()
{
  int i;
  for(i=0;i<=sizeof(all_inventory(this_player()));i++)
  {
    all_inventory(this_player())[i]->eventDeteriorate(ACID);
  }
  write("An acrid odor assaults you as you enter the pool of acid "
        "many of your items are damaged.");
}
