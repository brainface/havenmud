/* Aerelus
   This virtual forms the maze for the quest down in the forest plane.
   The reward is a scroll for the natural_enchantment spell "gift of nature".
   Player will navigate the maze, dig up a scroll, give it to the dryad at 
   the beginning, and receive the reward. It's fairly complex, but nothing 
   a monkey couldn't do with a piece of paper and a pen. The hedges are 
   mean, and will attack pretty fiercly. Also, on occasion, an exit will
   be created that will lead back to the start of the maze. Pain in the 
   ass for a player, but nature is complicated like that.
*/

#include <lib.h>
#include <domains.h>
#include <daemons.h>
#include <std.h>
inherit "/domains/planes/virtual/maze/lib_maze.c";
#include "maze/maze.h"

static void SetupRoom(int x, int y);
static void DebugMap();
static mixed mazemap;
static int XPosition, YPosition;

static void create(int x, int y)
{  
  if (!sizeof(mazemap))
  {
  	// Big huge map of the maze. Well over 80 chars. Don't hurt me.  	
    mazemap = ({ 
	    ({ 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 }), 
	    ({ 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0 }), 
      ({ 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0 }), 
      ({ 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0 }), 
      ({ 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0 }), 
      ({ 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1 }), 
      ({ 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0 }), 
      ({ 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0 }), 
      ({ 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0 }), 
      ({ 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0 }), 
      ({ 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0 }), 
      ({ 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1 }), 
      ({ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0 }), 
      ({ 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 }), 
      ({ 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0 }), 
      ({ 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0 }), 
      ({ 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0 }), 
      ({ 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0 }), 
      ({ 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0 }), 
      ({ 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }), 
      ({ 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }),   	
      ({ 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }),   	
      ({ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }),   	
      ({ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 })  	
    });
  } 
  
  // Set some room variables.
  SetNoReplace(1);
  ::create();
  XPosition = x;
  YPosition = y;
  SetShort("in a narrow hedge maze");
  SetClimate("temperate");
  SetProperty("lower plane",1);   
  SetProperty("no teleport", 1);
  SetDayLight(-40);
  SetNightLight(-40);
  SetClimate("temperate"); 
  SetProperty("no weather", 1);
  SetupRoom(x, y); 
}

