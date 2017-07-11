// Dalnairn
// Aerelus

#include <lib.h>
#include "../dalnairn.h"
inherit LIB_ITEM;
#include "../wanted.h"
void ReadMe();

static void create() {
  item::create();
  SetKeyName("poster");
  SetId( ({"poster"}) );
  
  SetShort("a wanted poster");
  SetLong("This is a poster listing the names and crimes of all "
          "people wanted in Dalnairn. One could read it.");
  SetAdjectives( ({"wanted"}) );
  SetPreventGet("It is nailed firmly to the wall.");
  SetMass(450);
  SetRead("default", (: ReadMe :) );
}

void ReadMe() 
{
  int anything;
  anything = 0;
  foreach(string person in keys(Crimes)) 
  {
     anything++;
     this_player()->eventPrint(capitalize(person) + " is wanted for " +
         Crimes[person] + ".");
  }
  if (anything == 0)
  {
  	this_player()->eventPrint("There are currently no names on the poster.");
  }
}
