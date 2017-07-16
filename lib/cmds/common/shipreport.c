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

  if (!creatorp(who)) {
    foreach(object ship in ships) {
      if (ship->GetOwner() != who->GetKeyName()) ships -= ({ ship });
      }
    }
  if(sizeof(ships)==0)  {
    who->eventPrint("No ships, mate");
    return 1;
  }
  msg = sprintf("%-18s %-3s %3s %-3s %3s %3s %3s %s", 
    "Ship Name", "SZ", "HP%", "WPN", "NAV", "SH", "MV", "LOC");
  who->eventPrint(TITLE_C + msg + RES);
  msg = "";
  while(wide--) {
    msg += "-";
  }
  who->eventPrint(msg);
  foreach(object ship in sort_array(ships, (:SortObByName:)) ) {
    doPrintShip(ship, who);
  }
  return 1;
}

string Resize(string str) {
  if (!stringp(str)) str = "";
  str = str[0..16];
  return str;
}
string GetWeaponString(object ship) {
  int i = ship->GetWeaponSystem();
  string dmg = " ";
  if (ship->GetDamagedSystem("weapon")) dmg = "*";
  if(i == VW_SMALL)       return dmg + "SM";
  if(i == VW_MEDIUM)      return dmg + "MD";
  if(i == VW_HUGE)        return dmg + "HU";
  if(i == VW_DEVASTATING) return dmg + "DV";
  return " XX";
}

string GetNavString(object ship) {
  int i = ship->GetSensorSuite();
  string dmg = " ";                                 
  if (ship->GetDamagedSystem("navigation")) dmg = "*"; 
  if (i == VSE_LOCAL)     return dmg +"LC";
  if (i == VSE_WIDE)      return dmg +"WD";
  return " XX";                   
}                                

string GetMastString(object ship) {
  int i = ship->GetDriveSystem();
  string dmg = " ";                                 
  if (ship->GetDamagedSystem("sails")) dmg = "*"; 
  if (i == VM_COASTAL)    return dmg + "CO";
  if (i == VM_DEEP)       return dmg + "DP";
  return " XX";
}

string GetShieldString(object ship) {
  int i = ship->GetShieldSystem();
  string dmg = " ";                                 
  if (ship->GetDamagedSystem("shield")) dmg = "*"; 
  if (i == VSH_SMALL)     return dmg + "SM";
  if (i == VSH_MEDIUM)    return dmg + "MD";
  if (i == VSH_LARGE)     return dmg + "LG";
  return " XX";
}

string GetLocation(object ship) {
  object env = environment(ship);
  string loc;
  if (!env) return "No Environment";
  if (creatorp(this_player())) return short_file(base_name(env));
  loc = env->GetTown();
  if (loc == "Wilderness") loc = env->GetDomain();
  if (loc == "Innersea") loc = "(At Sea)";
  return loc;
}

void doPrintShip(object ship, object who) {
  string msg;
  mixed hpp = ship->GetDamagePoints() * 100;
  hpp = hpp/ship->GetMaxDamagePoints();
  hpp = to_int(hpp);
  msg = sprintf("%-18s %-3s %3d %-3s %3s %3s %3s %s",
    Resize(ship->GetVehicleName() != "" ? ship->GetVehicleName() : ship->GetKeyName()),
    GetMeaningfulSize(ship->GetVehicleSize()),
    to_int(hpp),
    GetWeaponString(ship),
    GetNavString(ship),
    GetShieldString(ship),
    GetMastString(ship),
    GetLocation(ship)  
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
  if(i == VS_YACHT)       return "YT";
  if(i == VS_GALLEY)      return "GL";
  if(i == VS_CRUISER)     return "CR";
  if(i == VS_DREADNAUGHT) return "DN";
  return "??";
}

string GetHelp() {
  return "Returns a list of instantiated ships. \n"
         "Columns are: Name, Size, HealthPoint Percentage, Weapons, Navigation, Shields, Movement, Location\n"
         "Size: YT (Yacht) GL (Galley) CR (cruiser) DN (dreadnaught) \n"
         "HP % is a percentage showing status of the ship (1-100)\n"
         "Weapons: SM (small) MD (medium) HU (huge) DV (devastating)\n"
         "Navigation: LC (local/hailing) WD (wide/navigating)\n"
         "Shields: SM (small) MD (medium) LG (large)\n"
         "Movement: CO (coastal/shallows) DP (deep ocean)\n"
         "Location: The general location of your ship.\n"
         "\"XX\" in any category means the ship has no such item.\n"
         "\"*\" in any category marks that category as damaged.";
         
}

