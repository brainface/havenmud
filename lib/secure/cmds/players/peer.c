/*   /secure/cmds/player/peer.c
 *   Peer into an adjacent room wihout actually entering
 *   Blitz@NightmareIV
 */

#include <lib.h>
#include <vision.h>

inherit LIB_DAEMON;

string DescribeItems(mixed var);
string DescribeLiving(mixed var);

mixed cmd(string str) {
  int i;
  string file;
  object env, *livings, *items;

  if( !sizeof(str) ) return "Syntax: peer <direction>";
  if (this_player()->GetSleeping()) return "You are asleep!";
  if( this_player()->GetBlind() )
    return "You are blind and can see nothing.";
  i = this_player()->GetEffectiveVision();
  if (i == VISION_TOO_DARK || i == VISION_DARK) {
    return "It is too dark to do that!";
    }
  if (i == VISION_TOO_BRIGHT || i == VISION_BRIGHT) {
    return "It is too bright to do that!";
    }
  env = environment(this_player());
  if( !file = (string)env->GetExit(str) ) file = (string)env->GetEnter(str);
  if (sscanf(str, "into %s", str) == 1) { file = (string)env->GetEnter(str); }

  // Mahkefel 2013
  // okay, they've peered in a direction that doesn't exist, let's see if they're
  //   on a ship.
  if ( !sizeof(file) && vehiclep(env)) { // directino doesn't exist and on a ship?
    if (environment(env)) { // god help us all, does the ship exist in a room?
      if( !file = (string)environment(env)->GetExit(str) ) {
        // this following line does nothing. too chickenshit to remove it.
        // since I'm just copying and pasting.      
        file = (string)env->GetEnter(str);
      } 
    }
  }

  if( !sizeof(file) )
    return "You cannot peer that way.";
  if( env->GetDoor(str) && ((string)env->GetDoor(str))->GetClosed() ) {
    message("my_action", sprintf("%s is blocking your view %s.",
      ((string)capitalize(env->GetDoor(str)->GetShort(str))), str),
    this_player() );
    return 1;
  }
  if (env->GetEnter(str)) { str = "into the " + str; }
  if(!env = load_object(file)) {
    message("my_action", "It is not safe to peer "+str+"!", this_player() );
    return 1;
  }
/*
  if( (int)env->GetProperty("light") < 0 ||
      (int)env->GetProperty("light") > 6 ) {
    message("my_action", "You cannot see "+str+" very well.", this_player());
    return 1;
  }
*/
  items = filter(all_inventory(env),
           (: !(int)$1->GetInvis(this_player()) :) );
  items -= ({ this_player(), environment(this_player()) });
  items = items - (livings = filter(items, (: living :)));
  message("my_action", "%^GREEN%^"
    "Peering "+str+" you see...",
  this_player() );
  if (!(this_player()->GetInvis()))
  message("other_action",
    (string)this_player()->GetCapName()+" peers "+str+".",
  environment(this_player()), this_player() );
  message("room_description",
    ("\n"+(string)env->GetLong(0)+"\n" || "\nA void.\n"),
  this_player() );
  if( sizeof(items) )
    message("room_inventory",
      "%^MAGENTA%^" + DescribeItems(items) + "%^RESET%^\n",
    this_player() );
  if( sizeof(livings) )
    message("room_inventory",
      "%^BOLD%^%^RED%^" + DescribeLiving(livings) + "%^RESET%^",
      this_player() );
  return 1;
}

string DescribeItems(mixed var) {
  mapping m = ([ ]);
  string *shorts, ret;
  int i, max;

  if( !arrayp(var) ) return "";
  i = sizeof( shorts = map(var, (: $1->GetShort() :)) );
  while(i--) {
    if( !sizeof(shorts[i]) ) continue;
    if( m[ shorts[i] ] ) m[ shorts[i] ]++;
    else m[ shorts[i] ] = 1;
  }
  i = max = sizeof( shorts = keys(m) );
  ret = "";
  for(i=0; i<max; i++) {
    if( m[ shorts[i] ] < 2 ) ret += shorts[i];
    else ret += consolidate(m[shorts[i]], shorts[i]);
    if( i == (max - 1) ) {
      if( max>1 || m[ shorts[i] ] > 1 ) ret += " are here.";
      else ret += " is here.";
    }
    else if( i == (max - 2) ) ret += ", and ";
    else ret += ", ";
  }
  return capitalize(ret);
}

string DescribeLiving(mixed var) {
  mapping m = ([ ]);
  string *shorts, ret;
  int i;
  if( !arrayp(var) ) return "";
  i = sizeof( shorts = map(var, (: $1->GetShort() :)) );
  while(i--) {
    if( !sizeof(shorts[i]) ) continue;
    if( m[ shorts[i] ] ) m[ shorts[i] ]++;
    else m[ shorts[i] ] = 1;
  }
  ret = "";
  i = sizeof( shorts = keys(m) );
  while(i--) if( m[ shorts[i] ] > 1 )
    ret += (consolidate(m[shorts[i]], shorts[i]) + "\n");
    else ret += (shorts[i] + "\n");
  return ret;
}

void help() {
  message("help",
    "Syntax: peer <direction>\n"
    "        peer into <thing>\n\n"
    "Allows you to look into an adjacent room without actually "
    "entering it.  Note that light and doorways affect what you "
    "see.\n\n",
  this_player() );
}

