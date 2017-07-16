/*    /verbs/rooms/travel.c
 *    continuously go in a certain direction
 *    travel STR
 *    Mahkefel's mangling of the go verb
 *
 */

#pragma save_binary
#include <lib.h>

inherit LIB_VERB;

mapping cardinals = ([
  "north":"south",
  "northeast":"southwest",
  "east":"west",
  "southeast":"northwest",
  "south":"north",
  "southwest":"northeast",
  "west":"east",
  "northwest":"southeast",
]);

mapping abbreviations = ([
  "n":"north",
  "ne":"northeast",
  "e":"east",
  "se":"southeast",
  "s":"south",
  "sw":"southwest",
  "w":"west",
  "nw":"northwest",
]);

static void create() {
    verb::create();
    SetVerb("travel");
    SetRules("STR");
    SetErrorMessage("Travel in which direction?");
    SetHelp("Syntax: <travel DIRECTION>\n\n"
            "Travels along a length of straight road through multiple \n"
            "rooms. You will stop as soon as you reach a room with \n"
            "multiple paths to take, or until you've traveled 25 rooms.\n"
            "You must travel in a cardinal direction, such as 'travel north'\n"
            "or 'travel southeast'\n"
            "Abbreviations (n, s, e) also work.\n"
            "See also: go");
}

mixed can_travel_str(string str) {
  if(this_player()->GetParalyzed()) return "You are unable to move.";
  if(this_player()->GetSleeping() ) return "You are asleep!";
  if( !environment(this_player()) ) return "You are nowhere.";
  if( !creatorp(this_player()) && (int)this_player()->GetStaminaPoints() <3 )
      return "You are too tired to go anywhere right now.";

  // turn abbreviations into full word i.e. n = north
  if (member_array(str, keys(abbreviations)) > -1) {
    //debug(str);
    str = abbreviations[str];  
    //debug(str);
  }        
  //debug("["+str+"]");
  if (member_array(str, keys(cardinals)) == -1) {
    return "You can only travel in cardinal directions! (north, southeast, and so on)";
  }
 
  return (mixed)environment(this_player())->CanGo(this_player(), str);
}

mixed do_travel_str(string str) {
  object room;
  mixed return_value;
  int failsafe = 0;

  room =  environment( this_player() );

  // turn abbreviations into full word i.e. n = north
  if (member_array(str, keys(abbreviations)) > -1) {
    //debug(str);
    str = abbreviations[str];  
    //debug(str);
  }      
  
  do {
    failsafe+=1; // infinite loop protection
    return_value = (mixed)environment(this_player())->eventGo(this_player(), str);
    room =  environment( this_player() );     
    //debug("exits: " + sizeof(room->GetExits()));
    //debug("enters: " + sizeof(room->GetEnters()));
  } while (                               
    failsafe <= 25                  
    && sizeof(room->GetExits()) == 2
    && sizeof(room->GetEnters()) == 0
    && member_array(str, room->GetExits()) != -1
    && environment(this_player())->CanGo(this_player(), str)
    && return_value // eventGo returns 0 on a fail, 1 on success
  );

  return return_value;
}