static void SetupRoom(int x, int y) 
{
  string long;
  string tmp;
  int mapx, mapy;
  int c;
	string e, w, sw, ne, se, s, n, nw; 
	object hedge;
	// Set the long description. 
	long = "This long, narrow maze is made up of extremely dense hedges, ";
	long += "so thick that the only possible means of escape is either death, ";
	long += "or reaching the exit. ";
  for(c = 1; c < 3; c++)
  {
    tmp = Longs[random(sizeof(Longs))];
    Longs -= ({ tmp });
    long += (tmp + " ");
  }  
  
  // Invert y, because nobody likes reading a map (let alone creating a map :p)
  // upsides down.
  mapy = -y;
  mapx = x;    
  
  // Now find which exits exist on the map.
  
  // Northwest
  if ((mapy - 1) >= 0)
  {
    if ((mapx - 1) >= 0)
    {
    	if (mazemap[mapy-1][mapx-1] == 1)
    	{
    	  nw = MAZE + (x-1) + "," + (y+1);    	
    	}
    }
  }
  
  // North
  if ((mapy - 1) >= 0)
  {
    if (mazemap[mapy-1][mapx] == 1)
    {
    	n = MAZE + x + "," + (y+1);    
    }
  }
  
  // Northeast
  if ((mapy - 1) >= 0)
  {
    if ((mapx + 1) < 50)
    {
    	if (mazemap[mapy-1][mapx+1] == 1)
    	{
    	  ne = MAZE + (x+1) + "," + (y+1);    	
    	}
    }
  }
  
  // West
  if ((mapx - 1) >= 0)
  {
    if (mazemap[mapy][mapx-1] == 1)
    {
      w = MAZE + (x-1) + "," + y;
    }
  }
  
  // East
  if ((mapx + 1) < 50)
  {    
    if (mazemap[mapy][mapx+1] == 1)
    {
      e = MAZE + (x+1), "," + y;
    }
  }
  
  // Southwest
  if ((mapy + 1) < 24)
  {
    if ((mapx - 1) >= 0)
    {
    	if (mazemap[mapy+1][mapx-1] == 1)
    	{
    	  sw = MAZE + (x-1) + "," + (y-1);
    	}
    }
  }
  
  // South
  if ((mapy + 1) < 24)
  {
    if (mazemap[mapy+1][mapx] == 1)
    {
    	s = MAZE + x + "," + (y-1);
    }
  }
  
  // Southeast
  if ((mapy + 1) < 24)
  {
    if ((mapx + 1) < 50)
    {
    	if (mazemap[mapy+1][mapx+1] == 1)
    	{
    	  se = MAZE + (x+1) + "," + (y-1);
    	}
    }
  }
  
  // Back to the start! Do not pass go, do not collect 200 imperials.
  if (random(30))
  {
  	switch (random(3))
  	{
  		case 0:
  			if (!ne)
  			{
  			  ne = MAZE + "6,0";
  			  long += " The air to the northeast seems to shimmer slightly.";
  		  }
  			break;
  		case 1:
  			if (!nw)
  			{
  			  nw = MAZE + "6,0";
  			  long += " The air to the northwest seems to shimmer slightly.";
  		  }
  			break;
  		case 2:
  			if (!se)
  			{
  			  se = MAZE + "6,0";
  			  long += " The air to the southeast seems to shimmer slightly.";
  			}
  			break;
  		case 3:
  			if (!sw)
  			{
  			  sw = MAZE + "6,0";
  			  long += " The air to the southwest seems to shimmer slightly.";
  			}
  			break;
  		default:
  			if (!ne)
  			{
  			  ne = MAZE + "6,0";
  			  long += " The air to the northeast seems to shimmer slightly.";
  			}
  			break;
  	}
  }
  
  if ((x == 37) && (y == -17))
  {
    long += " The air to the south seems to shimmer slightly.";
  }
  
  // Add the exits we just created.
  if (ne) AddExit("northeast", ne);
  if (se) AddExit("southeast", se);
  if (nw) AddExit("northwest", nw);
  if (sw) AddExit("southwest", sw);
  if (n) AddExit("north", n);
  if (s) AddExit("south", s);
  if (e) AddExit("east", e);
  if (w) AddExit("west", w);  
  
  // Fire me if this happens.
  if (!sizeof(GetExits()))
  {
    // But not if you're just updating the virtual
    if ((x != 0) && (y != 0))
    {
      CHAT_D->eventSendChannel("ForestQuest", "reports", "The virtual is "
        "broken, time to rid Aerelus :(");
      AddExit("south", MAZE + (x) + "," + (y-1));
    }
  }
  
  // Finally, set the long desc, and any other stuff.
  SetLong(long);   
  SetSmell( ([
    "default" : Smells[random(sizeof(Smells))],
  ]) );
  SetListen( ([
    "default" : Listens[random(sizeof(Listens))],
  ]) );
}

// This function exists for testing. Don't feel you have to keep it. 
public void DebugMap()
{
	string map;
	string colour;
	int x, y, cur;	
	map = "   %^GREEN%^Forest Plane Quest%^RESET%^   \n    ";
	colour = "";
	for (y = 0; y < 24; y++)
	{	  
	  for (x = 0; x < 50; x++)
	  {
	    cur = mazemap[y][x];
	    if ((x == 6) && (y == 0)) colour = "%^GREEN%^";
	    if ((x == 37) && (y == 18)) colour = "%^RED%^";	    
	    if (cur == 0) map += " ";
	    if (cur == 1) map += colour + "%^BOLD%^+%^RESET%^";
	    colour = "";
	  }
	  map += "\n    ";
	}
	debug(map);
}



