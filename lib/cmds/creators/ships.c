//Command to see instantiated ships
//Davantalus@Haven
//2004813
// Tweaked the way this works.  I cheated
// and added code to the daemon.  
// Duuk
#include <lib.h>
#include <daemons.h>
#include <vehicle.h>
#define TITLE_C "%^BLUE%^"
#define RES "%^RESET%^"

#define IDLE_TIME 60*2

inherit LIB_DAEMON;

int SortObByName(object a, object b);
void doPrintShip(object ship, object who);
string withSpaces(string s);
string GetMeaningfulSize(int i);

static void create() {
  ::create();
  SetNoClean(1);
}

int cmd() {
  object who = this_player();
  int wide = who->GetScreen()[0];
  string spacer = "-";
  string msg;
  object *ships  = VEHICLES_D->GetShips();
  ships = filter(ships, (: $1->GetOwner() || $1->GetCaptain() :) );


  if(sizeof(ships)==0)  {
    who->eventPrint("No ships, mate");
    return 1;
  }
  msg = sprintf("%-10s %-10s %-18s %12s %11s", 
    "Owner", "Captain", "Ship Name", "Ship Size", 
    "Health/100");
  who->eventPrint(TITLE_C + msg + RES);
  msg = "";
  while(wide--) {
    msg += "-";
  }
  who->eventPrint(msg);
  foreach(object ship in sort_array(ships, (:SortObByName:)) ) {
    if (!environment(ship)) { ship->eventDestruct(); continue; }
    doPrintShip(ship, who);
  }
  return 1;
}

string Resize(string str) {
   if (!stringp(str)) return str;
  str = str[0..16];
  return str;
}

//Prints the ships information
void doPrintShip(object ship, object who) {
  string msg;
  msg = sprintf("%-10s %-10s %-18s %12s %-11s", 
    Resize(ship->GetOwner()   ? ship->GetOwner() : "none"), 
    Resize(ship->GetCaptain() ? ship->GetCaptain() : "none"), 
    Resize(ship->GetVehicleName() != "" ? ship->GetVehicleName() : ship->GetKeyName()),
    GetMeaningfulSize(ship->GetVehicleSize()),
    ship->GetDamagePoints()/100 + "/" + ship->GetMaxDamagePoints()/100
    );
  who->eventPrint(msg);
 
}

string withSpaces(string s) {
  int wide = this_player()->GetScreen()[0];
  int part = (wide/5)-2; //five catagories minus a few for good measure
  int dontneed = sizeof(s);

  if(s == 0) s = ""; 
  if(sizeof(s)>14) s = s[0..14];
  for(int i=0; i<=(part-dontneed); i++)
  { s = s + " "; } 

  return s;
}

int SortObByName(object a, object b)
{
  return strcmp(a->GetOwner() || "none", b->GetOwner()  || "none");
}

string GetMeaningfulSize(int i)
{
  if(i == VS_YACHT)       return "Yacht";
  if(i == VS_GALLEY)      return "Galley";
  if(i == VS_CRUISER)     return "Cruiser";
  if(i == VS_DREADNAUGHT) return "Dreadnaught";
  return "Unknown";
}

string GetHelp()
{
  return ( "Returns a list of instantiated ships." );
}

